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
int a[N + 2], d[N + 2][2];
void solve() {
	int n;
	std::cin >> n;
	for (int i = 1; i <= n; i++) {
		std::cin >> a[i];
	}
	d[0][1] = -1e15;
	for (int i = 1; i <= n; i++) {
		d[i][0] = std::max(d[i - 1][0], d[i - 1][1] + a[i] * 2);
		d[i][1] = std::max(d[i - 1][1], d[i - 1][0] + a[i]);
	}
	std::cout << std::max(d[n][0], d[n][1]) << std::endl;
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