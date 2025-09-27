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
	int a, b, c;
	std::cin >> a >> b >> c;
	int ans = 0, tag = 1;
	for (int i = 0; i <= 61; i++) {
		int aa = a & (1LL << i), bb = b & (1LL << i), cc = c & (1LL << i);
		// std::cout << i << ": " << aa << " " << bb << " " << cc << " " << std::endl;
		if ((aa | 0) - (bb & 0) == cc) {
			continue;
		}
		else if ((aa | (1LL << i)) - (bb & (1LL << i)) == cc) {
			ans += (1LL << i);
		}
		else {
			tag = 0;
			break;
		}
	}
	std::cout << (tag ? ans : -1) << std::endl;
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