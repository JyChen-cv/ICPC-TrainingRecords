#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>

#define int long long

bool cmp(int x, int y) {
	return x > y;
}
void solve() {
	int n;
	std::vector<int> q;
	std::cin >> n;
	int mx = 0;
	for (int i = 1; i <= n; i++) {
		int a;
		std::cin >> a;
		if (a % 2) mx = std::max(mx, a);
		else q.push_back(a);
	}
	if (q.size() == n || !q.size()) {
		std::cout << 0 << std::endl;
		return ;
	}
	int res1 = 0, mx1 = mx;
	std::sort(q.begin(), q.end(), cmp);
	for (auto i : q) {
		if (mx1 > i) {
			res1 += 1;
			mx1 += i;
		}
		else {
			mx1 += i * 2;
			res1 += 2;
		}
	}
	int res2 = 0, mx2 = mx;
	std::sort(q.begin(), q.end());
	for (auto i : q) {
		if (mx2 > i) {
			res2 += 1;
			mx2 += i;
		}
		else {
			mx2 += i * 2;
			res2 += 2;
		}
	}
	std::cout << std::min(res1, res2) << std::endl;
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