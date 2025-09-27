#include <algorithm>
#include <cmath>
#include <iostream>

#define int long long
const int N = 1e5;
int mapp[N + 2];
void solve() {
	int n;
	std::cin >> n;
	for (int i = 1; i <= n; i++) std::cin >> mapp[i];
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
