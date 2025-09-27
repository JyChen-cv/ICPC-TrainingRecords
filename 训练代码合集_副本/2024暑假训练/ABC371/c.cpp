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
const int N = 10;
std::vector<int> g1[N + 2], g2[N + 2];
int n, g, h;
int v[N + 2], to[N + 2], ans = 1e9;
int cst[N + 2][N + 2];
void dfs(int x) {
	if (x == n + 1) {
		// for (int i = 1; i <= n; i++) {
		// 	std::cout << to[i] << " \n"[i == n];
		// }
		int res[N + 2], cnt = 0;
		for (int i = 1; i <= n; i++) {
			memset(res, 0, sizeof res);
			for (int j = 0; j < (int)g2[i].size(); j++) {
				res[g2[i][j]]++;
			}
			int y = to[i];
			for (int j = 0; j < (int)g1[y].size(); j++) {
				res[g1[y][j]]--;
			}
			for (int j = 1; j <= n; j++) {
				if (res[j]) {
					cnt += cst[i][j];
				}
			}
		}
		ans = std::min(ans, cnt / 2);
		return;
	}
	for (int i = 1; i <= n; i++) {
		if (v[i]) continue;
		v[i] = 1;
		to[x] = i;
		dfs(x + 1);
		v[i] = 0;
	}
}
void solve() {
	std::cin >> n >> g;
	for (int i = 1; i <= g; i++) {
		int a, b;
		std::cin >> a >> b;
		g1[a].push_back(b);
	}
	std::cin >> h;
	for (int i = 1; i <= h; i++) {
		int a, b;
		std::cin >> a >> b;
		g2[a].push_back(b);
	}
	for (int i = 1; i <= n; i++) {
		for (int j = i + 1; j <= n; j++) {
			std::cin >> cst[i][j];
			cst[j][i] = cst[i][j];
		}
	}
	dfs(1);
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