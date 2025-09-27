#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>

typedef long long ll;
const int N = 1e5;
ll mapp[N + 2], sum[N + 2];

int main()
{
	int t;
	std::cin >> t;
	while (t--) {
		int n;
		std::cin >> n;
		for (int i = 1; i <= n; i++) {
			scanf("%lld", mapp + i);
			sum[i] = sum[i - 1] + mapp[i];
		}
		int q;
		std::cin >> q;
		for (int i = 1; i <= q; i++) {
			int l;
			ll u;
			scanf("%d%lld", &l, &u);
			int ls = std::lower_bound(sum + 1, sum + n + 1, u + sum[l - 1]) - sum;
			ll res1 = sum[ls] - sum[l - 1];
			ll res2 = sum[ls - 1] - sum[l - 1];
			ll ans1 = (u + (u + 1 - res1)) * res1 / 2;
			ll ans2 = (u + (u + 1 - res2)) * res2 / 2;
			// std::cout << ans1 << " ?" << ans2 << " ?";
			int ans = ls;
			if (ls > l) {
				if (ans2 >= ans1) ans = ls - 1;
			}
			if (ls > n) ans = ls - 1;
			std::cout << ans << " ";
		}
		puts("");
	}
	return 0;
}