#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>

// 当思考dp问题没有思路的时候应该先思考如何用状态表示当前的问题
const int N = 100;
int mapp[N + 2];
int dp[N + 2][N + 2][N + 2];

int main()
{
	int t;
	std::cin >> t;
	while (t--) {
		int n;
		std::cin >> n;
		for (int i = 1; i <= n; i++) {
			std::cin >> mapp[i];
		}
		// for (int i = 0; i <= n; i++)
		// 	for (int j = 0; j <= n; j++)
		// 		for (int k = 0; k <= n; k++)
		// 			dp[i][j][k] = 0x3f3f3f3f;
		memset(dp, 0x3f, sizeof(dp));
		dp[1][0][0] = 0;
		for (int i = 1; i <= n; i++) {
			for (int j = 0; j < n; j++) {
				for (int k = 0; k <= n; k++) {
					if (dp[i][j][k] >= 0x3f3f3f3f) continue;
					{	// 考虑第i个块不用
						int ni = i + 1;
						int nj = j > 0 ? (j + 1) : (k == 0 ? 1 : 0); // 当向右移动一格后，如果j有值那么就相当于距离远了一格子，若没有值那么就相当于看原本这个地方有没有值，如果也有的话那就是0，不然就是1
						int nk = std::max(0, k - 1); // 向右移动了一格子后,右侧距离-1
						dp[ni][nj][nk] = std::min(dp[ni][nj][nk], dp[i][j][k]);
					}
					{	// 考虑第i个块向左
						int ni = i + 1;
						int nj = ((j + 1) <= mapp[i]) ? 0 : (j + 1);
						int nk = std::max(0, k - 1);
						dp[ni][nj][nk] = std::min(dp[ni][nj][nk], dp[i][j][k] + 1);
					}
					{	// 考虑第i个块向右
						int ni = i + 1;
						int nj = j > 0 ? (j + 1) : 0; // 因为相当于k一定有，所以不用再后续分类讨论
						int nk = std::max(mapp[i] - 1, k - 1);
						dp[ni][nj][nk] = std::min(dp[ni][nj][nk], dp[i][j][k] + 1);
					}
				}
			}
		}

		int ans = 0x3f3f3f3f;
		for (int i = 0; i <= n; i++) {
			ans = std::min(ans, dp[n + 1][0][i]);
		}
		std::cout << ans << std::endl;
	}
	return 0;
}

// 感觉这个过程用dfs写更好理解