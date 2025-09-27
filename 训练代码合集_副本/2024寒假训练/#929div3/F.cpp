#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <queue>

#define xx first
#define yy second
const int N = 1e3;
int mapp[N + 2][N + 2], dp[N + 2][N + 2];
int n, m;

bool check(int x, int y, int z)
{
	if (mapp[x][y]) return 0;
	if (y >= m) return 0;
	if (z == 2) {
		x = (x + n - 1) % n;
		if (mapp[x][y]) return 0;
	}
	return 1;
}
int main()
{
	int t;
	std::cin >> t;
	while (t--) {
		std::cin >> n >> m;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				scanf("%d", &mapp[i][j]);
				dp[i][j] = 0x3f3f3f3f;
			}
		}
		std::queue<std::pair<int, int>> q;
		q.push(std::make_pair(0, 0));
		dp[0][0] = 0;

		int tag = 0;
		while (q.size()) {
			int x = q.front().xx;
			int y = q.front().yy;
			// std::cout << x << " " << y << std::endl;
			if (y == m - 1) {
				tag = 1;
				break;
			}
			q.pop();
			int ex, ey;
			ex = (x + 1) % n, ey = y + 1;
			if (check(ex, ey, 1) && dp[ex][ey] > dp[x][y] + 1) {
				q.push(std::make_pair(ex, ey));
				dp[ex][ey] = dp[x][y] + 1;
			}
			ex = (x + 2) % n, ey = y;
			if (check(ex, ey, 2) && dp[ex][ey] > dp[x][y] + 1) {
				q.push(std::make_pair(ex, ey));
				dp[ex][ey] = dp[x][y] + 1;
			}

		}
		if (!tag) {
			std::cout << -1 << std::endl;
			continue;
		}
		int x = q.front().xx;
		int y = q.front().yy;
		int pos = (n - 1 + dp[x][y]) % n;
		// std::cout << x << " " << y << " " << pos << " " << dp[x][y] << std::endl;

		std::cout << (std::min(std::abs(pos - x), n - std::abs(pos - x)) + dp[x][y]) << std::endl;
	}
	return 0;
}