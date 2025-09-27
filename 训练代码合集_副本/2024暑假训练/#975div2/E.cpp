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
const int N = 5e5, M = 5e5;
int head[N + 2], nxt[M * 2 + 2], ver[M * 2 + 2], edge[M * 2 + 2], tot;
int cnt[N + 2], dep[N + 2], sz[N + 2], cst[N + 2];

void add(int x, int y, int z = 0) {
	tot++;
	edge[tot] = z;
	ver[tot] = y;
	nxt[tot] = head[x];
	head[x] = tot;
}
int dfs(int x, int fa) {
	cnt[dep[x]]++;
	int res = dep[x];
	int rem = 0;
	for (int i = head[x]; i; i = nxt[i]) {
		int y = ver[i];
		if (y == fa) continue;
		dep[y] = res + 1;
		int ls = dfs(y, x);

		if (dep[y] > dep[x]) {
			cst[dep[x]] += rem;
			dep[x] = dep[y];
			rem = ls;
		}
		else {
			cst[dep[y]] += ls;
		}
	}
	return rem + 1;
}
void solve() {
	int n;
	std::cin >> n;
	tot = 0;
	for (int i = 0; i <= n + 1; i++) {
		head[i] = cst[i] = cnt[i] = sz[i] = dep[i] = 0;
	}
	for (int i = 1; i < n; i++) {
		int a, b;
		std::cin >> a >> b;
		add(a, b), add(b, a);
	}
	dep[1] = 1;
	cst[dep[1]] = dfs(1, 0) - 1;
	int ans = 1e9;
	// for (int i = 1; i <= n; i++) std::cout << cst[i] << std::endl;
	for (int i = n - 1; i >= 1; i--) cnt[i] += cnt[i + 1];
	for (int i = 1; i <= n; i++) cst[i] += cst[i - 1];
	for (int i = 1; i <= n; i++) {
		ans = std::min(ans, cst[i - 1] + cnt[i + 1]);
		// std::cout << i << " " << ans << " " << cst[i - 1] << " " << cnt[i + 1] << std::endl;
	}
	std::cout << ans << std::endl;
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