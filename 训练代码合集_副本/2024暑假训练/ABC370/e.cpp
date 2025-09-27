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
const int N = 2e5, mod = 998244353;
int a[N + 2], s[N + 2];
std::map<int, int> q;
void solve() {
	int n, m;
	std::cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		std::cin >> a[i];
		s[i] = s[i - 1] + a[i];
	}
	q[0] = 1;
	int sum = 1, res = 0;
	for (int i = 1; i <= n; i++) {
		res = (sum - q[s[i] - m] + mod) % mod;
		(sum += res) %= mod;
		// std::cout << res << " " << sum << " " << s[i] << " " << std::endl;
		(q[s[i]] += res) %= mod;
	}
	// if (m == 0) q[0] = 0;
	std::cout << res << std::endl;
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