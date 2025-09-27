#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <vector>

const int N = 2e5;
int n;
char mapp[N + 5];

int main()
{
	scanf("%d", &n);
	scanf("%s", mapp + 1);
	int base = 0, add = 0;
	for (int i = 1; i <= n; i++) {
		int cnt = 1;
		int ls = i;
		while (mapp[i] == mapp[i + 1]) {
			i++;
			cnt++;
		}
		if (mapp[i] == 'F') {
			if (cnt % 2) {
				if (mapp[ls - 1] == mapp[i + 1]) add += cnt + 1;
				else add += cnt - 1, base += 1;
			}
			else {
				if (mapp[ls - 1] == mapp[i + 1]) add += cnt, base += 1;
				else add += cnt;
			}
		}
		else base += cnt - 1;
	}

	if (add == n) {
		std::cout << n << std::endl;
		for (int i = 0; i < n; i++) {
			std::cout << i << std::endl;
		}
		return 0;
	}

	int ans = add / 2 + 1;
	if (mapp[1] == 'F' || mapp[n] == 'F') {
		ans *= 2;
		ans -= (base ? 0 : 1);
		std::cout << ans << std::endl;
		for (int i = std::max(0, base - 1); i <= base + add; i++) {
			printf("%d\n", i);
		}
	}
	else {
		std::cout << ans << std::endl;
		for (int i = base; i <= base + add; i += 2) {
			printf("%d\n", i);
		}
	}

	return 0;
}