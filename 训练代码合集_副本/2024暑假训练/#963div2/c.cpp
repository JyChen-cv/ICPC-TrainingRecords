#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <utility>
#include <vector>

#define int long long
const int N = 2e5;
int a[N + 2];
typedef std::pair<int, int> pii;

pii merge(pii x, pii y) {
	pii res;
	res.first = std::max(x.first, y.first);
	res.second = std::min(x.second, y.second);
	if (res.first > res.second) res.first = -1;
	return res;
}
void solve() {
	int n, k;
	std::cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		std::cin >> a[i];
	}
	std::sort(a + 1, a + n + 1);
	pii ans = {a[n], a[n] + k - 1};
	int tag = 1;
	for (int i = 1; i < n; i++) {
		int deal = (a[n] - a[i]) / k;
		if (deal % 2) deal++;
		pii ls = {a[i] + deal * k, a[i] + deal*k + k - 1};
		ans = merge(ls, ans);
		if (ans.first == -1) {
			tag = 0;
			break;
		}
		// std::cout << ls.first << " " << ls.second << std::endl;
		// std::cout << ans.first << " " << ans.second << std::endl;
	}
	if (!tag) std::cout << -1 << std::endl;
	else std::cout << ans.first << std::endl;
}
signed main() {
	std::ios::sync_with_stdio(0);
	std::cin.tie(0), std::cout.tie(0);
	int times = 1;
	std::cin >> times;
	while (times--) {
		solve();
	}
	return 0;
}