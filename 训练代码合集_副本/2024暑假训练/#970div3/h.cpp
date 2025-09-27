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
const int N = 1e5;
int a[N + 2], rem[N + 2];
int n, m;
inline int sum(int x, int y) {
	if (x) return a[y] - a[x - 1];
	else return a[y];
}
bool check(int x, int k) {
	int res = 0;
	for (int i = 0; i * k <= n; i++) {
		int l = i * k, r = i * k + x;
		r = std::min(n, r);
		res += sum(l, r);
	}
	// std::cout << x << "? " << k << " " << res << std::endl;
	return res >= ((n + 2) / 2);
}
void solve() {
	std::cin >> n >> m;
	for (int i = 0; i <= n; i++) rem[i] = -1, a[i] = 0;
	for (int i = 1; i <= n; i++) {
		int x; std::cin >> x;
		a[x]++;
	}
	for (int i = 1; i <= n; i++) a[i] += a[i - 1];
	for (int i = 1; i <= m; i++) {
		int x;
		std::cin >> x;
		if (rem[x] != -1) {
			std::cout << rem[x] << " \n"[i == m];
			continue;
		}
		int l = 0, r = x - 1;
		while (l < r) {
			int mid = (l + r ) >> 1;
			if (check(mid, x)) r = mid;
			else l = mid + 1;
		}
		rem[x] = l;
		std::cout << l << " \n"[i == m];
	}
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