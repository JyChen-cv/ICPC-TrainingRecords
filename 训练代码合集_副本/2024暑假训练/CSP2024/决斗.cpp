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
int a[N + 2];
void solve() {
	int n;
	std::cin >> n;
	for (int i = 1; i <= n; i++) std::cin >> a[i];
	std::sort(a + 1, a + n + 1);
	int point = 1, cnt = 0;
	for (int i = 1; i <= n; i++) {
		while (a[point] <= a[i] && point + 1 <= n + 1) point++;
		if (point == n + 1) break;
		else cnt++;
		point++;
		// std::cout << point << std::endl;
	}
	std::cout << n - cnt << std::endl;
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