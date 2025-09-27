#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <utility>
#include <vector>

#define int long long
const int N = 1e4;
int a[N + 2], n, k, b[N + 2], d[N + 2][1000];
bool check(int x) {
	for (int i = 1; i <= n; i++) {
		if (a[i] >= x) b[i] = 1;
		else b[i] = -1;
	}
	for (int i = 0; i <= n; i++) {
		for (int j = 0; j <= k; j++) d[i][j] = -1e9;
	}
	d[0][0] = 0;
	for (int i = 1; i <= n; i++) {
		if (i % k == 0) d[i][0] = 0;
		for (int j = 1; j <= std::min(i, k); j++) {
			d[i][j] = d[i - 1][j - 1] + b[i];
			if (i >= k) d[i][j] = std::max(d[i][j], d[i - k][j]);
		}
	}
	for (int i = 1; i <= k; i++) {
		if (d[n][i] > 0) return 1;
	}
	return 0;
}
void solve() {
	std::cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		std::cin >> a[i];
	}
	// std::cout << check(9) << std::endl;
	int l = 1, r = 1e9;
	while (l < r) {
		int mid = (l + r + 1) >> 1;
		if (check(mid)) l = mid;
		else r = mid - 1;
	}
	std::cout << l << std::endl;
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