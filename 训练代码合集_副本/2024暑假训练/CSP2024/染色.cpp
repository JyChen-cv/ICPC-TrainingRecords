// 一定是和最近的匹配最优秀

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
const int N = 1e6;
int a[N + 2], n, rec[N + 2], dp[N + 2];
std::map<int, int> apear;

inline int find(int l, int r) {
	if (r < l) return 0;
	return rec[r] - rec[l];
}
void solve() {
	std::cin >> n;
	apear.clear();
	for (int i = 0; i <= n + 1; i++) rec[i] = dp[i] = 0;
	for (int i = 1; i <= n; i++) std::cin >> a[i];
	for (int i = 2; i <= n; i++) {
		rec[i] = rec[i - 1];
		if (a[i] == a[i - 1]) rec[i] += a[i];
	}
	// for (int i = 1; i <= n; i++) std::cout << rec[i] << " \n"[i == n];
	int ans = 0;
	for (int i = 1; i <= n; i++) {
		if (apear[a[i]] == i - 1 && apear[a[i]]) dp[i] = dp[i - 1] + a[i];
		else if (apear[a[i]]) {
			dp[i] = dp[apear[a[i]] + 1] + a[i] + find(apear[a[i]] + 1, i - 1);
		}
		apear[a[i]] = i;
		dp[i] = std::max(dp[i], dp[i - 1]);
		// std::cout << dp[i] << " \n"[i == n];
	}
	std::cout << dp[n] << std::endl;
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