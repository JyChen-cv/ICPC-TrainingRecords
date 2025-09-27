#include <iostream>
#include <cstdio>
#include <queue>
#include <cstring>
#include <vector>
#include <algorithm>
#include <cmath>

#define int long long
const int N = 5000;
const int mod = 998244353;
int dp[N + 2][N + 2], ans[N + 2][N + 2];
signed main() {
	int n, k;
	std::cin >> n >> k;
	// dp[i][j]表示的是将i个块切分成j组，且没有长度为2的组的方案数量
	// ans[i][j]表示的是将i个块切分成j组，且只有第一组和最后一组的长度允许为2的方案数量
	dp[0][0] = 1;
	for (int i = 1; i <= n; i++) {
		std::cout << i << ":\n";
		for (int j = 1; j <= std::min(i, n); j++) {
			for (int t = 0; t < i; t++) {
				if (t == 2 && j == 2) continue;  // 这代表一定从dp[2][1]这里转移
				if (i - t == 2) continue;  // 这代表最后一组一定是长度为2
				dp[i][j] += dp[t][j - 1];
				dp[i][j] %= mod;
			}
			ans[i][j] = dp[i][j];
			if (i >= 2) ans[i][j] += 2 * dp[i - 2][j - 1];
			ans[i][j] %= mod;
			if (i >= 4 && j >= 2) ans[i][j] += dp[i - 4][j - 2];
			ans[i][j] %= mod;
		}
		// for (int j = 1; j <= std::min(i, n); j++)
		// 	std::cout << dp[i][j] << " \n"[j == std::min(i, n)];
		for (int j = 1; j <= std::min(i, n); j++)
			std::cout << ans[i][j] << " \n"[j == std::min(i, n)];
	}
	int anss = 0;
	for (int i = k; i <= n; i++) {
		anss += ans[n][i];
		anss %= mod;
	}
	std::cout << anss << std::endl;
	return 0;
}