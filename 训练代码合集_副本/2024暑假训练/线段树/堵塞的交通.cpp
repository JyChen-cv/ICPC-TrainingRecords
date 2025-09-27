// con数组表示的是i和i+1之间的连通性
// 线段树l,r表示的是l到r的连通性
// 这两个数组的细节表示是不同的，具体的，con像是表示的第一个间隔，线段树像是表示的第一个点

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <vector>
#include <queue>
#include <map>
#include <cstring>
#include <set>

typedef long long ll;
typedef double db;
const int N = 1e5;
struct node {
	int lft, rig;  // 左右端点
	int l, r, u, d, p, q;
} seg[N * 4 + 2];
int n;
bool con[N + 2][2]; // 表示当前位置i和i+1的连通性，本题线段树的建图数组,0表示上层，1表示下层
void pushup(node &u, node l, node r) {
	// u.lft=l.lft,u.rig=r.rig;
	u.l = l.l | (l.u & con[l.rig][0] & r.l & con[l.rig][1] & l.d);
	u.r = r.r | (r.u & con[l.rig][0] & l.r & con[r.rig][1] & r.d);
	u.u = (l.u & con[l.rig][0] & r.u) | (l.p & con[l.rig][1] & r.q);
	u.d = (l.d & con[l.rig][1] & r.d) | (l.q & con[l.rig][0] & r.p);
	u.p = (l.u & con[l.rig][0] & r.p) | (l.p & con[l.rig][1] & r.d);
	u.q = (l.d & con[l.rig][1] & r.q) | (l.q & con[l.rig][0] & r.u);
}
void pushup(int u) {
	pushup(seg[u], seg[u << 1], seg[u << 1 | 1]);
}
void build(int u, int l, int r) {
	if (l == r) {
		seg[u].lft = seg[u].rig = l;
		seg[u].u = seg[u].d = 1;
		return;
	}
	seg[u] = {l, r};
	int mid = (l + r) >> 1;
	build(u << 1, l, mid), build(u << 1 | 1, mid + 1, r);
	pushup(u);
}
void modify1(int u, int p, int lin, int sta) {
	int mid = (seg[u].lft + seg[u].rig) >> 1;
	if (mid == p) {
		con[mid][lin] = sta;
		pushup(u);
		return ;
	}
	if (p <= mid) modify1(u << 1, p, lin, sta);
	else modify1(u << 1 | 1, p, lin, sta);
	pushup(u);
}
void modify2(int u, int p, int sta) {
	if (seg[u].lft == seg[u].rig) {
		seg[u].l = seg[u].r = seg[u].q = seg[u].p = sta;
		return ;
	}
	int mid = (seg[u].lft + seg[u].rig) >> 1;
	if (p <= mid) modify2(u << 1, p, sta);
	else modify2(u << 1 | 1, p, sta);
	pushup(u);
}
node query(int u, int l, int r) {
	if (seg[u].lft >= l && seg[u].rig <= r) return seg[u];
	int mid = (seg[u].lft + seg[u].rig) >> 1;
	if (r <= mid) return query(u << 1, l, r);
	else if (l > mid) return query(u << 1 | 1, l, r);
	else {
		node res;
		pushup(res, query(u << 1, l, r), query(u << 1 | 1, l, r));
		return res;
	}
}
void solve() {
	std::cin >> n;
	build(1, 1, n);
	while (1) {
		std::string op;
		std::cin >> op;
		if (op[0] == 'E') break;
		int a, b, c, d;
		std::cin >> a >> b >> c >> d;
		if (op[0] == 'C') {
			if (a == c) modify1(1, std::min(b, d), a - 1, 0);
			else modify2(1, b, 0);
		}
		else if (op[0] == 'O') {
			if (a == c) modify1(1, std::min(b, d), a - 1, 1);
			else modify2(1, b, 1);
		}
		else {
			if (b > d) std::swap(a, c), std::swap(b, d);
			node ans1 = query(1, b, d), ans2 = query(1, 1, b), ans3 = query(1, d, n);
			bool flag = false;
			if (a == 1) {
				if (c == 1) {
					if (ans1.u) flag = 1;
					if (ans2.r & ans1.d & ans3.l) flag = 1;
				}
				else {
					if (ans1.p) flag = 1;
					if (ans2.r & ans1.d) flag = 1;
					if (ans3.l & ans1.u) flag = 1;
				}
			}
			else {
				if (c == 1) {
					if (ans1.q) flag = 1;
					if (ans2.r & ans1.u) flag = 1;
					if (ans3.l & ans1.d) flag = 1;
				}
				else {
					if (ans1.d) flag = 1;
					if (ans2.r & ans1.u & ans3.l) flag = 1;
				}
			}
			puts(flag ? "Y" : "N");
		}
	}
}

int main() {
	int times = 1;
	// std::cin >> times;
	while (times--) {
		solve();
	}
	return 0;
}