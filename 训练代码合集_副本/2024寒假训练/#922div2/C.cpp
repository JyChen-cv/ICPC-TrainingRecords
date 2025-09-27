#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <vector>

long long pw[70];

int main()
{
	pw[0] = 1;
	for (int i = 1; i <= 62; i++) pw[i] = pw[i - 1] * 2;
	int t;
	std::cin >> t;
	while (t--) {
		long long n, m, k, res = 0, tag = 1;
		std::cin >> n >> m >> k;
		if (n < m) std::swap(n, m);
		for (int i = 62; i >= 0; i--) {
			long long x = n & pw[i];
			long long y = m & pw[i];
			if (x != y) {
				if (tag) {
					tag = 0;
					continue;
				}
				if (y > x) continue;
				if (k < pw[i]) continue;
				res += pw[i];
				k -= pw[i];
			}
		}
		// std::cout << res << std::endl;
		std::cout << std::abs((n ^ res) - (m ^ res)) << std::endl;
	}
	return 0;
}