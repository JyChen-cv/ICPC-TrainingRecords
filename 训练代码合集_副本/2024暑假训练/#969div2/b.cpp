#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>

const int N = 1e5;
typedef long long ll;
struct group {
	int l, r;
	ll add, mul, mx;
} setr[N * 4 + 2];
ll mapp[N + 2], mod = 1e18;
int n, m;

void pushup(group &u, group &l, group &r) {
	u.mx = std::max(l.mx, r.mx);
}
void pushup(int u) {
	if (setr[u].l == setr[u].r) return ;
	pushup(setr[u], setr[u << 1], setr[u << 1 | 1]);
}
void eva(group &u, ll add, ll mul) {
	// 先 * 后 + 先算优先级高的
	// evaluation
	u.mx = u.mx + add;
	u.add += add;
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
	// std::cout << u << " " << add << std::endl;
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
	// std::cout << setr[u].l << " " << setr[u].r << " " << setr[u].mx << std::endl;
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
	int times;
	std::cin >> times;
	while (times--) {
		std::cin >> n >> m;
		for (int i = 1; i <= n; i++) {
			std::cin >> mapp[i];
		}
		for (int i = 1; i <= n * 4; i++) {
			setr[i].add = setr[i].l = setr[i].r = setr[i].mx = 0;
		}
		build(1, 1, n);
		for (int i = 1; i <= m; i++) {
			// std::cout << 1 << std::endl;
			char op;
			int t, g, c;
			std::cin >> op;
			std::cin >> t >> g;
			if (t <= n) {
				g = std::min(g, n), t = std::min(t, n);
				if (op == '+') {
					modify(1, t, g, 1, 1);
				}
				else {
					modify(1, t, g, -1, 1);
				}
			}
			std::cout << query(1, 1, n).mx << " \n"[i == m];
		}
	}
	return 0;
}