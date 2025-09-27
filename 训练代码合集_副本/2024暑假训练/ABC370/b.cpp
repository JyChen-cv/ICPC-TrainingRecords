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
const int N = 100;
int a[N + 2][N + 2];
void solve() {
	int n;
	std::cin >> n;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= i; j++) {
			std::cin >> a[i][j];
		}
	}
	int ans = 1;
	for (int i = 1; i <= n; i++) {
		int tag = i;
		if (ans < tag) std::swap(ans, tag);
		ans = a[ans][tag];
		// std::cout << ans << std::endl;
	}
	std::cout << ans << std::endl;
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