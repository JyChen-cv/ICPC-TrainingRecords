#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>

#define int long long
const int N = 1e5;
int mapp[N + 2], a[N + 2];

signed main()
{
	int n, d;
	std::cin >> n >> d;
	for (int i = 2; i <= n; i++) {
		std::cin >> mapp[i];
		mapp[i] += mapp[i - 1];
	}
	for (int i = 1; i <= n; i++) {
		std::cin >> a[i];
	}

	int mi = 0x3f3f3f3f, ans = 0, far = 0;
	for (int i = 1; i <= n; i++) {
		if (far >= mapp[i]) {
			mi = std::min(a[i], mi);
		}
		else {
			int ls = (mapp[i] - far) / d + ((mapp[i] - far) % d ? 1 : 0);
			ans += mi * ls;
			far += ls * d;
			mi = std::min(a[i], mi);
		}
	}
	std::cout << ans << std::endl;
	return 0;
}