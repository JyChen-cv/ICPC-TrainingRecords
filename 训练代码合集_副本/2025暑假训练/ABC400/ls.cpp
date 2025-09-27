#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <queue>
#include <utility>

const int N = 100;
const int dx[4] = {0, 0, 1, -1};
const int dy[4] = {1, -1, 0, 0};
const int inf = 2147483647;

int mapp[N + 2][N + 2], d[N + 2][N + 2], v[N + 2][N + 2];
std::queue<std::pair<int, int> >q;
int n, m;

bool check(int x, int y) {
	if (x <= 0 || x > n || y <= 0 || y > m) return 0;
	if (mapp[x][y] == -1 || v[x][y]) return 0;
	return 1;
}

int main() {
	std::cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			d[i][j] = 2147483647;
			std::cin >> mapp[i][j];
			if (mapp[i][j] == 0) {
				d[i][j] = 0, v[i][j] = 1;
				q.push(std::make_pair(i, j));
			}
			else if (mapp[i][j] == -1) {
				d[i][j] = -1;
				v[i][j] = 1;
			}
		}
	}

	while (q.size()) {
		std::pair<int, int> now = q.front();
		q.pop();

		for (int i = 0; i <= 3; i++) {
			int xx = now.first + dx[i];
			int yy = now.second + dy[i];
			if (check(xx, yy)) {
				d[xx][yy] = d[now.first][now.second] + 1;
				v[xx][yy] = 1;
				q.push(std::make_pair(xx, yy));
			}
		}
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			std::cout << d[i][j] << " ";
		}
		std::cout << "\n";
	}
	return 0;
}