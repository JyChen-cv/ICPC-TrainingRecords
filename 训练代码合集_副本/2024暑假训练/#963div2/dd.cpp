#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <utility>
#include <vector>

#define int long long
const int N = 5e5;
int a[N + 2], n, k, b[N + 2], d[N + 2];
bool check(int x) {
	for (int i = 1; i <= n; i++) {
		if (a[i] >= x) b[i] = 1;
		else b[i] = -1;
	}
	// for (int i = 1; i <= n; i++) std::cout << b[i] << " \n"[i == n];
	// d[1] = b[1];
	for (int i = 1; i <= n; i++) {
		if (i % k == 1 && i != 1) {
			d[i] = std::max(d[i - k], b[i]);
		}
		else {
			d[i] = d[i - 1] + b[i];
			if (i >= k) d[i] = std::max(d[i], d[i - k]);
		}
	}
	// for (int i = 1; i <= n; i++) std::cout << d[i] << " \n"[i == n];
	return d[n] > 0;
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