#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>

#define int long long
typedef long long ll;
const int N = 1e5;
ll mapp[N + 2], cnt[N + 2], s;
int n;

bool check(int x) {
	ll res = 0;
	for (int i = 1; i <= n; i++) {
		if (cnt[i] >= x)
			res += mapp[i];
	}
	return res >= s;
}

signed main() {
	std::cin >> n >> s;
	for (int i = 1; i <= n; i++) {
		std::cin >> mapp[i] >> cnt[i];
	}
	int l = 0, r = 1e6;
	while (l < r) {
		int mid = (l + r + 1) >> 1;
//		std::cout << l << " " << mid << " " << r << std::endl;
		if (check(mid))
			l = mid;
		else
			r = mid - 1;
		// zuihouyige >= s de weizhi
	}
//	std::cout << l << std::endl;
	ll ans = s * l;
	for (int i = 1; i <= n; i++) {
		ans += (cnt[i] - l) * mapp[i];
	}
	std::cout << ans << std::endl;
	return 0;
}
