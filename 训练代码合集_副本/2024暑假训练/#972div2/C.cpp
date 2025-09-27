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

typedef long long ll;
typedef double db;
typedef std::pair<int, int> PII;
const int N = 1e3;
const char p[5] = {'n', 'a', 'r', 'e', 'k'};
char a[N + 2][N + 2];
int n, m, dp[N + 2][5];
struct node {
	int e, z;
	int tot;
} rem[N + 2][5];
void solve() {
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++) scanf("%s", a[i]);
	for (int i = 0; i <= n; i++)
		for (int j = 0; j < 5; j++) dp[i][j] = -1e9, rem[i][j] = {0, 0, 0};
	for (int i = 1; i <= n; i++) {
		// std::cout << i << std::endl;
		int tot = 0;
		for (int k = 0; k < m; k++)
			if (a[i][k] == 'n' || a[i][k] == 'a' || a[i][k] == 'r' || a[i][k] == 'e' || a[i][k] == 'k') tot++;
		for (int j = 0; j < 5; j++) {
			int nxt = j, v = 0;
			for (int k = 0; k < m; k++) {
				if (a[i][k] == p[nxt]) {
					(++nxt) %= 5;
					v++;
				}
			}
			rem[i][j] = {(v + j) % 5, (v + j) / 5, tot};
			// std::cout << j << ": " << (v % 5 + j) % 5 << " " << (v + j) / 5 << " " << tot << std::endl;
		}
	}

	// 表示0是完全匹配的，1要从p[0]开始匹配了
	int mx[5] = { 0, -(int)1e9, -(int)1e9, -(int)1e9, -(int)1e9};
	for (int i = 1; i <= n; i++) {
		for (int k = 0; k < 5; k++) {
			int nxt = rem[i][k].e, val = rem[i][k].z, tot = rem[i][k].tot;
			int res = mx[k] + val * 5 * 2 - tot;
			dp[i][nxt] = std::max(dp[i][nxt], res);
		}
		for (int k = 0; k < 5; k++) mx[k] = std::max(mx[k], dp[i][k]);
	}
	int ans = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j < 5; j++) {
			ans = std::max(ans, dp[i][j]);
		}
	}
	std::cout << ans << std::endl;
}

signed main() {
	// std::ios::sync_with_stdio(0);
	// std::cin.tie(0), std::cout.tie(0);
	int times = 1;
	std::cin >> times;
	while (times--) {
		solve();
	}
	return 0;
}