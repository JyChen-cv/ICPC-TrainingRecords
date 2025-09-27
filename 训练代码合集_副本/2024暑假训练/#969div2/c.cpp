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
const int N = 1e5;
int aa[N + 2], d[N + 2];
inline int gcd(int x, int y) {
	return y ? gcd(y, x % y) : x;
}
void solve() {
	int n, a, b, mx = -1e9, mi = 1e9;
	std::cin >> n >> a >> b;
	for (int i = 1; i <= n; i++) {
		std::cin >> aa[i];
	}
	std::sort(aa + 1, aa + n + 1);
	int k = gcd(a, b), ans = 0;
	// std::cout << k << std::endl;
	for (int i = 1; i <= n; i++) {
		d[i] = aa[n] - aa[i];
		d[i] %= k;
		// std::cout << d[i] << "? \n"[i == n];
		// if (d[i] > (k - 1) / 2) d[i] = d[i] - k;
		mx = std::max(mx, d[i]), mi = std::min(mi, d[i]);
	}
	ans = mx - mi;
	mx = -1e9, mi = 1e9;
	for (int i = 1; i <= n; i++) {
		int ls = d[i];
		if (d[i]) ls -= k;
		mx = std::max(mx, ls), mi = std::min(mi, ls);
	}
	ans = std::min(ans, mx - mi);
	mx = -1e9, mi = 1e9;
	for (int i = 1; i <= n; i++) {
		if (d[i] > (k - 1) / 2) d[i] = d[i] - k;
		mx = std::max(mx, d[i]), mi = std::min(mi, d[i]);
	}
	ans = std::min(ans, mx - mi);
	// if (mi < 0) ans--;
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