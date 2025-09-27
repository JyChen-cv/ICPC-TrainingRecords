// 开始写之前请先想好复杂度正确
#include <functional>
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <vector>
#include <queue>
#include <map>
#include <cstring>
#include <set>

#define int long long
typedef long long ll;
typedef double db;
typedef std::pair<int, int> PII;
int n, k;
std::vector<PII> q;
const int N = 1000;
int v[N + 2][N * 2 + 2];
int dp[N + 2];

void deal(int i, PII x, int cst, int val) {
	if (x.first == x.second && x.second == 1) {
		v[i][val + 1] = v[i][val + 2] = cst + 1;
		return ;
	}
	if (x.first > x.second) std::swap(x.first, x.second);
	v[i][val + 1] = cst + x.first;
	x.second--;
	deal(i, x, cst + x.first, val + 1);
}

void solve() {
	q.clear(), q.push_back({0, 0});
	std::cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		PII a;
		std::cin >> a.first >> a.second;
		if (a.first > a.second) std::swap(a.first, a.second);
		q.push_back(a);
		deal(i, a, 0, 0);
	}
	for (int i = 1; i <= k; i++) dp[i] = 1e9;
	dp[0] = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = k; j >= 1; j--) {
			for (int l = j - 1; l >= 0; l--) {
				if (j - l > q[i].first + q[i].second) break;
				dp[j] = std::min(dp[j], dp[l] + v[i][j - l]);
			}
		}
	}
	std::cout << (dp[k] == 1e9 ? -1 : dp[k]) << std::endl;
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