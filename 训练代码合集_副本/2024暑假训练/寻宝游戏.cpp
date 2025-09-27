#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <vector>
#include <queue>
#include <map>
#include <unordered_map>
#include <cstring>
#include <set>

#define int long long
typedef long long ll;
typedef double db;
typedef std::pair<int, int> PII;
const int N = 1e5, M = 1e5;
int head[N + 2], nxt[M * 2 + 2], ver[M * 2 + 2], edge[M * 2 + 2], tot;
int n, m, dfn[N + 2], total, ans, mp[N + 2];
int dep[N + 2], d[N + 2], f[N + 2][25];
std::set<int> q;

void add(int x, int y, int z = 0) {
	tot++;
	edge[tot] = z;
	ver[tot] = y;
	nxt[tot] = head[x];
	head[x] = tot;
}
void dfs(int x, int fa) {
	dfn[x] = ++total;
	dep[x] = dep[fa] + 1;
	f[x][0] = fa;
	for (int i = 1; i <= 20; i++) f[x][i] = f[f[x][i - 1]][i - 1];
	for (int i = head[x]; i; i = nxt[i]) {
		int y = ver[i], z = edge[i];
		if (y == fa) continue;
		d[y] = d[x] + z;
		dfs(y, x);
	}
}

int lca(int x, int y) {
	if (dep[x] < dep[y]) std::swap(x, y);
	for (int i = 20; i >= 0; i--) {
		if (dep[f[x][i]] >= dep[y]) x = f[x][i];
	}
	if (x == y) return x;
	for (int i = 20; i >= 0; i--) {
		if (f[x][i] != f[y][i]) x = f[x][i], y = f[y][i];
	}
	return f[x][0];
}
inline int dis(int x, int y) {
	int res = lca(x, y);
	return d[x] + d[y] - 2 * d[res];
}

inline std::set<int>::iterator back(std::set<int> &v) {
	if (!v.size()) { exit(99);} // 标记错误代码
	auto x = v.end(); x--;
	return x;
}
inline std::set<int>::iterator s_pre(std::set<int>::iterator x, std::set<int> &v) {
	if (!v.size()) { exit(99);} // 标记错误代码
	if (x == v.begin()) return back(v);
	else {x--; return x;}
}

void solve() {
	// freopen("okok.in", "r", stdin);
	std::cin >> n >> m;
	for (int i = 1; i < n; i++) {
		int a, b, c;
		std::cin >> a >> b >> c;
		add(a, b, c), add(b, a, c);
	}
	dfs(1, 0);
	for (int i = 1; i <= n; i++) {
		mp[dfn[i]] = i;
	}
	for (int i = 1; i <= m; i++) {
		int x;
		std::cin >> x;
		if (q.find(dfn[x]) == q.end()) {
			if (!q.size()) q.insert(dfn[x]);
			else {
				auto nn = q.lower_bound(dfn[x]);
				auto pp = s_pre(nn, q); nn = (nn == q.end() ? q.begin() : nn);
				// std::cout << mp[*pp] << " " << x << " " << mp[*nn] << std::endl;
				// std::cout << ans << std::endl;
				ans -= dis(mp[*pp], mp[*nn]);
				// std::cout << ans << " " << dis(mp[*pp], x) << " " << dis(x, mp[*nn]) << " " << std::endl;
				ans += dis(mp[*pp], x) + dis(x, mp[*nn]);
				// std::cout << ans << std::endl;
				q.insert(dfn[x]);
			}
			std::cout << ans << std::endl;
		}
		else {
			q.erase(dfn[x]);  // 对于非multiset来讲直接删除就行
			if (!q.size()) continue;

			auto nn = q.lower_bound(dfn[x]);
			auto pp = s_pre(nn, q); nn = (nn == q.end() ? q.begin() : nn);
			// std::cout << *pp << " " << *nn << std::endl;
			// std::cout << ans << std::endl;
			ans += dis(mp[*pp], mp[*nn]);
			// std::cout << ans << std::endl;
			ans -= dis(mp[*pp], x) + dis(x, mp[*nn]);
			// std::cout << ans << std::endl;
			std::cout << ans << std::endl;
		}

	}
}

signed main() {
	std::ios::sync_with_stdio(0);
	std::cin.tie(0), std::cout.tie(0);
	int times = 1;
	// std::cin >> times;
	while (times--) {
		solve();
	}
	return 0;
}