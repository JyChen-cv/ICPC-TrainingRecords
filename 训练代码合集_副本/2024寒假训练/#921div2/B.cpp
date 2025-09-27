#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <vector>
#include <algorithm>

int main()
{
	int t;
	std::cin >> t;
	while (t--) {
		long long n, x, ans = 0;
		std::cin >> x >> n;
		for (long long i = 1; i <= x / n && i * i <= x; i++) {
			if (x % i) continue;
			long long l = i, r = x / i;
			ans = std::max(ans, l);
			if (l >= n) ans = std::max(ans, r);
		}
		std::cout << ans << std::endl;
	}
	return 0;
}