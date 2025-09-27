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
const int N = 3e5;
int a[N + 2], b[N + 2];
void solve() {
	int n, m;
	std::cin >> n >> m;
	for (int i = 1; i <= n; i++) std::cin >> a[i], a[i] += a[i - 1];
	for (int i = 1; i <= m; i++) std::cin >> b[i];

	// dp[i][j] 表示前i个被cover且现在b处于第j位置是的最小花费
	std::vector<std::vector<int> > dp(n + 2, std::vector<int>(m + 2));
	for (auto &i : dp) {
		for (auto &j : i) j = 1e9;
	}
	for (int j = 0; j <= m; j++) dp[0][j] = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			dp[i][j] = std::min(dp[i][j - 1], dp[i][j]);
			auto pos = std::lower_bound(a, a + n + 1, a[i] - b[j]) - a;
			if (pos < i) dp[i][j] = std::min(dp[pos][j] + (m - j), dp[i][j]);
		}
	}
	int ans = 1e9;
	for (int i = 1; i <= m; i++) {
		ans = std::min(ans, dp[n][i]);
	}
	std::cout << (ans == 1e9 ? -1 : ans) << std::endl;
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