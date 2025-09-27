#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>
#include <cstring>

const int mod = 1e9 + 7;
typedef long long ll;
ll n, ans = 0;

ll q_pow(ll x, ll y) {
	if (y == 0) return 1;
	ll mid = q_pow(x, y / 2);
	if (y % 2) return mid * mid % mod * x % mod;
	else return mid * mid % mod;
}

ll sum (ll x) {
	return x * ((x + 1) % mod) % mod * ((2 * x % mod + 1) % mod) % mod * q_pow(6, mod - 2) % mod;
}

ll del(ll x, ll y)
{
	return ((sum(y) - sum(x - 1)) % mod + mod) % mod * (n / x) % mod;
}

int main()
{
	std::cin >> n;
	for (ll i = 1; i <= n; i++) {
		ll l = i;
		ll r = n / (n / l);
		// std::cout << l << " " << r << std::endl;
		ans += del(l, r);
		ans %= mod;
		i = r;
	}
	std::cout << ans << std::endl;
	return 0;
}