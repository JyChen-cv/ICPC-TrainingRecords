#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <vector>

const int N = 5e5;
struct group {
	int l, r;
	int sum, ls, rs, mx;
} setr[N * 4 + 2];
int mapp[N + 2];

void pushup(group &u, group &l, group &r) {
	u.sum = l.sum + r.sum;
	u.ls = std::max(l.ls, r.ls + l.sum);
	u.rs = std::max(r.rs, l.rs + r.sum);
	u.mx = std::max(std::max(l.mx, r.mx), l.rs + r.ls);
}
void pushup(int u) {
	pushup(setr[u], setr[u << 1], setr[u << 1 | 1]);
}
void build(int u, int l, int r) {
	if (l == r) {
		setr[u] = {l, r, mapp[l], mapp[l], mapp[l], mapp[l]};
		return ;
	}
	setr[u] = {l, r};
	int mid = (l + r) >> 1;
	build(u << 1, l, mid), build(u << 1 | 1, mid + 1, r);
	pushup(u);
}

void modify(int u, int x, int v) {
	if (setr[u].l == x && setr[u].r == x) {
		setr[u] = {x, x, v, v, v, v};
		mapp[x] = v;
		return ;
	}
	int mid = (setr[u].l + setr[u].r) >> 1;
	if (x <= mid) modify(u << 1, x, v);
	else modify(u << 1 | 1, x, v);
	pushup(u);
}
group query(int u, int l, int r) {
	if (setr[u].l >= l && setr[u].r <= r) return setr[u];
	int mid = (setr[u].l + setr[u].r) >> 1;
	if (r <= mid) return query(u << 1, l, r);
	else if (l > mid) return query(u << 1 | 1, l, r);
	else {
		group res, left = query(u << 1, l, r), right = query(u << 1 | 1, l, r);
		pushup(res, left, right);
		return res;
	}
}

int main() {
	std::ios::sync_with_stdio(0);
	std::cin.tie(0), std::cout.tie(0);
	int n, m;
	std::cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		std::cin >> mapp[i];
	}
	build(1, 1, n);
	for (int i = 1; i <= m; i++) {
		int op, a, b;
		std::cin >> op >> a >> b;
		if (op == 1) {
			if (a > b)std::swap(a, b);
			std::cout << query(1, a, b).mx << std::endl;
		}
		else {
			modify(1, a, b);
		}
	}
	return 0;
}