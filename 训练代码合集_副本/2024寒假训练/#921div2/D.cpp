#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <vector>
#include <algorithm>

typedef long long ll;
const ll mod = 1e9 + 7;

ll q_pow(ll x, ll y) {
	if (y == 0) return 1;
	ll mid = q_pow(x, y / 2);
	if (y % 2)
		return mid * mid % mod * x % mod;
	else
		return mid * mid % mod;
}

ll inv(ll a) {
	return q_pow(a, mod - 2);
}

ll C(ll x, ll y) {
	ll res = 1;
	for (ll i = x; i > x - y; i--) {
		res = (res * i) % mod;
	}
	ll res2 = 1;
	for (ll i = 1; i <= y; i++) {
		res2 = (res2 * i) % mod;
	}
	return res * inv(res2) % mod;
}

int main()
{
	ll t;
	std::cin >> t;
	while (t--) {
		ll n, m, d, all = 0;
		std::cin >> n >> m >> d;
		for (int i = 1; i <= m; i++) {
			ll a, b, c;
			std::cin >> a >> b >> c;
			all += c;
			all %= mod;
		}
		ll ans = m * inv(C(n, 2)) % mod;
		all = (all * d) % mod * inv(m);

		all += (d * (d - 1) % mod * inv(2) % mod) * inv(m) % mod * ans % mod;
		all %= mod;
		ans *= all;
		ans %= mod;
		std::cout << (m ? ans : 0) << std::endl;
	}
	return 0;
}