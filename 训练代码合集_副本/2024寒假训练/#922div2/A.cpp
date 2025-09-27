#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <vector>
#define int long long

signed main()
{
	int t;
	std::cin >> t;
	while (t--) {
		int n, m;
		std::cin >> n >> m;
		std::swap(n, m);
		if (n == 1) {
			std::cout << -m / 2 << std::endl;
			continue;
		}

		if (n % 2 == 1) {
			std::cout << m*((n - 3) / 2 + 1) << std::endl;
			continue;
		}
		else std::cout << m*n / 2 << std::endl;
	}
	return 0;
}