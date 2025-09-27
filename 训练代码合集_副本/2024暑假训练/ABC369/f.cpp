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
const int N = 2e5;
int n, m, k, rem[N + 2];
PII point[N + 2];
struct node {
	int l, r;
	int v, num;
} setr[N * 4 + 2];

void pushup(node &u, node &l, node &r) {
	if (l.v >= r.v) {
		u.v = l.v;
		u.num = l.num;
	}
	else {
		u.v = r.v;
		u.num = r.num;
	}
}
void pushup(int u) {
	pushup(setr[u], setr[u << 1], setr[u << 1 | 1]);
}

void build(int u, int l, int r) {
	setr[u] = {l, r};
	if (l == r) {
		return ;
	}
	int mid = (l + r) / 2;
	build(u << 1, l, mid);
	build(u << 1 | 1, mid + 1, r);
	pushup(u);
}
node query(int u, int l, int r) {
	if (l > r) {return {0, 0, 0};}  // 回答非法询问
	if (setr[u].l >= l && setr[u].r <= r) return setr[u];
	int mid = (setr[u].l + setr[u].r) >> 1;
	if (r <= mid) return query(u << 1, l, r);
	else if (l > mid) return query(u << 1 | 1, l, r);
	else {
		node res, left = query(u << 1, l, r), right = query(u << 1 | 1, l, r);
		pushup(res, left, right);
		return res;
	}
}
void modify(int u, int x, int v, int nv) {
	if (setr[u].l == x && setr[u].r == x) {
		setr[u].v = v;
		setr[u].num = nv;
	}
	else {
		int mid = (setr[u].l + setr[u].r) / 2;
		if (x <= mid) modify(u << 1, x, v, nv);
		else modify(u << 1 | 1, x, v, nv);
		pushup(u);
	}
}
void dfs(int x) {
	// std::cout << x << std::endl;
	if (rem[x] == 0) {
		int l1 = point[x].first - 1;
		int l2 = point[x].second - 1;
		for (int i = 1; i <= l1; i++) std::cout << 'D';
		for (int i = 1; i <= l2; i++) std::cout << "R";
		return ;
	}

	int d = rem[x];
	dfs(d);
	int l1 = point[x].first - point[d].first;
	int l2 = point[x].second - point[d].second;
	for (int i = 1; i <= l1; i++) std::cout << 'D';
	for (int i = 1; i <= l2; i++) std::cout << "R";

}
void solve() {
	std::cin >> n >> m >> k;
	for (int i = 1; i <= k; i++) {
		std::cin >> point[i].first >> point[i].second;
	}
	std::sort(point + 1, point + k + 1);
	if (point[k].first != n || point[k].second != m) {
		k++;
		point[k] = {n, m};
	}

	build(1, 1, m);
	node ls;
	for (int i = 1; i <= k; i++) {
		ls = query(1, 1, point[i].second);
		rem[i] = ls.num;
		modify(1, point[i].second, ls.v + 1, i);
	}
	std::cout << ls.v << std::endl;  // 题目保证了不会有（n,m）节点，所以ls+1才是最后的值，这里相当于就是答案！
	dfs(k);
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