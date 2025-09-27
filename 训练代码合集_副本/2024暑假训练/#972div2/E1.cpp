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
const int N = 300;
int a[N + 2], b[N + 2][N + 2], f[N + 2][N + 2][N + 2];
int len, n, m;

void solve() {
	std::cin >> len >> n >> m;
	for (int k = 1; k <= len + 1; k++) {
		for (int i = 1; i <= n + 1; i++) {
			for (int j = 1; j <= m + 1; j++) {
				f[i][j][k] = 0;
			}
		}
	}
	for (int i = 1; i <= len; i++) {
		std::cin >> a[i];
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			std::cin >> b[i][j];
		}
	}
	// f[i][j][k] 表示 在(i,j)位置 拿元素k是否存在必胜的方案
	for (int k = len; k >= 1; k--) {
		for (int i = n; i >= 1; i--) {
			for (int j = m; j >= 1; j--) {
				if (b[i][j] == a[k] && f[i + 1][j + 1][k + 1] == 0) {
					f[i][j][k] = 1;
				}
			}
		}
		for (int i = n; i >= 1; i--) {
			for (int j = m; j >= 1; j--) {
				f[i][j][k] += f[i + 1][j][k] + f[i][j + 1][k] - f[i + 1][j + 1][k];
			}
		}

		// std::cout << k << ": \n";
		// for (int i = 1; i <= n; i++) {
		// 	for (int j = 1; j <= m; j++) {
		// 		std::cout << f[i][j][k] << " ";
		// 	}
		// 	std::cout << std::endl;
		// }
	}
	if (f[1][1][1] == 0) puts("N");
	else puts("T");
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