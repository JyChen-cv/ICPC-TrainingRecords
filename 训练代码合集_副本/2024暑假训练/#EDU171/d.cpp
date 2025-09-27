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
const int N = 3e5;
int n, m;
int a[N + 2], s1[N + 2], s2[N + 2], s3[N + 2], dis[N + 2];

int lookUp(int k, int d) {
	int res = s2[n + 1 - d];
	// std::cout << k << " " << d << " " << res << std::endl;
	res += d * (s1[n - d] - s1[k - 1]);
	// std::cout << k << " ?" << d << " " << res << std::endl;
	return res;
}
void solve() {
	std::cin >> n;
	for (int i = 1; i <= n; i++) {
		std::cin >> a[i];
		s1[i] = s1[i - 1] + a[i];
		dis[i] = dis[i - 1] + n - i + 1;
	}
	s2[n] = a[n];
	for (int i = n - 1; i >= 1; i--) {
		s2[i] = a[i] * (n - i + 1) + s2[i + 1];  // fanxu
	}
	// for (int i = 1; i <= n; i++) {
	// 	std::cout << s2[i] << std::endl;
	// }
	for (int i = 1; i <= n; i++) s3[i] = s3[i - 1] + s2[i];

	std::cin >> m;
	while (m--) {
		int l, r;
		std::cin >> l >> r;
		int p1 = std::lower_bound(dis + 1, dis + n + 1, l) - dis;
		int p2 = std::lower_bound(dis + 1, dis + n + 1, r) - dis;
		// std::cout << p1 << " ? " << dis[p1] << " " << p2 << " ? " << dis[p2] << std::endl;
		int res = s3[p2] - s3[p1];
		// std::cout << res << std::endl;
		res += lookUp(p1, dis[p1] - l + 1);
		res -= lookUp(p2, dis[p2] - r);
		std::cout << res << std::endl;
	}
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