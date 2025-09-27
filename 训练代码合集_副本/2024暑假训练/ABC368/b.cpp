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
const int N = 1e3;
int a[N + 2];
void solve() {
	int n;
	std::cin >> n;
	for (int i = 1; i <= n; i++) {
		std::cin >> a[i];
		a[i] = -a[i];
	}
	if (n == 1) {
		std::cout << 0 << std::endl;
		return ;
	}
	int ans = 0;
	while (1) {
		std::sort(a + 1, a + n + 1);
		if (a[2] >= 0) {
			std::cout << ans << std::endl;
			break;
		}
		a[1]++, a[2]++;
		ans++;
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