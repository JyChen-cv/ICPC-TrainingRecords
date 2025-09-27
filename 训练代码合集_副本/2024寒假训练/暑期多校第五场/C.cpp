#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <vector>

std::vector<int> mapp;
int gcd(int x, int y) {
	return y ? gcd(y, x % y) : x;
}

int main()
{
	int t;
	std::cin >> t;
	while (t--) {
		mapp.clear();
		int k, c, n;
		std::cin >> k >> c >> n;
		for (int i = 1; i * i <= c; i++) {
			if (c / i < i) break;
			if (c % i == 0) {
				mapp.push_back(i);
				mapp.push_back(c / i);
			}
		}
		std::sort(mapp.begin(), mapp.end());
		mapp.erase(unique(mapp.begin(), mapp.end()), mapp.end());
		int ans = 0;
		for (int i = 0; i < (int)mapp.size(); i++) {
			int ls = c / mapp[i];
			if (ls == 1) continue;
			if ((ls - 1)*mapp[i] % k == 0) {
				int a = (ls - 1) * mapp[i] / k;
				if (gcd(a, mapp[i]) < n) continue;
				// std::cout << a << " " << mapp[i] << std::endl;
				ans++;
			}
		}
		std::cout << ans << std::endl;
	}
	return 0;
}