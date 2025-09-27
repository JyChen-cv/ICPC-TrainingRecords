#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>

const int N = 200, M = 1e5;
struct node {
	int x, y;
} mapp[N + 2];
int sz[N + 2];
int yu[N + 2][N + 2][N + 2];
int dp[M + 2][N + 2];
int main()
{
	std::ios::sync_with_stdio(0);
	std::cin.tie(0);
	std::cout.tie(0);
	int n, m;
	std::cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		std::cin >> mapp[i].x >> mapp[i].y;
		// std::cout << mapp[i].x << " " << mapp[i].y << std::endl;
	}
	int mx = 0;
	for (int i = 1; i <= m; i++ ) {
		std::cin >> sz[i];
		mx = std::max(mx, sz[i]);
	}

	for (int i = 1; i <= n; i++)
		for (int j = mapp[i].x; j <= mx; j++) {
			yu[i][i][j] = mapp[i].y;
		}
	for (int len = 2; len <= n; len++) {
		for (int l = 1; l + len - 1 <= n; l++) {
			int r = l + len - 1;
			for (int k = 1; k <= mx; k++) {
				yu[l][r][k] = yu[l][r][k - 1];
				if (k >= mapp[r].x) yu[l][r][k] = std::max(yu[l][r - 1][k - mapp[r].x] + mapp[r].y, yu[l][r][k]);
				if (k >= mapp[l].x) yu[l][r][k] = std::max(yu[l + 1][r][k - mapp[l].x] + mapp[l].y, yu[l][r][k]);
				// if (l == 4) std:: cout << "!!" << k << ' ' << mapp[l].x << yu[l][r - 1][k - mapp[r].x] << " " << mapp[r].y << std::endl;
				// std::cout << l << " " << r << " " << k << " " << yu[l][r][k] << std::endl;
			}
		}
	}

	int st = std::max(1, m - n + 1);
	for (int i = st; i <= m; i++) {
		for (int j = 1; j <= n; j++) {
			dp[i][j] = std::max(dp[i - 1][j - sz[i]] + yu[j - sz[i]])
		}
	}
	return 0;
}