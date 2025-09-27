#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>

int main()
{
	int t;
	std::cin >> t;
	while (t--) {
		int n;
		std::cin >> n;
		long long res = 0, a, mi = 1e18;
		for (int i = 1; i <= n; i++) {
			std::cin >> a;
			res += std::abs(a);
			mi = std::min(mi, a);
		}
		std::cout << res << std::endl;
		// else std::cout << (res - mi) << std::endl;
	}
	return 0;
}