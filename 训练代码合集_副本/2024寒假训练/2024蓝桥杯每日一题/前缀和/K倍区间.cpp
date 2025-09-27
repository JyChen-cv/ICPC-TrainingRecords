#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>

typedef long long ll;
const int N = 1e5;
ll mapp[N + 2], res[N + 2];

int main()
{
	int n;
	ll k;
	std::cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		std::cin >> mapp[i];
		mapp[i] += mapp[i - 1];
		mapp[i] %= k;
	}
	ll ans = 0;
	for (int i = 1; i <= n; i++) {
		// std::cout << mapp[i] << std::endl;
		ans += res[mapp[i]];
		res[mapp[i]]++;
		if (mapp[i] == 0) ans++;
	}
	std::cout << ans << std::endl;
	return 0;
}