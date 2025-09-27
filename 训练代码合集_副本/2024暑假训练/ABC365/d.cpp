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
int dp[N + 2][2];
int n;
std::string a;
bool check(int x, int y) {
	// x<y;
	if (a[x] == 'R' && a[y] == 'P') return 1;
	if (a[x] == 'P' && a[y] == 'S') return 1;
	if (a[x] == 'S' && a[y] == 'R') return 1;
	return 0;
}
void solve() {
	std::cin >> n >> a;
	a = '0' + a;
	for (int i = 1; i <= n; i++) {
		if (a[i] == a[i - 1]) {
			dp[i][1] = dp[i - 1][0] + 1;
			dp[i][0] = dp[i - 1][1];
		}
		else {
			if (check(i, i - 1)) {
				dp[i][1] = dp[i - 1][1] + 1;
				dp[i][0] = std::max(dp[i - 1][0], dp[i - 1][1]);
			}
			else {
				dp[i][1] = std::max(dp[i - 1][1], dp[i - 1][0]) + 1;
				dp[i][0] = dp[i - 1][0];
				// else dp[i][0] = std::max(dp[i - 1][1], dp[i - 1][0]);
			}
		}
		// std::cout << dp[i][0] << " " << dp[i][1] << "\n";
	}
	std::cout << std::max(dp[n][0], dp[n][1]) << std::endl;
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