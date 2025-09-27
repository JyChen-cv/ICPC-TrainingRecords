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
const int N = 400, M = 2e5;
int d[N + 2][N + 2];
struct group {
	int l, r, t;
} r[M * 2 + 2];
int v[10], ans, q[10];
std::vector<int> rem;
int n, m;
void dfs(int x, int all) {
	if (x > all) {
		int res = 0;
		// for (auto i : rem) {
		// 	std::cout << i << " ";
		// }
		// std::cout << std::endl;
		if (r[rem[0]].l != 1) res += d[1][r[rem[0]].l];
		// std::cout << res << " " << all << std::endl;
		for (int i = 1; i < all; i++) {
			// std::cout << r[rem[i - 1]].r << " " << r[rem[i]].l << std::endl;
			res += d[r[rem[i - 1]].r][r[rem[i]].l];
		}
		// std::cout << res << " " << all << std::endl;
		if (r[rem[all - 1]].r != n) res += d[r[rem[all - 1]].r][n];
		// std::cout << res << " " << all << std::endl;
		ans = std::min(ans, res);
		return ;
	}
	for (int i = 1; i <= all; i++) {
		if (v[i] == 0) {
			v[i] = 1;
			rem.push_back(q[i]);
			dfs(x + 1, all);
			rem.pop_back();
			rem.push_back(q[i] + m);
			dfs(x + 1, all);
			rem.pop_back();
			v[i] = 0;
		}
	}
}
void solve() {
	std::cin >> n >> m;
	memset(d, 0x3f, sizeof d);
	for (int i = 1; i <= m; i++) {
		int a, b, c;
		std::cin >> a >> b >> c;
		d[a][b] = std::min(d[a][b], c);
		d[b][a] = std::min(d[b][a], c);
		r[i] = {a, b, c};
		r[i + m] = {b, a, c};
	}
	for (int i = 1; i <= n; i++) d[i][i] = 0;
	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				d[i][j] = std::min(d[i][j], d[i][k] + d[k][j]);
			}
		}
	}
	int t;
	std::cin >> t;
	for (int i = 1; i <= t; i++) {
		int k;
		std::cin >> k;
		for (int j = 1; j <= k; j++) {
			std::cin >> q[j];
		}
		ans = 1e15;
		dfs(1, k);
		for (int j = 1; j <= k; j++) {
			ans += r[q[j]].t;
		}
		std::cout << ans << std::endl;
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