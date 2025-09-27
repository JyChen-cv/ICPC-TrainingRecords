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
int a[N + 2], dp[N + 2][2];
void solve() {
	int n;
	std::cin >> n;
	for (int i = 1; i <= n; i++) {
		std::cin >> a[i];
	}
	std::sort(a + 1, a + n + 1);
	for (int i = 1; i <= n; i++) dp[i][0] = dp[i][1] = 0;
	dp[0][0] = 1, dp[0][1] = 1e18;
	dp[1][0] = 1e18; dp[1][1] = 1;
	for (int i = 2; i <= n; i++) {
		dp[i][0] = std::max(dp[i - 2][0], a[i] - a[i - 1]);
		dp[i][1] = std::max(dp[i - 1][0], 1ll);
		dp[i][1] = std::min(dp[i][1], std::max(dp[i - 2][1], a[i] - a[i - 1]));
	}
	std::cout << std::min(dp[n][0], dp[n][1]) << std::endl;
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

/*

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
int a[N + 2], mx1[N + 2], mx2[N + 2];
void solve() {
	int n;
	std::cin >> n;
	for (int i=0;i<=n+10;i++) mx1[i]=mx2[i]=0;
	for (int i = 1; i <= n; i++) {
		std::cin >> a[i];
	}
	std::sort(a + 1, a + n + 1);
	if (n % 2 == 0) {
		int max1 = 0;
		for (int i = 1; i <= n; i += 2) {
			max1 = std::max(max1, a[i + 1] - a[i]);
		}
		std::cout << max1 << std::endl;
		return ;
	}
	for (int i = 2; i <= n; i += 2) {
		mx1[i] = std::max(mx1[i - 2], a[i] - a[i - 1]);
	}
	for (int i = n - 1; i >= 2; i -= 2) {
		mx2[i] = std::max(mx2[i + 2], a[i + 1] - a[i]);
	}
	int ans = 1e18;
	for (int i = 0; i <= n; i += 2) {
		ans = std::min(ans, std::max(mx1[i], mx2[i + 2]));
	}
	ans = std::max(ans, 1ll);
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

*/