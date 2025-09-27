// https://codeforces.com/problemset/problem/1987/D

// 难点1在转化式子，难点2在有式子后去设计一个合理的dp状态，这题目评分才1800，只能说感觉这种类型的题目着实是弱点
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

const int N = 5000;
int a[N + 2], dp[N + 2][N + 2];
void solve() {
	int n, cnt = 0;
	std::cin >> n;
	for (int i = 0; i <= n; i++) {
		a[i] = 0;
		for (int j = 0; j <= n; j++) {

		}
	}
	for (int i = 1; i <= n; i++) {
		int ls; std::cin >> ls;
		a[ls]++;
	}
	std::vector<PII> q; q.push_back({0, 0});
	for (int i = 1; i <= n; i++) {
		if (a[i]) q.push_back({i, a[i]});
	}
	// std::cout << q.size() << "?" << std::endl;
	for (int i = 0; i <= (int)q.size(); i++) {
		for (int j = 0; j <= (int)q.size(); j++) dp[i][j] = 1e9;
	}
	dp[0][0] = 0;
	int ans = 0;
	for (int i = 1; i < (int)q.size(); i++) {
		for (int j = 0; j <= i; j++) {
			dp[i][j] = dp[i - 1][j];
			if (j == 0) continue;
			if (dp[i - 1][j - 1] + q[i].second <= i - j) {
				dp[i][j] = std::min(dp[i][j], dp[i - 1][j - 1] + q[i].second);
			}
			if (i == q.size() - 1 && dp[i][j] != 1e9) ans = std::max(ans, j);
		}
	}
	std::cout << q.size() - 1 - ans << std::endl;
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