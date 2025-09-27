#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <utility>
#include <vector>
#include <queue>
#include <map>
#include <unordered_map>
#include <cstring>
#include <set>
#include <bitset>

#define int long long
typedef long long ll;
typedef double db;
typedef std::pair<int, int> PII;

const int N = 2e5;
std::map<std::pair<int, int>, int> q;
int f[N + 2], c[N + 2], res, ans;

inline int deal(int x, int y) {
	if (f[x] && f[y]) {res++; return 1;}
	else if (f[x]) {c[y]++; return 1;}
	else if (f[y]) {c[x]++; return 1;}
	return 0;
}

void solve() {
	q.clear(); res = 0, ans = 0;
	int n, m, k;
	std::cin >> n >> m >> k;
	for (int i = 1; i <= k; i++) {
		c[i] = f[i] = 0;
	}

	for (int i = 1; i <= n; i++) {
		int a;
		std::cin >> a;
		f[a] = 1;
	}
	for (int i = 1; i <= m; i++) {
		int a, b;
		std::cin >> a >> b;
		if (a == b) c[a]++;
		else {
			if (deal(a, b)) continue;
			if (a < b) std::swap(a, b);
			q[ {a, b}]++;
		}
	}
	// for (int i = 1; i <= k; i++) {
	// 	std::cout << c[i] << " ";
	// }
	// std::cout << std::endl;
	// for (int i = 1; i <= k; i++) {
	// 	std::cout << f[i] << " ";
	// }
	// std::cout << std::endl;
	// std::cout << res << std::endl;

	int mx1 = 0, mx2 = 0;
	for (int i = 1; i <= k; i++) {
		if (f[i]) {
			res += c[i];
			continue;
		}
		if (c[i] >= mx1) {
			mx2 = mx1;
			mx1 = c[i];
		}
		else if (c[i] > mx2) mx2 = c[i];
	}
	// std::cout << mx1 << " " << mx2 << std::endl;
	ans = res + mx1 + mx2;

	for (auto i : q) {
		int x = i.first.first, y = i.first.second;
		if (x < y) std::swap(x, y);
		// std::cout << x << " " << y << " " << i.second << std::endl;
		ans = std::max(ans, res + i.second + c[x] + c[y]);
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