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
const int N = 3e5, M = 3e5;
int head[N + 2], nxt[M * 2 + 2], ver[M * 2 + 2], tot;
int n, m, w[N + 2], sz[N + 2], hson[N + 2], Hson, ans[N + 2], dep[N + 2];
int cnt1[N * 2 + 10], cnt2[N * 2 + 10], f[N + 2][30]; // 感觉f数组也很大，线段树合并也就比这个数组多了4倍？
std::vector<int> q1_plu[N + 2], q1_sub[N + 2], q2_plu[N + 2], q2_sub[N + 2];

void add_edge(int x, int y) {
	tot++;
	ver[tot] = y;
	nxt[tot] = head[x];
	head[x] = tot;
}

void dfs(int x, int fa) {
	dep[x] = dep[fa] + 1;
	f[x][0] = fa;
	for (int i = 1; i <= 20; i++) f[x][i] = f[f[x][i - 1]][i - 1];
	sz[x] = 1;
	for (int i = head[x]; i; i = nxt[i]) {
		int y = ver[i];
		if (y == fa) continue;
		dfs(y, x);
		sz[x] += sz[y];
		if (sz[y] > sz[hson[x]]) hson[x] = y;  // 不为0就是说明有重节点，就是说明不是叶子节点
	}
}
int lca(int x, int y) {
	if (dep[y] > dep[x]) std::swap(x, y);
	for (int i = 20; i >= 0; i--) {
		if (dep[f[x][i]] >= dep[y]) x = f[x][i];
	}
	if (x == y) return x;
	for (int i = 20; i >= 0; i--) {
		if (f[x][i] != f[y][i]) {
			x = f[x][i];
			y = f[y][i];
		}
	}
	return f[x][0];
}

inline int deal(int x) {
	return x + 3e5;
}
void calc(int x, int fa, int op) {
	if (op) {
		for (int i = 0; i < (int)q1_plu[x].size(); i++) {
			cnt1[q1_plu[x][i]]++;
		}
		for (int i = 0; i < (int)q1_sub[x].size(); i++) {
			cnt1[q1_sub[x][i]]--;
		}
		for (int i = 0; i < (int)q2_plu[x].size(); i++) {
			cnt2[deal(q2_plu[x][i])]++;
		}
		for (int i = 0; i < (int)q2_sub[x].size(); i++) {
			cnt2[deal(q2_sub[x][i])]--;
		}
	}
	else {
		for (int i = 0; i < (int)q1_plu[x].size(); i++) {
			cnt1[q1_plu[x][i]]--;
		}
		for (int i = 0; i < (int)q1_sub[x].size(); i++) {
			cnt1[q1_sub[x][i]]++;
		}
		for (int i = 0; i < (int)q2_plu[x].size(); i++) {
			cnt2[deal(q2_plu[x][i])]--;
		}
		for (int i = 0; i < (int)q2_sub[x].size(); i++) {
			cnt2[deal(q2_sub[x][i])]++;
		}
	}
	for (int i = head[x]; i; i = nxt[i]) {
		int y = ver[i];
		if (y == fa || y == Hson) continue;
		calc(y, x, op);
	}
}
void dsu(int x, int fa, int op) {
	for (int i = head[x]; i; i = nxt[i]) {
		int y = ver[i];
		if (y == fa || y == hson[x]) continue;
		dsu(y, x, 0);
	}
	if (hson[x]) {
		dsu(hson[x], x, 1), Hson = hson[x];
	}
	calc(x, fa, 1);
	ans[x] += cnt1[dep[x] + w[x]];
	// std::cout << x << " " << ans[x] << " ";
	ans[x] += cnt2[deal(w[x]) - dep[x]];
	// std::cout << ans[x] << std::endl;
	Hson = 0;
	if (!op) {
		calc(x, fa, 0);
	}
}

void solve() {
	// freopen("okok.in", "r", stdin);
	std::cin >> n >> m;
	for (int i = 1; i < n; i++) {
		int a, b;
		std::cin >> a >> b;
		add_edge(a, b), add_edge(b, a);
	}
	for (int i = 1; i <= n; i++) {
		std::cin >> w[i];
	}
	dfs(1, 0);
	for (int i = 1; i <= m; i++) {
		int s, e, c;
		std::cin >> s >> e; c = lca(s, e);
		// 这里有点问题，应该是再开一张图然后分别计算
		q1_plu[s].push_back(dep[s]), q2_plu[e].push_back(dep[s] - 2 * dep[c]);
		q1_sub[f[c][0]].push_back(dep[s]), q2_sub[c].push_back(dep[s] - 2 * dep[c]);
	}
	// for (int i = 1; i <= n; i++) {
	// 	std::cout << i << ": \n";
	// 	std::cout << 1 << " : ";
	// 	for (int j = 0; j < (int)q1_plu[i].size(); j++) {
	// 		std::cout << q1_plu[i][j] << " ";
	// 	}
	// 	std::cout << std::endl;
	// 	std::cout << 2 << " : ";
	// 	for (int j = 0; j < (int)q1_sub[i].size(); j++) {
	// 		std::cout << q1_sub[i][j] << " ";
	// 	}
	// 	std::cout << std::endl;
	// 	std::cout << 3 << " : ";
	// 	for (int j = 0; j < (int)q2_plu[i].size(); j++) {
	// 		std::cout << q2_plu[i][j] << " ";
	// 	}
	// 	std::cout << std::endl;
	// 	std::cout << 4 << " : ";
	// 	for (int j = 0; j < (int)q2_sub[i].size(); j++) {
	// 		std::cout << q2_sub[i][j] << " ";
	// 	}
	// 	std::cout << std::endl;
	// }
	dsu(1, 0, 0);
	for (int i = 1; i <= n; i++) {
		std::cout << ans[i] << " \n"[i == n];
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
