// https://www.luogu.com.cn/problem/P2495
// 算法模版～虚树的二次排序+LCA实现

#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <vector>

#define int long long
const int N = 3e5;
int head[N + 2], nxt[N * 2 + 2], ver[N * 2 + 2], tot, edge[N * 2 + 2];
int fa[N + 2][30], dis[N + 2][30], dep[N + 2], dfn[N + 2], number, v[N + 2];
std::vector<std::pair<int, int>> tr[N + 2];

void add(int x, int y, int z) {
	tot++;
	ver[tot] = y;
	edge[tot] = z;
	nxt[tot] = head[x];
	head[x] = tot;
}

void dfs(int x) {
	dfn[x] = ++number;
	for (int i = 1; i <= 20; i++) fa[x][i] = fa[fa[x][i - 1]][i - 1];
	for (int i = 1; i <= 20; i++) dis[x][i] = std::min(dis[fa[x][i - 1]][i - 1], dis[x][i - 1]);
	for (int i = head[x]; i; i = nxt[i]) {
		int y = ver[i];
		int z = edge[i];
		if (fa[x][0] == y) continue;
		fa[y][0] = x;
		dep[y] = dep[x] + 1;
		dis[y][0] = z;
		dfs(y);
	}
}

int lca(int x, int y) {
	if (dep[x] < dep[y]) std::swap(x, y);
	for (int i = 20; i >= 0; i--) {
		if (dep[fa[x][i]] >= dep[y]) x = fa[x][i];
	}
	if (x == y) return x;
	for (int i = 20; i >= 0; i--) {
		if (fa[x][i] != fa[y][i]) x = fa[x][i], y = fa[y][i];
	}
	return fa[x][0];
}

bool cmp(int x, int y) {
	return dfn[x] < dfn[y];
}

int deal(int x) {
	int res = 0;
	for (int i = 0; i < (int)tr[x].size(); i++) {
		int y = tr[x][i].first;
		int z = tr[x][i].second;
		int ls = deal(y);
		if (v[y]) {
			res += z;
		} else {
			res += std::min(z, ls);
		}
	}
	// std::cout << x << ": " << res << std::endl;
	return res;
}

int getdis(int x, int anc) {
	int res = 1e16;
	for (int i = 20; i >= 0; i--) {
		while (dep[fa[x][i] >= dep[anc]]) {
			res = std::min(res, dis[x][i]);
			x = fa[x][i];
		}
	}
	return res;
}

signed main() {
	std::ios::sync_with_stdio(0);
	std::cin.tie(0);
	std::cout.tie(0);
	int n;
	std::cin >> n;
	for (int i = 1; i < n; i++) {
		int a, b, c;
		std::cin >> a >> b >> c;
		add(a, b, c);
		add(b, a, c);
	}
	dep[1] = 1;
	dfs(1);

	int m;
	std::cin >> m;
	for (int i = 1; i <= m; i++) {
		int k;
		std::cin >> k;
		std::vector<int> h, res;
		for (int j = 1; j <= k; j++) {
			int a;
			std::cin >> a;
			v[a] = 1;
			h.push_back(a);
		}
		std::sort(h.begin(), h.end(), cmp);  // 感觉这个不必要
		res.push_back(h[0]);
		res.push_back(1);
		for (int j = 1; j < (int)h.size(); j++) {
			res.push_back(lca(h[j - 1], h[j]));
			res.push_back(h[j]);
		}
		// 把所有的可能出现的点放在res数组里面排序，方便后续建树，这里是 Core Process
		std::sort(res.begin(), res.end(), cmp);
		res.erase(unique(res.begin(), res.end()), res.end());
		// for (auto j : res) {
		//     std::cout << j << std::endl;
		// }

		for (int j = 1; j < (int)res.size(); j++) {
			int ls = lca(res[j - 1], res[j]);
			tr[ls].push_back({res[j], getdis(res[j], ls)});
		}
		std::cout << deal(1) << std::endl;
		for (int j = 0; j < k; j++) v[h[j]] = 0;
		for (auto j : res) {
			tr[j].clear();  // 先暂时这么写，感觉不会出现res以外新的节点
		}
	}
	return 0;
}