#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <vector>
#include <queue>
#include <map>
#include <unordered_map>
#include <cstring>
#include <set>

#define int long long
typedef long long ll;
typedef double db;
typedef std::pair<int, int> PII;
const int N = 2e5;
int cnt[N + 2];
void solve() {
	int n, ans = 0;
	std::cin >> n;
	for (int i = 0; i <= 30; i++) cnt[i] = 0;
	for (int i = 1; i <= n; i++) {
		int a;
		std::cin >> a;
		for (int d = 30; d >= 0; d--) {
			if (a >= (1LL << d)) {
				a -= 1LL << d;
				ans += (i - 1 - cnt[d]) * (1LL << d);
				cnt[d] = i - 1 - cnt[d] + 1;
			}
			else {
				ans += (cnt[d]) * (1LL << d);
			}
		}
		// for (int j = 0; j <= 3; j++) {
		// 	std::cout << cnt[i] << " \n"[j == 3];
		// }
	}
	std::cout << ans << std::endl;
}

signed main() {
	std::ios::sync_with_stdio(0);
	std::cin.tie(0), std::cout.tie(0);
	int times = 1;
	// std::cin >> times;
	while (times--) {
		solve();
	}
	return 0;
}