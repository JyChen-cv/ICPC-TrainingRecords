#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstring>

#define int long long
typedef long long ll;
const int N = 2e5;
ll mapp[N + 2];
int n, k, b;

ll C(int x) {
	return x * (x - 1) / 2;
}

ll check(int x) {
	ll res = 0;
	for (int i = 1; i <= n; i++) {
		res += C(mapp[i]);
		if (mapp[i] > x) {
			int ls = mapp[i] % x;
			ll lss = mapp[i] / x;
			res -= C(lss + 1) * ls;
			res -= C(lss) * (x - ls);
		}
	}
	return res * b - (x - 1) * k;
}

signed main()
{
	int t;
	std::cin >> t;
	while (t--) {
		std::cin >> n >> b >> k;
		for (int i = 1; i <= n; i++) {
			std::cin >> mapp[i];
		}

		int l = 1, r = 2e6;
		while (l < r) {
			// std::cout << l << " " << r << std::endl;
			int ml = (l * 2 + r) / 3;
			int mr = (l + r * 2) / 3;
			if (check(ml) < check(mr)) {
				l = ml + 1;
			}
			else r = mr;
		}
		std::cout << check(l) << std::endl;
	}
	return 0;
}