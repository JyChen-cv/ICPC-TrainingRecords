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
int a[N + 2];
void solve() {
	int n;
	std::cin >> n;
	int ans = 0, now = 0;
	for (int i = 1; i <= n; i++) {
		std::cin >> a[i];
		if (now == 1) {
			if (a[i] == 1) {
				ans++;
				now = 2;
				continue;
			}
			else {
				ans += 2;
				a[i] = std::max(0LL, a[i] - 4);
				now = 0;
			}
		}
		else if (now == 2) {
			a[i] = std::max(0LL, a[i] - 3);
			now = 0;
			ans++;
		}
		if (!a[i]) continue;
		int ls = a[i] / 5;
		ans += ls * 3;
		int lls = a[i] % 5;
		if (lls <= 2) {
			ans += lls;
			now = lls;
		}
		else {
			ans += 3;
			now = 0;
		}
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