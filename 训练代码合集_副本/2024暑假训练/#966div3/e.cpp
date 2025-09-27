#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <vector>
#include <queue>
#include <map>
#include <cstring>
#include <set>

#define int long long
typedef long long ll;
typedef double db;
typedef std::pair<int, int> PII;
bool cmp(int x, int y) {
	return x > y;
}
void solve() {
	int n, m, k;
	std::cin >> n >> m >> k;
	std::vector<int> q, v;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			int lx = std::max(1LL, i - k + 1), rx = std::min(i, n - k + 1);
			int ly = std::max(1LL, j - k + 1), ry = std::min(j, m - k + 1);
			int pow = (rx - lx + 1) * (ry - ly + 1);
			// std::cout << i << " " << j << ": " << pow << std::endl;
			q.push_back(pow);
		}
	}
	std::sort(q.begin(), q.end(), cmp);
	int all;
	std::cin >> all;
	for (int i = 1; i <= all; i++) {
		int a;
		std::cin >> a;
		v.push_back(a);
	}
	std::sort(v.begin(), v.end(), cmp);
	int ans = 0;
	for (int i = 0; i < all; i++) {
		ans += v[i] * q[i];
	}
	std::cout << ans << std::endl;
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