#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <utility>
#include <vector>
#include <queue>
#include <map>
#include <cstring>
#include <set>

#define int long long
typedef long long ll;
typedef double db;
const int N = 6e5;
struct group {
	int x, y;
} e[N + 2];
struct node {
	int l, r;
	std::vector<int> q;
} setr[N * 4 + 2];
int fa[N + 2], sz[N + 2], n, m, ans[N + 2];
std::vector<std::pair<int, int>> his_fa, his_sz;

int find(int x) {
	if (x == fa[x]) return x;
	else return find(fa[x]);
}
void unn(int x, int y) {
	x = find(x), y = find(y);
	if (x == y) return ;
	if (sz[x] < sz[y]) std::swap(x, y);
	his_sz.push_back({x, sz[x]});
	his_fa.push_back({y, fa[y]});
	ans[y] -= ans[x];  // 这里x已经是祖先了
	sz[x] += sz[y], fa[y] = x;
	// x是大的，y是小的
}
void roll(int h) {
	while (his_fa.size() > h) {
		sz[his_sz.back().first] = his_sz.back().second;
		fa[his_fa.back().first] = his_fa.back().second;
		int x = his_sz.back().first, y = his_fa.back().first;
		ans[y] += ans[find(x)];
		his_sz.pop_back(), his_fa.pop_back();
	}
}

void build(int u, int l, int r) {
	if (l == r) {
		setr[u] = {l, r};
		return ;
	}
	setr[u] = {l, r};
	int mid = (l + r) >> 1;
	build(u << 1, l, mid), build(u << 1 | 1, mid + 1, r);
}
void deal(int u, int p, int l, int r) {
	if (setr[u].l >= l && setr[u].r <= r) {
		setr[u].q.push_back(p);
		return ;
	}
	int mid = (setr[u].l + setr[u].r) >> 1;
	if (l <= mid) deal(u << 1, p, l, r);
	if (r > mid) deal(u << 1 | 1, p, l, r);
}
void dfs(int u) {
	int h = his_sz.size();
	for (auto i : setr[u].q) {
		unn(e[i].x, e[i].y);
	}
	if (setr[u].l != setr[u].r) // 非叶子结点
		dfs(u << 1), dfs(u << 1 | 1);
	else {
		// ???
		ans[find(1)] += setr[u].l;
	}
	roll(h);  // 回滚到原来的状态
}
void solve() {
	std::cin >> n >> m;
	build(1, 1, n);
	for (int i = 1; i <= n; i++) {
		sz[i] = 1, fa[i] = i;
	}
	for (int i = 1; i <= m; i++) {
		int a, b, c, d;
		std::cin >> a >> b >> c >> d;
		// c++;
		e[i] = {a, b};
		deal(1, i, c, d);
	}
	dfs(1);
	int answer = 0;
	for (int i = 1; i <= n; i++) {
		// std::cout << ans[i] << std::endl;
		answer ^= ans[i];
	}
	std::cout << answer << std::endl;
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

/*

4 5
1 3 2 4
2 1 3 4
4 3 1 3
2 4 2 2
4 3 3 3

*/