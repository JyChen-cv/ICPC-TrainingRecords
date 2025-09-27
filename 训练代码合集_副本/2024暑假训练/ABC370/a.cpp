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
	int l, r;
	std::cin >> l >> r;
	if (l && !r) {
		puts("Yes");
	}
	else if (!l && r) {
		puts("No");
	}
	else if (l && r) {
		puts("Invalid");
	}
	else {
		puts("Invalid");
	}
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