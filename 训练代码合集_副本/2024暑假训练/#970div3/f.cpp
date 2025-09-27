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
const int mod = 1e9 + 7; // 记得开 long long
int q_pow(int x, int y) {
	if (!y) return 1;
	int mid = q_pow(x, y / 2);
	if (y % 2) return mid * mid % mod * x % mod;
	else return mid * mid % mod;
}
const int N = 2e5;
int a[N + 5], s[N + 5];
void solve() {
	int n;
	std::cin >> n;
	for (int i = 1; i <= n; i++) {
		std::cin >> a[i];
	}
	s[n + 1] = 0;
	for (int j = n; j >= 1; j--) {
		s[j] = s[j + 1] + a[j];
		s[j] %= mod;
	}
	// std::cout << 1 << std::endl;
	int ans = 0;
	// std::cout << ans << std::endl;
	for (int i = 1; i <= n; i++) {
		ans += a[i] * s[i + 1] % mod;
		ans %= mod;
	}
	int t = n * (n - 1) / 2;
	t %= mod;
	ans = (ans * q_pow(t, mod - 2)) % mod;
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