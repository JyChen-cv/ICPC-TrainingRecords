#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <map>
#include <vector>

#define int long long

const int mod = 998244353;
const int N = 1e7;
int tag[N + 2], inv[N + 2];
std::map<int, int> num;

inline int q_pow(int x, int y) {
	if (!y) return 1;
	int mid = q_pow(x, y / 2);
	if (y % 2)
		return mid * mid % mod * x % mod;
	else
		return mid * mid % mod;
}

void solve() {
	int n, lcm = 1;
	std::vector<int> pri;
	std::cin >> n;
	for (int i = 2; i <= n; i++) {
		if (tag[i] == 0) {
			pri.push_back(i);
			tag[i] = i;
		}
		for (auto j : pri) {
			if (j > tag[i] || i * j > n) break;
			tag[j * i] = j;
		}
	}
	inv[1] = 1;
	for (int i = 2; i <= n; i++) {
		inv[i] = (mod - mod / i) * inv[mod % i] % mod;
	}
	for (auto i : pri) {
		int p = (double)std::log(n) / std::log(i);
		lcm *= q_pow(i, p), lcm %= mod;
	}
	// std::cout << "lcm: " << lcm << std::endl;

	int ans = 0, res = 0;
	for (int i = n - 1; i >= 1; i--) {
		int cnt = n - i;
		res = (res + lcm * inv[i + 1] % mod) % mod;
		// std::cout << i << " " << cnt << " " << res << " "<< (lcm * inv[i + 1]
		// % mod) << std::endl;
		ans = (ans + lcm * inv[i] % mod * cnt % mod - res + mod) % mod;
	}
	std::cout << ans << std::endl;
}

signed main() {
	std::ios::sync_with_stdio(0);
	std::cin.tie(0), std::cout.tie(0);
	int times = 1;
	// std::cin>>times;
	while (times--) {
		solve();
	}

	return 0;
}
