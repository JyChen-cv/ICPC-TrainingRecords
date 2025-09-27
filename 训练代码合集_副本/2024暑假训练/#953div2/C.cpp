#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>

#define int long long
const int N = 2e5;
int mapp[N + 2];
signed main()
{
	std::ios::sync_with_stdio(0);
	std::cin.tie(0);
	std::cout.tie(0);

	int t;
	std::cin >> t;
	while (t--) {
		int n, k;
		std::cin >> n >> k;
		for (int i = 1; i <= n; i++) {
			mapp[i] = i;
		}
		int nmax = 0;
		if (n % 2) {
			nmax = (n + 1) / 2 * (n - 1);
		}
		else nmax = (n / 2) * (n - 1 + 1);

		if (k % 2 != 0 || k > nmax) {
			std::cout << "No" << std::endl;
			continue;
		}
		int l = 1, r = n;
		while (l <= r) {
			if (k == 0) break;

			if (k <= 2 * (r - l)) {

				std::swap(mapp[l], mapp[l + k / 2]);
				k = 0;
			}
			else {
				k -= (mapp[r] - mapp[l]) * 2;
				std::swap(mapp[l], mapp[r]);
				l++, r--;
			}
			// std::cout << k << " " << mapp[l] << " " << mapp[r] << std::endl;
		}
		if (k) std::cout << "No" << std::endl;
		else {
			std::cout << "Yes" << std::endl;
			for (int i = 1; i <= n; i++) std::cout << mapp[i] << " ";
			std::cout << std::endl;
		}
	}
	return 0;
}