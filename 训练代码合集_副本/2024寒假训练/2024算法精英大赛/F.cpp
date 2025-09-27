#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <queue>

const int N = 1000;
char mapp[N + 2][N + 2];
int sum[N + 2][N + 2];
int dp[N + 2][N + 2][22], n, m;

struct group {
	int x, y, dx;
};

bool check(int x1, int y1, int x2, int y2)
{
	// 传入左上角和右下角即可
	if (x1 > n || y1 > m || x1 <= 0 || y1 <= 0 || x2 > n || y2 > m || x2 <= 0 || y2 <= 0) return 0;
	int res = sum[x2][y2] - sum[x1 - 1][y2] - sum[x2][y1 - 1] + sum[x1 - 1][y1 - 1];
	return res == 0;
}

bool check2(int nx, int ny, int nb)
{
	// 传入左上角和大小
	return check(nx, ny, nx + nb - 1, ny + nb - 1);
}

int main()
{
	std::cin >> n >> m;
	int sx, sy, ex, ey;
	std::cin >> sx >> sy >> ex >> ey;
	for (int i = 1; i <= n; i++) {
		scanf("%s", mapp[i] + 1);
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (mapp[i][j] == '#') sum[i][j] = 1;
			sum[i][j] += sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1];
		}
	}
	// for (int i = 1; i <= n; i++) {
	// 	for (int j = 1; j <= m; j++) {
	// 		std::cout << sum[i][j] << " ";
	// 	}
	// 	puts("");
	// }

	std::queue<group> q;
	memset(dp, 0x3f, sizeof(dp));
	q.push((group) {sx, sy, 1});
	dp[sx][sy][1] = 0;

	while (q.size()) {
		int nx = q.front().x;
		int ny = q.front().y;
		int nb = q.front().dx;
		// std::cout << nx << " " << ny << " " << nb << std::endl;
		if (nx == ex && ny == ey && nb == 1) {
			std::cout << dp[ex][ey][1] << std::endl;
			break;
		}

		q.pop();
		// if (nx>n || ny>m || nx<=0 || ny<=0 || nb>20 || nb<=0) continue;
		if (dp[nx][ny][nb + 1] > dp[nx][ny][nb] + 1 && check2(nx, ny, nb + 1)) { // check能不能变大
			dp[nx][ny][nb + 1] = dp[nx][ny][nb] + 1;
			q.push((group) {nx, ny, nb + 1});
		}
		if (dp[nx][ny][nb - 1] > dp[nx][ny][nb] + 1 && nb != 1) {
			dp[nx][ny][nb - 1] = dp[nx][ny][nb] + 1;
			q.push((group) {nx, ny, nb - 1});
		}

		if (dp[nx][ny - nb][nb] > dp[nx][ny][nb] + 1 && check2(nx, ny - nb, nb)) { // 判断目的地是否合法，向上
			dp[nx][ny - nb][nb] = dp[nx][ny][nb] + 1;
			q.push((group) {nx, ny - nb, nb});
		}
		if (dp[nx][ny + nb][nb] > dp[nx][ny][nb] + 1 && check2(nx, ny + nb, nb)) { // 向下走
			dp[nx][ny + nb][nb] = dp[nx][ny][nb] + 1;
			q.push((group) {nx, ny + nb, nb});
		}
		if (dp[nx - nb][ny][nb] > dp[nx][ny][nb] + 1 && check2(nx - nb, ny, nb)) { // 判断目的地是否合法，向左
			dp[nx - nb][ny][nb] = dp[nx][ny][nb] + 1;
			q.push((group) {nx - nb, ny, nb});
		}
		if (dp[nx + nb][ny][nb] > dp[nx][ny][nb] + 1 && check2(nx + nb, ny, nb)) { // 向右走
			dp[nx + nb][ny][nb] = dp[nx][ny][nb] + 1;
			q.push((group) {nx + nb, ny, nb});
		}
	}

	return 0;
}