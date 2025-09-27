// 同一时刻只能查看一个边的负载
// 这样就可以转化成，一个边只是出现在从第一次出现到最后除了第i时刻！
// 这样最多划分出来的区间也不会太多

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <utility>
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

const int N = 1e5;
struct group {
	int l, r;
	std::vector<PII> q;  // 修改1
} sgt[N * 4 + 2];

int fa[N + 2], sz[N + 2];
std::vector<int> ans;
PII que[N + 5];
std::map<PII, int> lis;
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
	sz[x] += sz[y], fa[y] = x;
}
void roll(int h) {
	while (his_fa.size() > h) {
		sz[his_sz.back().first] = his_sz.back().second;
		fa[his_fa.back().first] = his_fa.back().second;
		his_sz.pop_back(), his_fa.pop_back();
	}
}

void build(int u, int l, int r) {
	if (l == r) {
		sgt[u] = {l, r};  // 修改3
		return ;
	}
	sgt[u] = {l, r};
	int mid = (l + r) >> 1;
	build(u << 1, l, mid), build(u << 1 | 1, mid + 1, r);
}

void deal(int u, PII x, int l, int r) {
	// std::cout << u << std::endl;
	if (l > r) return ;
	if (sgt[u].l >= l && sgt[u].r <= r) {
		sgt[u].q.push_back(x);
		return ;
	}
	int mid = (sgt[u].l + sgt[u].r) >> 1;
	if (l <= mid) deal(u << 1, x, l, r);
	if (r > mid) deal(u << 1 | 1, x, l, r);
}
void dfs(int u) {
	int rem = his_fa.size();
	for (auto i : sgt[u].q) {
		unn(i.first, i.second);
	}

	if (sgt[u].l == sgt[u].r) {
		PII ls = que[sgt[u].l];  // 这里还需要注意每次solve初始化
		if (ls.first != 0) {
			int sz1 = sz[find(ls.first)], sz2 = sz[find(ls.second)];
			ans.push_back(sz1 * sz2);
		}
		roll(rem);
		return ;
	}
	int mid = sgt[u].l + sgt[u].r >> 1;
	dfs(u << 1), dfs(u << 1 | 1);
	roll(rem);
}

void solve() {
	int n, m;
	std::cin >> n >> m;
	ans.clear(); lis.clear();
	for (int i = 1; i <= n; i++) fa[i] = i, sz[i] = 1;
	for (int i = 1; i <= m; i++) que[i] = {0, 0};
	std::vector<PII> q;
	std::vector<std::vector<int> > itv;
	for (int i = 1; i <= m; i++) {
		char op; int a, b;
		std::cin >> op >> a >> b;
		if (a > b) std::swap(a, b);
		if (op == 'A') {
			q.push_back({a, b});
			lis[ {a, b}] = q.size() - 1;
			std::vector<int> j; j.push_back(i - 1);
			itv.push_back(j);
		}
		else {
			int pos = lis[ {a, b}];
			// std::cout << i << " 's question :" << pos << std::endl;
			que[i] = {a, b};
			itv[pos].push_back(i);
		}
	}
	build(1, 1, m);
	for (int i = 0; i < (int)q.size(); i++) {
		itv[i].push_back(m + 1);
		for (int j = 1; j < (int)itv[i].size(); j++) {
			deal(1, q[i], itv[i][j - 1] + 1, itv[i][j] - 1); // 要防止前面比后面大
		}
	}
	dfs(1);
	// std::cout << ans.size() << std::endl;
	for (auto i : ans) std::cout << i << std::endl;
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