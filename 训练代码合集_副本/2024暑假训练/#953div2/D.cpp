#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>

#define int long long
const int N = 2e5;
int mapp[N + 2], mx[N + 2], sum[N + 2];

signed main()
{
	int t;
	std::cin >> t;
	while (t--) {
		int n, c;
		std::cin >> n >> c;
		for (int i = 1; i <= n; i++) {
			std::cin >> mapp[i];
			if (i == 1) mapp[i] += c;
			mx[i] = std::max(mx[i - 1], mapp[i]);
			sum[i] = sum[i - 1] + mapp[i];
		}
		int maxx = mx[n];
		for (int i = 1; i <= n; i++) {
			if (mx[i - 1] < mapp[i] && mapp[i] == maxx) {
				std::cout << 0 << " ";
			}
			else {
				if (mapp[i] + sum[i - 1] >= maxx) {
					std::cout << i - 1 << " ";
				}
				else std::cout << i << " ";
			}
		}
		std::cout << std::endl;
	}
	return 0;
}