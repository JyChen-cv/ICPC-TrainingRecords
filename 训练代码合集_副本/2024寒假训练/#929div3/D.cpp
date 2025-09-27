#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>

typedef long long ll;
const int N = 1e5;
ll mapp[N + 2];
int main()
{
	int t;
	std::cin >> t;
	while (t--) {
		int n;
		std::cin >> n;
		ll mi = 1e18, num = 0;
		for (int i = 1; i <= n; i++) {
			scanf("%lld", mapp + i);
			if (mapp[i] < mi) {
				mi = mapp[i];
				num = 1;
			}
			else if (mapp[i] == mi) num++;
		}
		if (num == 1) std::cout << "YES" << std::endl;
		else {
			int tag = 0;
			for (int i = 1; i <= n; i++) {
				ll ls = mapp[i] % mi;
				if (ls) {
					tag = 1;
					break;
				}
			}
			if (tag)std::cout << "YES" << std::endl;
			else std::cout << "NO" << std::endl;
		}
	}
	return 0;
}