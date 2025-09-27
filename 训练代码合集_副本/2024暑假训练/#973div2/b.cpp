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
const int N = 2e5nint mapp[N + 2];
void solve() {
	int n;
	std::cin >> n;
	for (int i = 1; i <= n; i++) {
		std::cin >> mapp[i];
	}
	int ans = mapp[n];
	for (int i = 1; i <= n - 2; i++) {
		mapp[n - 1] -= mapp[i];
	}
	std::cout << ans - mapp[n - 1] << std::endl;
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