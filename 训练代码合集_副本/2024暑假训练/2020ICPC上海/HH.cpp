#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>

const int N = 5000;
int a[N + 2], b[N * 2 + 2], n, k;

// 不会有超过一半以上的答案
int dis(int x, int y, int duandian) {
	int dx = (x + n / 2) % n, tag;
	if (x > dx) {
		if (y <= x && y >= dx) {
			tag = 1;  // you
		} else
			tag = 0;
	} else {
		if (y <= dx && y >= x) {
			tag = 0;
		} else
			tag = 1;
	}
	int ls = std::abs(x - y);
	ls = std::min(ls, n - ls);
	if (tag)
		return -ls;
	else
		return ls;
}

void solve() {
	std::cin >> n >> k;
	for (int i = 1; i <= k; i++) {
		std::cin >> a[i];
	}
	for (int i = 1; i <= k; i++) {
		std::cin >> b[i];
	}
	std::sort(a + 1, a + k + 1);
	std::sort(b + 1, b + k + 1);
	for (int i = k + 1; i <= k * 2; i++) {
		b[i] = b[i - k];
	}

	int ans = n;
	for (int i = 0; i < k; i++) {
		int maxx = 0, minn = 0, tag = 0;
		for (int j = 1; j <= k; j++) {
			int l = i + j, ls = dis(a[j], b[l], a[i + 1]);
			std::cout << a[j] << " " << b[l] << " " << a[i + 1] << " " << ls << std::endl;
			if (ls * 2 == n || ls * 2 == -n) {
				tag = 1;
				continue;
			}
			maxx = std::max(maxx, ls);
			minn = std::min(minn, ls);
		}
		int val;
		if (tag == 1) {
			int val1 = -minn * 2 + n / 2;
			int val2 = maxx * 2 + n / 2;
			val = std::min(val1, val2);
		}
		else val = std::min(maxx, -minn) * 2 + std::max(maxx, -minn);
		ans = std::min(ans, val);
		std::cout << val << std::endl;
	}
	std::cout << ans << std::endl;
}

int main() {
	int t;
	std::cin >> t;
	while (t--) {
		solve();
	}
	return 0;
}

/*
1
14 5
0 12 13 8 9
9 2 6 13 5

*/