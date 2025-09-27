#include <iostream>

const int N = 10;
int mapp[N + 2][N + 2];
void solve() {
	int k, n, m;
	std::cin >> k >> n >> m;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			std::cin >> mapp[i][j];
		}
	}
}

int main() {
	std::ios::sync_with_stdio(0);
	std::cin.tie(0), std::cout.tie(0);
	int times = 1;
	std::cin >> times;
	while (times--) {
		solve();
	}
	return 0;
}
