#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>

#define int long long

int v[5];
void solve() {
	int n;
	std::string a;
	std::cin >> n >> a;
	for (int i = 1; i <= 4; i++) v[i] = 0;
	for (auto i : a) {
		if (i == '?') continue;
		else v[i - 'A' + 1]++;
	}
	int ans = 0;
	for (int i = 1; i <= 4; i++) {
		ans += std::min(v[i], n);
	}
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