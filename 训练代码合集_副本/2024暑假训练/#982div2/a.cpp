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
	int n, lmax = 0, rmax = 0;
	std::cin >> n;
	for (int i = 1; i <= n; i++) {
		int a, b;
		std::cin >> a >> b;
		lmax = std::max(lmax, a), rmax = std::max(rmax, b);
	}
	std::cout << (lmax + rmax) * 2 << std::endl;
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