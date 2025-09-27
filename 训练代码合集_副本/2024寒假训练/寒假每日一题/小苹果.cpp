#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <cstring>

int main()
{
	int n;
	std::cin >> n;
	int all = 0, ans = 0;
	while (n) {
		all++;
		if (n % 3 == 1 && !ans) ans = all;
		n -= n / 3 + (n % 3 ? 1 : 0);
		// std::cout << n << " ";
	}
	std::cout << all << " " << ans << std::endl;
	return 0;
}