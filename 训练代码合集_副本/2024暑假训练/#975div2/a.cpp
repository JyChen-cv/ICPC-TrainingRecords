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
const int N = 100;
int a[N + 2];
void solve() {
	int n;
	std::cin >> n;
	for (int i = 1; i <= n; i++) {
		std::cin >> a[i];
	}
	int num1 = (n + 1) >> 1, mx = 0, mx2 = 0;
	for (int i = 1; i <= n; i += 2) {
		mx = std::max(mx, a[i]);
	}
	for (int i = 2; i <= n; i += 2) {
		mx2 = std::max(mx2, a[i]);
	}
	int ans = 0;
	ans = std::max(mx + num1, mx2 + (n - num1));
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