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
int pos[N + 2], val[N + 2];
void solve() {
	int n, m;
	std::cin >> n;
	for (int i = 1; i <= n; i++) {
		std::cin >> pos[i];
	}
	for (int i = 1; i <= n; i++) {
		std::cin >> val[i];
		val[i] += val[i - 1];
	}
	std::cin >> m;
	for (int i = 1; i <= m; i++) {
		int l, r;
		std::cin >> l >> r;
		int pl = std::lower_bound(pos + 1, pos + n + 1, l) - pos;
		int pr = std::upper_bound(pos + 1, pos + n + 1, r) - pos;
		// std::cout << l << " " << r << " " << pl << " " << pr << std::endl;
		int ans = val[pr - 1];
		ans -= val[pl - 1];
		std::cout << ans << std::endl;
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