// https://codeforces.com/problemset/problem/2006/B
// 考察对于这个二倍结论的理解，如果只是会背结论那就gg了
// 每一条边只与出入该子树的两个链产生贡献
// 这里暴力转移len达到了nlogn的复杂度，但是正解理论上可以到n

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

const int N = 2e5, M = 2e5;
int n, w, p[N + 2], tag[N + 2], rem[N + 2], dep[N + 2];
int head[N + 2], nxt[M * 2 + 2], ver[M * 2 + 2], edge[M * 2 + 2], tot;
int fa[N + 2][30], len[N + 2];
void add(int x, int y, int z = 0) {
	tot++;
	edge[tot] = z;
	ver[tot] = y;
	nxt[tot] = head[x];
	head[x] = tot;
}

void dfs(int x) {
	rem[x] = x;
	dep[x] = dep[fa[x][0]] + 1;
	for (int i = 1; i <= 20; i++) {
		fa[x][i] = fa[fa[x][i - 1]][i - 1];
	}
	for (int i = head[x]; i; i = nxt[i]) {
		int y = ver[i];
		if (y == fa[x][0]) continue;
		fa[y][0] = x;
		dfs(y);
		rem[x] = std::max(rem[x], rem[y]);
	}
}
int lca(int x, int y) {
	if (dep[x] < dep[y]) std::swap(x, y);
	for (int i = 20; i >= 0; i--) {
		if (dep[fa[x][i]] >= dep[y]) x = fa[x][i];
	}
	if (x == y) return x;
	for (int i = 20; i >= 0; i--) {
		if (fa[x][i] != fa[y][i]) x = fa[x][i], y = fa[y][i];
	}
	return fa[x][0];
}

void solve() {
	tot = 0;
	std::cin >> n >> w;
	for (int i = 1; i <= n; i++) head[i] = 0;
	for (int i = 2; i <= n; i++) {
		std::cin >> p[i];
		add(i, p[i]), add(p[i], i);
	}
	dfs(1);
	len[1] = dep[n] - dep[1];
	for (int i = 2; i <= n; i++) {
		int ls = lca(i, i - 1);
		len[i] = dep[i] + dep[i - 1] - dep[ls] * 2;
	}

	// for (int i = 1; i <= n; i++) {
	// 	std::cout << rem[i] << " " << len[i] << std::endl;
	// }
	int cnt = n, res = 0;
	for (int i = 1; i < n; i++) {
		int x, y;
		std::cin >> x >> y;
		int pre = x, nxt = (rem[x] == n ? 1 : (rem[x] + 1));
		// std::cout << pre << " " << nxt << std::endl;

		res += y;
		if (--len[pre] == 0) cnt--;
		if (--len[nxt] == 0) cnt--;
		int ans = cnt * (w - res) + res * 2;
		std::cout << ans << " \n"[i == n - 1];
	}
}

signed main() {
	std::ios::sync_with_stdio(0);
	std::cin.tie(0), std::cout.tie(0);
	int times = 1;
	std::cin >> times;
	while (times--) {
		solve();
	}
	return 0;
}