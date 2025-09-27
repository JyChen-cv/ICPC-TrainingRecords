#include <algorithm>
#include <bitset>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <unordered_map>
#include <vector>

#define int long long
typedef long long ll;
typedef double db;
typedef std::pair<int, int> PII;

const int N = 100;
std::bitset < N + 2 > am[N + 2];
int n, t, ans;

bool operator<(std::bitset < N + 2 > a, std::bitset < N + 2 > b) {
	for (int i = N; i >= 0; i--) {
		if (a[i] > b[i])
			return 0;
		else if (a[i] < b[i])
			return 1;
	}
	return 0;  // 严格小于
}

// 增广矩阵am，第0列表示常数，前面1~n表示矩阵系数
void solve() {
	std::cin >> n;
	for (int i = 1; i <= n; i++) am[i] = 0;
	for (int i = 1; i <= n; i++) {
		int a;
		std::cin >> a;
		am[i][0] = a;
	}
	for (int i = 1; i <= n; i++) {
		int a;
		std::cin >> a;
		am[i] ^= a;
		am[i][i] = 1;
	}
	// for (auto i : am) {
	// 	std::cout << i << std::endl;
	// }

	int x, y;
	while (1) {
		std::cin >> x >> y;
		if (x == 0 && y == 0) break;
		am[y][x] = 1;
	}

	ans = 1;  // 后面标记0就直接gg了
	for (int i = 1; i <= n; i++) {
		for (int j = i + 1; j <= n; j++) {
			if (am[i] < am[j]) std::swap(am[i], am[j]);
		}
		if (am[i] == 0) {
			// 若消元完毕，则直接输出答案
			ans = 1 << (n - i + 1);
			break;
		} else if (am[i] == 1) {
			// 若出现0=1这样的方程，则直接宣判无解
			ans = 0;
			break;
		} else {
			// 这里第i行的最大元素作为主元，把所有其他行这一列的元素清空
			for (int k = n; k >= 1; k--) {
				if (am[i][k]) {
					for (int l = 1; l <= n; l++) {
						if (i != l && am[l][k]) am[l] ^= am[i];
					}
					break;
				}
			}
		}
	}
	if (!ans)
		puts("Oh,it's impossible~!!");
	else
		std::cout << ans << std::endl;
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
