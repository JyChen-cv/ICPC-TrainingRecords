#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <cstring>

const long long mod = 998244353;
typedef long long ll;
ll p[100];

ll qpow(ll x, ll y) {
	if (y == 0) return 1;
	ll mid = qpow(x, y / 2);
	if (y % 2) return mid * mid % mod * x % mod;
	else return mid * mid % mod;
}

int main() {
	p[0] = 1;
	for (int i = 1; i <= 40; i++) {
		p[i] = p[i - 1] * 2 + 1;
	}

	ll n, m;
	std::cin >> n >> m;
	m += n;
	ll fz = 1, fm = 1;
	for (int i = 0; i <= 40; i++) {
		if (p[i] <= n && p[i + 1] > n) {
			for (int j = i; j <= 40; j++) {
				if (p[j] <= m && p[j + 1] > m) {

					fz *= qpow(p[j], m - std::max(p[j], n));
					fz %= mod;
					fm *= qpow(p[j] + 1, m - std::max(p[j], n));
					fm %= mod;
					// std::cout << fz << " " << fm << std::endl;
					break;
				}
				else {

					fz *= qpow(p[j], p[j + 1] - std::max(p[j], n));
					fz %= mod;
					fm *= qpow(p[j] + 1, p[j + 1] - std::max(p[j], n));
					fm %= mod;
					// std::cout << fz << " " << fm << std::endl;
				}
			}
			break;
		}
	}

	std::cout << fz*qpow(fm, mod - 2) % mod << std::endl;
	return 0;
}