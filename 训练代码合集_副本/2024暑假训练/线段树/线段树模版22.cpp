#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>

const int N = 1e5;
typedef long long ll;
struct group {
	int l, r;
	ll add, mul, sum;
} setr[N * 4 + 2];
ll mapp[N + 2], mod;
int n, m;

void pushup(group &u, group &l, group &r) {
	u.sum = (l.sum + r.sum) % mod;
}
void pushup(int u) {
	if (setr[u].l == setr[u].r) return ;
	pushup(setr[u], setr[u << 1], setr[u << 1 | 1]);
}
void eva(group &u, ll add, ll mul) {
	// 先 * 后 + 先算优先级高的
	// evaluation
	u.sum = u.sum * mul % mod;
	u.sum = (u.sum + (u.r - u.l + 1) * add % mod) % mod;
	u.mul = u.mul * mul % mod;
	u.add = (u.add * mul % mod + add) % mod;
}

void pushdown(group &u, group &l, group &r) {
	// 注意：本层的一定是计算完成的，懒标记标记的是下一层的值的改变情况
	eva(l, u.add, u.mul), eva(r, u.add, u.mul);
	u.add = 0, u.mul = 1;
}
void pushdown(int u) {
	pushdown(setr[u], setr[u << 1], setr[u << 1 | 1]);
}

void build(int u, int l, int r) {
	if (l == r) {
		setr[u] = {l, l, 0, 1, mapp[l]};
		return ;
	}
	setr[u] = {l, r, 0, 1};  // 一定小心mul没有初始值的情况
	int mid = (l + r) >> 1;
	build(u << 1, l, mid), build(u << 1 | 1, mid + 1, r);
	pushup(u);
}

void modify(int u, int l, int r, ll add, ll mul) {
	if (setr[u].l >= l && setr[u].r <= r) {
		eva(setr[u], add, mul);
		return ;
	}
	pushdown(u);  // 请及时pushdown
	int mid = (setr[u].l + setr[u].r) >> 1;
	if (l <= mid) modify(u << 1, l, r, add, mul);
	if (r > mid) modify(u << 1 | 1, l, r, add, mul);
	pushup(u);
}

group query(int u, int l, int r) {
	if (setr[u].l >= l && setr[u].r <= r) return setr[u];
	pushdown(u);  // 请及时pushdown
	int mid = (setr[u].l + setr[u].r) >> 1;
	if (l > mid) return query(u << 1 | 1, l, r);
	else if (r <= mid) return query(u << 1, l, r);
	else {
		group res, left = query(u << 1, l, r), right = query(u << 1 | 1, l, r);
		pushup(res, left, right);
		return res;
	}
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
	}
	return 0;
}