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
	int a, b, c, d;
	std::cin >> a >> b >> c >> d;
	if (a > c) std::swap(a, c), std::swap(b, d);
	if (b < c) std::cout << 1 << std::endl;
	else {
		int ls = std::max(a, c);
		int rs = std::min(b, d);
		int ans = rs - ls;
		if (a < ls || c < ls) ans++;
		if (b > rs || d > rs) ans++;
		std::cout << ans << std::endl;
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