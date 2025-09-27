#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>

const int N = 2e5;
int mapp[N + 2];

int main()
{
	int t;
	std::cin >> t;
	while (t--) {
		int n, m, k, tag = 0;
		std::cin >> n >> m;
		if (n % m) k = n / m + 1;
		else k = n / m;
		// std::cout << k << std::endl;
		for (int i = 1; i <= m; i++) {
			if (i % 2)
				for (int j = 1; j <= k; j++) {
					if (m * (j - 1) + i > n) continue;
					mapp[m * (j - 1) + i] = ++tag;
				}
			else
				for (int j = k; j >= 1; j--) {
					if (m * (j - 1) + i > n) continue;
					mapp[m * (j - 1) + i] = ++tag;
				}
			// std::cout << tag << std::endl;
		}
		for (int i = 1; i <= n; i++) {
			std::cout << mapp[i] << " ";
		}
		std::cout << std::endl;
	}
	return 0;
}