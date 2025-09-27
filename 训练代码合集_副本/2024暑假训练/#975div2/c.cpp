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
const int N = 2e5;
int a[N + 2];
void solve() {
	int n, k, mx = 0, tot = 0;
	std::cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		std::cin >> a[i];
		tot += a[i];
		mx = std::max(mx, a[i]);
	}

	for (int i = mx; i <= tot + k; i++) {
		int y = (tot + k) / i;
		y = std::min(y, n);
		int res = y * i;
		// std::cout << y << " " << res << std::endl;
		if (res >= tot) {
			std::cout << y << std::endl;
			break;
		}

		if (y < i) {
			for (int j = std::min(y, n); j >= 1; j--) {
				res = (tot + k) / j * j;
				if (res >= tot) {
					std::cout << j << std::endl;
					break;
				}
			}
			break;
		}
	}
	// int st = (tot + k) / mx;
	// for (int i = st; i >= 1; i--) {

	// }
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