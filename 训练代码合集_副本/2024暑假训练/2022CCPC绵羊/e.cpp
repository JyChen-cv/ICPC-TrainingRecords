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
const int N = 1e5;
const int mod = 998244353;
std::vector<int> adj[N + 2], v[N + 2], hvy[N + 2];
std::multiset<int> as[N + 2];
int n, m, k;
int dp[N + 2], q[N + 2], p[N + 2];
void solve() {
	std::cin >> n >> m >> k;
	int B = 600;
	for (int i = 1; i <= n; i++) {
		adj[i].clear();
		v[i].clear();
		hvy[i].clear(), dp[i] = 0;
		as[i].clear();
	}
	for (int i = 1; i <= n; i++) std::cin >> p[i];  // 点权值
	for (int i = 1; i <= m; i++) {
		int a, b, c;
		std::cin >> a >> b >> c;
		adj[a].push_back(b), v[a].push_back(c);
		adj[b].push_back(a), v[b].push_back(c);  // 建立图
	}
	for (int i = 1; i <= k; i++) {
		std::cin >> q[i];
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j < (int)adj[i].size(); j++) {
			int y = adj[i][j];
			if (adj[y].size() >= B) {
				as[y].insert(dp[i] + v[i][j]);
				hvy[i].push_back(j);  // 存的是这个点的第几个点
			}
		}
	}
	for (int i = k; i >= 1; i--) {
		int x = q[i];
		if (adj[x].size() < B) {
			int ls = 1e17;
			for (int j = 0; j < (int)adj[x].size(); j++) {
				int y = adj[x][j];
				ls = std::min(ls, dp[y] + v[x][j]);
			}
			for (int j = 0; j < (int)hvy[x].size(); j++) {
				int ege = hvy[x][j];
				int y = adj[x][ege];
				as[y].erase(as[y].find(dp[x] + v[x][ege])), as[y].insert(ls + v[x][ege]);
			}
			dp[x] = ls;
		}
		else {
			int ls = *as[x].begin();
			for (int j = 0; j < (int)hvy[x].size(); j++) {
				int ege = hvy[x][j];
				int y = adj[x][ege];
				as[y].erase(as[y].find(dp[x] + v[x][ege])), as[y].insert(ls + v[x][ege]);
			}
			dp[x] = ls;
		}
	}
	int ans = 0;
	for (int i = 1; i <= n; i++) {
		ans += dp[i] % mod * p[i] % mod;
		ans %= mod;
	}
	std::cout << ans << std::endl;
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