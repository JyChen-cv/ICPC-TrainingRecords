// https://codeforces.com/problemset/problem/1988/D
// 和没有上司的舞会很像，相当于重复log次没有上司的舞会，三次删完全部元素是肯定错误的，log次删除完全部元素才正确
// 难点：容易想错结论，正确结论不好证明，但是想一想又觉得肯定对。。。


// 其实就是可以在没有上司的舞会的基础上的一个拓展
// 没有上司的舞会 dp[i][0/1] 表示不选/选第i个节点时，以i为根的子树所能产生的最大价值
// 换一个角度理解，dp[i][0/1] 表示第 0/1 次选第i个节点时，以i为根的子树所能产生的最大价值

// dp[i][j(0~19)] 表示第j次选第i个节点时，以i为根的子树所能产生的最大贡献，由于没有其他的限制，那么转移就很显然了
// 然后用了一些实现技巧把时间复杂度从 log^2 压缩到了 log

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
const int N = 3e5, M = 3e5;
int head[N + 2], nxt[M * 2 + 2], ver[M * 2 + 2], edge[M * 2 + 2], tot;
int n, w[N + 2], dp[N + 2][25];

void add(int x, int y, int z = 0) {
	tot++;
	edge[tot] = z;
	ver[tot] = y;
	nxt[tot] = head[x];
	head[x] = tot;
}

void dfs(int x, int fa) {
	for (int i = 1; i <= 20; i++) dp[x][i] = w[x] * i;
	for (int i = head[x]; i; i = nxt[i]) {
		int y = ver[i];
		if (y == fa) continue;
		dfs(y, x);
		int mn1 = 2e18, mn2 = 2e18;
		for (int j = 1; j <= 20; j++) {
			if (dp[y][j] <= mn1) mn2 = mn1, mn1 = dp[y][j];
			else if (dp[y][j] < mn2) mn2 = dp[y][j];
		}
		for (int j = 1; j <= 20; j++) {
			if (mn1 == dp[y][j]) { // 排除父子都是在同时被选中
				dp[x][j] += mn2;
			}
			else dp[x][j] += mn1;
		}
	}
}

void solve() {
	std::cin >> n; tot = 0;
	for (int i = 1; i <= n; i++) head[i] = 0;
	for (int i = 1; i <= n; i++) {
		std::cin >> w[i];
	}
	for (int i = 1; i < n; i++) {
		int a, b;
		std::cin >> a >> b;
		add(a, b), add(b, a);
	}
	dfs(1, 0);
	int ans = 2e18;
	for (int i = 1; i <= 20; i++) ans = std::min(ans, dp[1][i]);
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