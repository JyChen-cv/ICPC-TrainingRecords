#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>

#define int long long
const int N = 5e5;
int n, m, a[N + 2], b[N + 2];

void solve() {
	std::cin >> n >> m;
	for (int i = 1; i <= n; i++) std::cin >> a[i];
	for (int i = 1; i <= m; i++) std::cin >> b[i];
	std::sort(a + 1, a + n + 1), std::sort(b + 1, b + m + 1);

	int all = 0;
	int t1 = 1, t2 = 0, boom = 0, tag = 1;
	if (a[1] == 1) all++;
	for (int i = 1; i <= n; i++) {
		if (a[i] > 1) all++, a[i]--;
		else a[i]--;
	}
	while (t2 < m) {
		while (t1 <= n && a[t1] <= boom ) t1++, boom++;
		++t2;
		b[t2] -= boom;
		if (b[t2] > 0) {
			all -= b[t2];
			if (all < 0) {
				tag = 0;
				break;
			}
		}
		boom++;
		// std::cout << t2 << " " << t1 << " " << boom << " " << all << std::endl;
	}
	std::cout << (tag ? "YES" : "NO") << std::endl;
}

signed main() {
	std::ios::sync_with_stdio(0);
	std::cin.tie(0), std::cout.tie(0);
	int times = 1;
	std::cin >> times;
	while (times--) {
		solve();
	}
}
