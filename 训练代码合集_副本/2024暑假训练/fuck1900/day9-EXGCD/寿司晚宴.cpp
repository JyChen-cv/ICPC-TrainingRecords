// https://www.luogu.com.cn/problem/P2150

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

const int N = 30;
int v[N + 2];
std::vector<int> pri;
int dp[500][500], deal[N + 2];
int res[500][500];
void solve() {
	int n, mod;
	std::cin >> n >> mod;
	for (int i = 2; i <= n; i++) {
		for (int j = 0; j < (int)pri.size(); j++) {
			if (i % pri[j] == 0) deal[i] |= (1 << j);
		}
		// std::cout << deal[i] << std::endl;
	}
	dp[0][0] = 1;
	for (int i = 2; i <= n; i++) {
		memset(res, 0, sizeof(res));
		for (int j = 0; j < (1 << 8); j++) {
			for (int k = 0; k < (1 << 8); k++) {
				if ((k & deal[i]) == 0)
					(res[j | deal[i]][k] += dp[j][k]) %= mod;
				if ((j & deal[i]) == 0)
					(res[j][k | deal[i]] += dp[j][k]) %= mod;
			}
		}
		for (int j = 0; j < (1 << 10); j++) {
			for (int k = 0; k < (1 << 10); k++) {
				dp[j][k] += res[j][k];
			}
		}
	}
	int ans = 0;
	for (int i = 0; i < (1 << 10); i++) {
		for (int j = 0; j < (1 << 10); j++) {
			if (i & j) continue;
			(ans += dp[i][j]) %= mod;
		}
	}
	// for (int i = 0; i <= 5; i++) {
	// 	for (int j = 0; j <= 5; j++) {
	// 		std::cout << dp[i][j] << " \n"[j == 5];
	// 	}
	// }
	std::cout << ans << std::endl;
}

signed main() {
	std::ios::sync_with_stdio(0);
	std::cin.tie(0), std::cout.tie(0);

	for (int i = 2; i <= N; i++) {
		if (!v[i]) pri.push_back(i);
		for (int j = 2; j * i <= N; j++) v[i * j] = 1;
	}
	// for (auto i : pri) std::cout << i << std::endl;
	int times = 1;
	// std::cin >> times;
	while (times--) {
		solve();
	}
	return 0;
}