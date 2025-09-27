#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>

const int N = 1e5;
#define int long long
signed main()
{
	int t;
	std::cin >> t;
	while (t--) {
		int n, a, b;
		std::cin >> n >> a >> b;
		int ls = std::min(n, b);
		int ans = 0;
		if (a >= b) std::cout << a*n << std::endl;
		else if (b >= a + n - 1) {
			std::cout << n*(b * 2 - n + 1) / 2 << std::endl;
		}
		else {
			std::cout << (b + a)*(b - a + 1) / 2 + a*(n - (b - a + 1)) << std::endl;
		}
	}
	return 0;
}