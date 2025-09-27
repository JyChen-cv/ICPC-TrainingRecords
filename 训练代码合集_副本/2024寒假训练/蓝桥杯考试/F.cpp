#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>

const int N = 1e5;
long long mapp[N + 2], num[N + 2];

int check(int x, int y, int z, int t) {
	if (mapp[x] > mapp[z] || mapp[y] > mapp[t])
		return 0;
	if (mapp[z] % mapp[x] == 0 && mapp[t] % mapp[y] == 0)
		return 1;
	else
		return 0;
}

int main() {
	int n;
	std::cin >> n;
	for (int i = 1; i <= n; i++) {
		std::cin >> mapp[i];
	}
	if (n <= 50) {
		int cnt = 0;
//		std::cout << 1 << std::endl;
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				if (i == j)
					continue;
				for (int k = 1; k <= n; k++) {
					if (i == k || j == k)
						continue;
					for (int l = 1; l <= n; l++) {
						if (i == l || j == l || k == l )
							continue;
						if (check(i, j, k, l))
							cnt++;
					}
				}
			}
		}
		std::cout << cnt << std::endl;
	} else {
		long long cnt = 0, all = 0;
		for (int i = 1; i <= n; i++) {
			for (int j = i + 1; j <= n; j++) {
//				std::cout << n << std::endl;
				if (mapp[i] == mapp[j])
					cnt++;
				if (mapp[i] % mapp[j] == 0) {
					num[i]++, num[j]++, all++;
				}
				if (mapp[j] % mapp[i] == 0) {
					num[i]++, num[j]++, all++;
				}
			}
		}
		cnt += all * (all - 1) / 2;
		for (int i = 1; i <= n; i++) {
			cnt -= num[i] * (num[i] - 1) / 2;
		}
		std::cout << cnt * 2 << std::endl;
	}
	return 0;
}

