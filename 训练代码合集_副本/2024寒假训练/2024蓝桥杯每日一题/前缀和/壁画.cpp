#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <queue>

const int N = 5e6;
#define x first
#define y second
char mapp[N + 2];
long long res[N + 2];

int main() {
	int t = 0, T;
	std::cin >> T;
	while (++t <= T) {
		int n;
		std::cin >> n;
		scanf("%s", mapp + 1);
		for (int i = 1; i <= n; i++) {
			res[i] = res[i - 1] + mapp[i] - '0';
		}
		int len = (n + 1) / 2;
		long long ans = 0;
		for (int i = len; i <= n; i++) {
			ans = std::max(ans, res[i] - res[i - len]);
		}
		std::cout << "Case #" << t << ": " << ans << std::endl;
	}
	return 0;
}