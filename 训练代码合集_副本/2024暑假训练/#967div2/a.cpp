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
const int N = 1000;
int c[N + 2];
void solve() {
	int n;
	std::cin >> n;
	for (int i = 1; i <= n; i++) c[i] = 0;
	for (int i = 1; i <= n; i++) {
		int a;
		std::cin >> a;
		c[a]++;
	}
	int ans = 0;
	for (int i = 1; i <= n; i++) {
		ans = std::max(ans, c[i]);
	}
	std::cout << n - ans << std::endl;
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