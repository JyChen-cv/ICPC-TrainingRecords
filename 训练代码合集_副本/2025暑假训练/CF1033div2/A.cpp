#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iostream>

void solve() {
	int l[3], b[3];
	int tl = 1, tb = 1, sl = 0, sb = 0;
	for (int i = 0; i < 3; i++) {
		std::cin >> l[i] >> b[i];
		sl += l[i], sb += b[i];
		if (i && l[i] != l[i - 1]) tl = 0;
		if (i && b[i] != b[i - 1]) tb = 0;
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
