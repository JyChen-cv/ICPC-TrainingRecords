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
#include <bitset>

#define int long long
typedef long long ll;
typedef double db;
typedef std::pair<int, int> PII;

const int N = 1000;
int mapp[N + 2][N + 2], n, m;

void pt(int x) {
	if (x) {
		// 颠倒
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {
				std::cout << mapp[j][i];
			}
			std::cout << std::endl;
		}
	}
	else {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				std::cout << mapp[i][j];
			}
			std::cout << std::endl;
		}
	}
}

bool check(int x, int y) {

}
void solve() {
	std::cin >> n >> m;
	if (n % 2 && m % 2) {
		std::cout << "NO" << std::endl;
		return ;
	}
	std::cout << "YES" << std::endl;
	int turn = 0;
	if (n % 2 == 0 && m % 2 == 0) {
		if (n > m) std::swap(n, m), turn = 1;
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= m; j++) {
				if (check(i, j)) mapp[i][j] = 1;
			}
		}
		pt(turn);
	}
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