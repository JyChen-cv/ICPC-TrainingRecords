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
		long long a, res = 0, tag = 0;
		for (int i = 1; i <= n; i++) {
			std::cin >> a;
			if (a % 3 == 1) tag = 1;
			res += a;
		}
		if (res % 3 == 0) std::cout << 0 << std::endl;
		else if (res % 3 == 2 || tag) std::cout << 1 << std::endl;
		else std::cout << 2 << std::endl;
	}
	return 0;
}