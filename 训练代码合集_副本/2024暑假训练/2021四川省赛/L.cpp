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

// #define int long long
// typedef long long ll;
// typedef double db;
typedef std::pair<int, int> PII;
int n, m, k;
const int N = 5e5, M = 5e5;
int head[N + 2], nxt[M * 2 + 2], ver[M * 2 + 2], tot;
int p[N + 2], dp[N + 2][102], v[N + 2];
void add(int x, int y) {
	tot++;
	ver[tot] = y;
	nxt[tot] = head[x];
	head[x] = tot;
}
void solve() {
	std::cin >> n >> m >> k;
	for (int i = 1; i <= n; i++) {
		std::cin >> p[i];
	}
	for (int i = 1; i <= m; i++) {
		int a, b;
		std::cin >> a >> b;
		add(a, b), add(b, a);
	}
	memset(dp, 0x3f, sizeof dp);  // dp[i][j] 表示到i点辣度<=j的最近点的距离
	for (int i = 1; i <= 100; i++) {
		std::queue<int> q;
		memset(v, 0, sizeof v);
		for (int j = 1; j <= n; j++)
			if (p[j] <= i) {
				q.push(j);
				dp[j][i] = std::min(dp[j][i], 0);
				v[j] = 1;
			}

		while (q.size()) {
			int x = q.front();
			q.pop();
			for (int j = head[x]; j; j = nxt[j]) {
				int y = ver[j];
				if (v[y]) continue;
				else {
					dp[y][i] = std:: min(dp[y][i], dp[x][i] + 1);
					q.push(y);
					v[y] = 1;
				}
			}
		}
	}

	for (int i = 1; i <= k; i++) {
		int a, b;
		std::cin >> a >> b;
		std::cout << (dp[a][b] == 0x3f3f3f3f ? -1 : dp[a][b]) << std::endl;
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