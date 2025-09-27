// 这是一个更新本层的写法，但是没有调出来，bk了

#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>

typedef long long ll;
const int N = 1e5;
int n, m, mod, mapp[N + 2];
struct group {
	int l, r;
	ll sum, mul, add;
} setr[N * 4 + 2];
void pushup(group &u, group &l, group &r) {
	u.sum = (l.sum + r.sum) % mod;
}
void pushup(int u) {
	pushup(setr[u], setr[u << 1], setr[u << 1 | 1]);
}
void build(int u, int l, int r) {
	if (l == r) {
		setr[u] = {l, l, mapp[l], 1, 0};
		return;
	}
	setr[u] = {l, r, 0, 1, 0};  // 这里必须得有初始值
	int mid = (l + r) >> 1;
	build(u << 1, l, mid), build(u << 1 | 1, mid + 1, r);
	pushup(u);
}

void eva(group &u) {
	// evaluation
	// if (u.l == 7 && u.r == 7) {
	// 	std::cout << u.sum << " ?" << u.add << " " << u.mul << std::endl;
	// }
	if (u.add == 0 && u.mul == 1) return ;
	u.sum = u.sum * u.mul % mod;
	u.sum = (u.sum + (u.r - u.l + 1) * u.add % mod) % mod;
	u.add = 0, u.mul = 1;
}
void pushdown(group &u, group &l, group &r) {
	// if (u.l == u.r) return ;
	l.mul = l.mul * u.mul % mod;
	l.add = (l.add * u.mul % mod + u.add) % mod;
	r.mul = r.mul * u.mul % mod;
	r.add = (r.add * u.mul % mod + u.add) % mod;
	if (u.l == 6 && u.r == 8) {
		std::cout << u.sum << " ?" << u.add << " " << u.mul << std::endl;
	}
	eva(u);
}
void pushdown(int u) {
	pushdown(setr[u], setr[u << 1], setr[u << 1 | 1]);
}
void modify(int u, int l, int r, ll add, ll mul) {
	pushdown(u);  // 这一步很重要
	if (setr[u].l >= l && setr[u].r <= r) {
		setr[u].mul = setr[u].mul * mul % mod;
		setr[u].add = (setr[u].add * mul % mod + add) % mod;
		pushdown(u);  // 必须对内容有实质性的改变，不然pushup就错了
		return ;
	}
	int mid = (setr[u].l + setr[u].r) >> 1;
	if (l <= mid) modify(u << 1, l, r, add, mul);
	if (r > mid) modify(u << 1 | 1, l, r, add, mul);
	pushup(u);
}
group query(int u, int l, int r) {
	std::cout <<  u << ": " << setr[u].sum << " " << setr[u].add << " " << setr[u].mul << std::endl;
	pushdown(u);
	if (setr[u].l >= l && setr[u].r <= r) return setr[u];
	int mid = (setr[u].l + setr[u].r) >> 1;
	if (l > mid) return query(u << 1 | 1, l, r);
	else if (r <= mid) return query(u << 1, l, r);
	else {
		group res, left = query(u << 1, l, r), right = query(u << 1 | 1, l, r);
		pushup(res, left, right);
		return res;
	}
	pushup(u);
}

int main() {
	std::ios::sync_with_stdio(0);
	std::cin.tie(0), std::cout.tie(0);
	std::cin >> n >> mod;
	for (int i = 1; i <= n; i++) {
		std::cin >> mapp[i];
		mapp[i] %= mod;
	}
	build(1, 1, n);
	std::cin >> m;
	for (int i = 1; i <= m; i++) {
		int op, t, g, c;
		std::cin >> op;
		if (op == 1) {
			std::cin >> t >> g >> c;
			modify(1, t, g, 0, c);
		}
		else if (op == 2) {
			std::cin >> t >> g >> c;
			modify(1, t, g, c, 1);
		}
		else {
			std::cin >> t >> g;
			std::cout << query(1, t, g).sum << std::endl;
		}
		// std::cout << setr[12].r << " " << setr[12].sum << " " << setr[12].add << " " << setr[12].mul << std::endl;
	}
	return 0;
}