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
#include <bitset>

#define int long long
typedef long long ll;
typedef double db;
typedef std::pair<int, int> PII;

const int N = 2e5;
int a[N + 2], dp[N + 2], ms[N + 2];
int solve() {
	int n;
	std::cin >> n;
	for (int i = 1; i <= n; i++) {
		std::cin >> a[i];
	}

	std::queue<int> q[N + 2];
	for (int i = 1; i <= n; i++) {
		// dp[i] = dp[i - 1], ms[i] = ms[i - 1];
		if (!q[a[i]].size()) q[a[i]].push(0);
		int x = q[a[i]].front();
		if (ms[x] & (1 << a[i])) {
		}
		else {
			dp[i] = dp[x] + 2;
			ms[i] = ms[x] | (1 << a[i]);
		}

		if (dp[i - 1] > dp[i]) {

		}
	}
}

signed main() {
	std::ios::sync_with_stdio(0);
	std::cin.tie(0), std::cout.tie(0);
	int times = 1;
	// std::cin >> times;
	while (times--) {
		std::cout << solve() << std::endl;
	}
	return 0;
}