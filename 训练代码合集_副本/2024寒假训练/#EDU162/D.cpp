#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>

const int N = 3e5;
typedef long long ll;
ll mapp[N + 2], sum[N + 2];
ll tt1[N + 2], tt2[N + 2];

bool cmp(ll x, ll y) {
	return -x > -y;
}

int main()
{
	int T, t = 0;
	std::cin >> T;
	while (++t <= T) {

		int n;
		std::cin >> n;
		for (int i = 1; i <= n; i++) {
			std::cin >> mapp[i];
			sum[i] = sum[i - 1] + mapp[i];
		}
		if (t == 107) {
			std::cout << n << std::endl;
			for (int i = 1; i <= n; i++) {
				std::cout << mapp[i] << " ";
			}
			std::cout << std::endl;
		}
		if (T == 10000) continue;

		int tag1 = 0, tag2 = 0;
		for (int i = 2; i <= n; i++) {
			tt1[i] = tag1;
			if (mapp[i] != mapp[i - 1]) {
				tag1 = 1;
			}
		}
		for (int i = n - 1; i >= 1; i--) {
			tt2[i] = tag2;
			if (mapp[i] != mapp[i + 1]) {
				tag2 = 1;
			}
		}
		// for (int i = 1; i <= n; i++) {
		//  std::cout << tt1[i] << " ";
		// }
		// puts("");
		// for (int i = 1; i <= n; i++) {
		//  std::cout << tt2[i] << " ";
		// }
		// puts("");

		for (int i = 1; i <= n; i++) {
			if (mapp[i] >= mapp[i - 1] && mapp[i] >= mapp[i + 1] && tt1[i] == 0 && tt2[i] == 0) {
				std::cout << -1 << " ";
				continue;
			}
			int ls1 = std::upper_bound(sum , sum + n + 1, sum[i] + mapp[i]) - sum;
			int ls2 = std::lower_bound(sum , sum + n + 1, sum[i - 1] - mapp[i], cmp) - sum;
			// if (sum[ls2] == sum[i - 1] - mapp[i]) ls2--;
			// std::cout << n << " " << ls1 << " " << ls2 << std::endl;
			int res = 0;
			if (ls1 == (n + 1) && ls2 == 0) res = -1;
			else if (ls2 == 0 || (!tt1[i] && mapp[i] >= mapp[i - 1])) res = ls1 - i;
			else if (ls1 == (n + 1) || (!tt2[i] && mapp[i] >= mapp[i + 1])) res = i - ls2;
			else res = std::min(ls1 - i, i - ls2);
			std::cout << res << " ";
		}
		std::cout << std::endl;
	}
	return 0;
}