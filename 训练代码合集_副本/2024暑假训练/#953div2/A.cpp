#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>

const int N = 1e5;
int mapp[N + 2];
int main()
{
	int t;
	std::cin >> t;
	while (t--) {
		int n;
		std::cin >> n;
		for (int i = 1; i <= n; i++) {
			std::cin >> mapp[i];
		}
		std::sort(mapp + 1, mapp + n);
		std::cout << mapp[n] + mapp[n - 1] << std::endl;
	}

	return 0;
}