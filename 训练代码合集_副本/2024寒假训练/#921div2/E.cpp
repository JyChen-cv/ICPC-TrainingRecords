#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <vector>
#include <set>

typedef long long ll;
const int N = 3e5;
struct node {
	int l, r;
	ll sum, add, mul;
} setr[N * 4 + 2];

ll v[N + 2];
int n, m, q, cs[N + 2];

void pushup(node &u, node &l, node &r) {
	u.sum = l.sum + r.sum;
}
void pushup(int u) {
	if (setr[u].l == setr[u].r) return ;
	pushup(setr[u], setr[u << 1], setr[u << 1 | 1]);
}

void eva(node &t, long long add, long long mul) {
	// 先 * 后 + 先算优先级高的
	// evaluation
	t.sum = t.sum * mul;
	t.sum = (t.sum + (long long)(t.r - t.l + 1) * add) ;
	t.mul = t.mul * mul ;
	t.add = t.add * mul + add;
}

void pushdown(node &u, node &l, node &r) {
	// 先 * 后 + 先算优先级高的
	// 注意：本层的一定是计算完成的
	eva(l, u.add, u.mul);
	eva(r, u.add, u.mul);
	u.add = 0;
	u.mul = 1;
}
void pushdown(int u) {
	if (setr[u].l == setr[u].r) return ;
	pushdown(setr[u], setr[u << 1], setr[u << 1 | 1]);
}

void build (int u, int l, int r) {
	if (l == r) {
		setr[u] = {l, r, 0, 0, 0};
	}
	else {
		setr[u] = {l, r, 0, 1};
		int mid = (l + r) >> 1;
		build(u << 1, l, mid);
		build(u << 1 | 1, mid + 1, r);
		pushup(u);
	}
}

node query(int u, int l, int r) {
	if (setr[u].l >= l && setr[u].r <= r) return setr[u];
	else {
		pushdown(u);
		int mid = (setr[u].l + setr[u].r) >> 1;
		if (l > mid) return query(u << 1 | 1, l, r);
		else if (r <= mid) return query(u << 1, l, r);
		else {
			node res, left = query(u << 1, l, r), right = query(u << 1 | 1, l, r); // 小心res没有初始值
			pushup(res, left, right);
			return res;
		}
	}
}

void modify(int u, int l, int r, long long add, long long mul) {
	if (setr[u].l >= l && setr[u].r <= r) {
		eva(setr[u], add, mul);
	}
	else {
		pushdown(u);
		int mid = (setr[u].l + setr[u].r) >> 1; // 有没有括号都行
		if (l <= mid) modify(u << 1, l, r, add, mul);
		if (r > mid) modify(u << 1 | 1, l, r, add, mul);
		pushup(u);
	}
}

int main()
{
	std::cin >> n >> m >> q;
	std::set<std::pair<int, int> > s;

	for (int i = 1; i <= m; i++) std::cin >> cs[i];
	for (int i = 1; i <= m; i++) std::cin >> v[i];
	for (int i = 1; i <= m; i++) {
		s.insert(std::make_pair(cs[i], v[i]));
	}


	build(1, 1, n);
	for (int i = 1; i <= q; i++) {
		int t, a, b;
		std::cin >> t >> a >> b;
		if (t == 1) {
			auto it = s.lower_bound(std::make_pair(a, 0));
			auto [x2, v2] = *it;
			auto [x1, v1] = *prev(it);
			modify(1, x1 + 1, a, -v1 * (x2 - a), 1);
			modify
			s.insert(std::make_pair(a, b));
		}
		else {
			std::cout << query(1, a, b).sum << std::endl;
		}
	}

	return 0;
}
