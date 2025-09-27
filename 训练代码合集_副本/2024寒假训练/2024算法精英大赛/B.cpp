#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>

typedef long long ll;
int main()
{
	ll n, m;
	std::cin >> n >> m;
	if (n == m) {
		std::cout << n << " " << m << std::endl;
	}
	else if (n > m) {
		if (n == 2 * m) {
			std::cout << m << " " << m << std::endl;
		}
		else if (n > 2 * m) {
			if (n >= 3 * m) {
				std::cout << (m * 3) << " " << m << std::endl;
			}
			else {
				std::cout << n << " " << (n - m * 2) << std::endl;
			}
		}
		else std::cout << ((n - m) * 2) << " " << 0 << std::endl;
	}
	else {
		if (m == 2 * n) {
			std::cout << n << " " << n << std::endl;
		}
		else if (m > 2 * n) {
			if (m >= 3 * n) {
				std::cout << n << " " << (n * 3) << std::endl;
			}
			else {
				std::cout << (m - n * 2) << " " << m << std::endl;
			}
		}
		else std::cout << 0 << " " << ((m - n) * 2) << std::endl;
	}
	return 0;
}