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
void solve() {
	int a, b;
	std::cin >> a >> b;
	int len = b - a + 1;
	int l = 1, r = len;
	while (l < r) {
		int mid = (l + r + 1) >> 1;
		// std::cout << l << " " << mid << " " << r << std::endl;
		if (mid * (mid - 1) / 2 + 1 <= len) l = mid;
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