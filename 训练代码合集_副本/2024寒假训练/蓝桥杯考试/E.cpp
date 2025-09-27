#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>

const int N = 1e5;
double mapp[N + 2], t, sum[N + 2];
int n, k;

int main() {
	std::cin >> n >> k >> t;
	double avg = 0;
	for (int i = 1; i <= n; i++) {
		std::cin >> mapp[i];
		avg += mapp[i];
	}
	avg /= n;
	std::cout << avg << std::endl;
	for (int i = 1; i <= n; i++) {
		mapp[i] -= avg;
		mapp[i] *= mapp[i];
	}
	std::sort(mapp + 1, mapp + n + 1);
	for (int i = 1; i <= n; i++) {
		std::cout << mapp[i] << std::endl;
		sum[i] = sum[i - 1] + mapp[i];
	}
	int tag = 0;
	for (int i = k; i <= n; i++) {
		double res = sum[i] - sum[i - k];
		std::cout << k << " " << res << std::endl;
		if (res < t)
			i++;
		else {
			tag = i;
			break;
		}
	}
	if (tag == 0)
		std::cout << -1 << std::endl;
	else
		std::cout << (n - tag + k) << std::endl;

	return 0;
}
