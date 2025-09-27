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
int rem[1002][1002][2];
int deal0(int x, int y) {
	return (x + y) % 2;
}
int deal1(int x, int y, int z) {
	if (rem[x][y][z] != -1) return rem[x][y][z];
	int v[4];
	memset(v, 0, sizeof v);
	if (z == 1) {
		if (x > 1 && y > 1) v[deal0(x - 1, y - 1)] = 1;
	}
	if (x > 1) v[deal1(x - 1, y, z)] = 1;
	if (y > 1) v[deal1(x, y - 1, z)] = 1;
	for (int i = 0; i <= 3; i++) {
		if (!v[i]) return rem[x][y][z] = i;
	}
}
void solve() {
	int n, m;
	int ans = 0;
	std::cin >> n >> m;
	memset(rem, -1, sizeof rem);
	for (int i = 1; i <= n; i++) {
		std::string a;
		std::cin >> a;
		int l = 0, r = 0;
		if (m % 2) {
			for (int j = 1; j <= (m + 1) / 2; j++) {
				l += a[j - 1] == '1';
			}
			for (int j = (m + 1) / 2; j <= m; j++) {
				r += a[j - 1] == '1';
			}
			ans ^= deal1(l, r, a[(m + 1) / 2 - 1] == '1');
			// std::cout << l << " " << r << " " << deal1(l, r, a[(m + 1) / 2] == '1') << std::endl;
		}
		else {
			for (int j = 1; j <= m / 2; j++) {
				l += a[j - 1] == '1';
			}
			for (int j = m / 2 + 1; j <= m; j++) {
				r += a[j - 1] == '1';
			}
			ans ^= deal0(l, r);
			// std::cout << l << " " << r << " " << ans << std::endl;
		}
	}
	puts(ans ? "Alice" : "Bob");
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