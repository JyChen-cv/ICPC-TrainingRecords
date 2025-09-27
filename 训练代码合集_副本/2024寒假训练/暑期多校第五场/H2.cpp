#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>

const int N = 200;
struct node {
	int x, y;
} mapp[N + 2];
int sz[N + 2], dp[N + 2][N + 2][N + 2]; // 考虑第i次拿，拿到了第j个物品，当前背包的体积考虑为k
int main()
{
	int n, m;
	std::cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		std::cin >> mapp[i].x >> mapp[i].y;
	}
	for (int i = 1; i <= m; i++) {
		std::cin >> sz[i];
	}
	if (m > n) {
		for (int i = 1; i <= n; i++) {
			sz[i] = sz[m - n + i];
		}
		m = n;
	}

	for (int i = 1; i <= m; i++) {
		for (int j = 1; j <= n; j++) {
			for (int k = 0; k <= sz[i - 1]; k++) {
				dp[i][j][0] = std::max(dp[i][j][0], dp[i - 1][j][k]);
			}
			// std::cout << i << " " << j << " " << dp[i][j][0] << std::endl;
			for (int k = 1; k <= sz[i]; k++) {
				dp[i][j][k] = dp[i][j][k - 1];
				if (k >= mapp[j].x) dp[i][j][k] = std::max(dp[i][j][k], dp[i][j - 1][k - mapp[j].x] + mapp[j].y);
				dp[i][j][k] = std::max(dp[i][j][k], dp[i][j - 1][k]);
				// std::cout << i << " " << j << " " << k << " " << dp[i][j][k] << std::endl;
			}
		}
	}
	std::cout << dp[m][n][sz[m]] << std::endl;
	return 0;
}