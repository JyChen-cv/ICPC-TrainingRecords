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
#include <bitset>

#define int long long
typedef long long ll;
typedef double db;
typedef std::pair<int, int> PII;

const int N = 5e5;
struct group {
	int l, r;
	int ;  // 修改1
} sgt[N * 4 + 2];

void pushup(group &u, group &l, group &r) {
	// 修改2

}
void pushup(int u) {
	pushup(sgt[u], sgt[u << 1], sgt[u << 1 | 1]);
}
void build(int u, int l, int r) {
	if (l == r) {
		sgt[u] = {l, r, };  // 修改3
		return ;
	}
	sgt[u] = {l, r};
	int mid = (l + r) >> 1;
	build(u << 1, l, mid), build(u << 1 | 1, mid + 1, r);
	pushup(u);
}

void modify(int u, int x, int v) {
	if (sgt[u].l == x && sgt[u].r == x) {
		sgt[u] = {x, x, };  // 修改4
		mapp[x] = v;
		return ;
	}
	int mid = (sgt[u].l + sgt[u].r) >> 1;
	if (x <= mid) modify(u << 1, x, v);
	else modify(u << 1 | 1, x, v);
	pushup(u);
}
group query(int u, int l, int r) {
	if (l > r) {return {0, 0, 0};}  // 回答非法询问
	if (sgt[u].l >= l && sgt[u].r <= r) return sgt[u];
	int mid = (sgt[u].l + sgt[u].r) >> 1;
	if (r <= mid) return query(u << 1, l, r);
	else if (l > mid) return query(u << 1 | 1, l, r);
	else {
		group res, left = query(u << 1, l, r), right = query(u << 1 | 1, l, r);
		pushup(res, left, right);
		return res;
	}
}
void solve() {

}

signed main() {
	std::ios::sync_with_stdio(0);
	std::cin.tie(0), std::cout.tie(0);
	int times = 1;
	std::cin >> times;
	while (times--) {
		solve();
	}
	return 0;
}