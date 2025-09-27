#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>

typedef long long ll;
ll q_pow(ll x, int y) {
	if (y == 0) return 1;
	else {
		ll mid = q_pow(x, y / 2);
		if (y % 2) return mid * mid * x;
		else return mid * mid;
	}
}
int main()
{
	int t ;
	std::cin >> t;
	while (t--) {
		// std::cout << t << std::endl;
		long long a, b, l;
		std::cin >> a >> b >> l;
		std::vector<ll> k;

		int ta = 0, tb = 0;
		long long ls = l;
		while (ls % a == 0) {
			ta++;
			ls /= a;
		}
		ls = l;
		while (ls % b == 0) {
			tb++;
			ls /= b;
		}
		for (int i = 0; i <= ta; i++) {
			for (int j = 0; j <= tb; j++) {
				ll ls1 = q_pow(a, i);
				ll ls2 = q_pow(b, j);
				if (l / ls1 < ls2) break;
				if (l % (ls1 * ls2) == 0) k.push_back(l / ls1 / ls2);
			}
		}
		std::sort(k.begin(), k.end());
		k.erase(unique(k.begin(), k.end()), k.end());
		std::cout << k.size() << std::endl;
		// for (int i = 0; i < (int)k.size(); i++) {
		// 	std::cout << k[i] << " ";
		// }
		// puts("");
	}
	return 0;
}