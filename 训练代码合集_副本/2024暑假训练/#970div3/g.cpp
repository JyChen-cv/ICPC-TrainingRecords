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
int a[N + 2];
int gcd(int x, int y) {
	return y ? gcd(y, x % y) : x;
}
void solve() {
	int n, m;
	std::cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		std::cin >> a[i];
	}
	if (n == 1) {
		if (a[1] < m) std::cout << m << std::endl;
		else std::cout << m - 1 << std::endl;
		return ;
	}
	int res = a[1];
	// std::cout << res << std::endl;
	for (int i = 2; i <= n; i++) {
		res = gcd(res, a[i]);
	}
	if (res == 1) {
		std::cout << m + n - 1 << std::endl;
		return ;
	}
	int d = res - 1;
	// for (int i=0;i<n;i++) {

	// }
	int k = std::min(n, m / d), l = m - k * d;
	// std::cout << k << " " << l << std::endl;
	int ans = k * res - 1 + l;
	if (k < n && l) ans++;
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