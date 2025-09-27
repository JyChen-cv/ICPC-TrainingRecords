#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <vector>

const int N = 5000;
const int mod = 998244353;
int dp[N + 2][N * 2 + 5];

int main()
{
	std::ios::sync_with_stdio(0);
	std::cin.tie(0);
	int n, m;
	std::cin >> n >> m;
	int all = m * 2 + 1;
	for (int i = 1; i <= all; i++) dp[1][i] = 1;

	for (int i = 1; i < n; i++) {
		for (int j = 1; j <= all; j++) {
			if (j > m + 1) {
				dp[i + 1][all - j + 1] += dp[i][j];
				dp[i + 1][all - j + 1] %= mod;
			}
			else {
				dp[i + 1][m + 1] += dp[i][j];
				dp[i + 1][m + 1] %= mod;
				dp[i + 1][j + m + 1] -= dp[i][j];
				dp[i + 1][j + m + 1] = (dp[i + 1][j + m + 1] + mod) % mod;
			}
		}
		for (int j = 1; j <= all; j++) {
			dp[i + 1][j] += dp[i + 1][j - 1];
			dp[i + 1][j] %= mod;
			// std::cout << dp[i + 1][j] << " ";
		}
		// std::cout << std::endl;
	}
	int ans = 0;
	for (int i = 1; i <= all; i++) {
		ans += dp[n][i];
		ans %= mod;
	}
	std::cout << ans << std::endl;
	return 0;
}