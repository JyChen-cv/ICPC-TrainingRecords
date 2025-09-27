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
#include <bitset>

#define int long long
typedef long long ll;
typedef double db;
typedef std::pair<int, int> PII;
inline int u(int x, int y) {
	return x % y ? x / y + 1 : x / y;
}
void solve() {
	int l, r, b, k;
	std::cin >> l >> r >> b >> k;
	if (l <= b) {
		std::cout << b*k << std::endl;
	}
	else std::cout << u(l, b)*b*k << std::endl;
}

signed main() {
	std::ios::sync_with_stdio(0);
	std::cin.tie(0), std::cout.tie(0);
	int times = 1;
	// std::cin >> times;
	while (times--) {
		solve();
	}
	return 0;
}
