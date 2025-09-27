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
	int d = r - l + 1;
	int ji = d / 2, ou = d / 2;
	if (l % 2 && d % 2) ji++;
	else if (l % 2 == 0 && d % 2) ou++;
	// std::cout << ji << " " << ou << std::endl;
	int ans = ji / 2;
	// if (ou - ans >= 3 && l <= 2) ans++;
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