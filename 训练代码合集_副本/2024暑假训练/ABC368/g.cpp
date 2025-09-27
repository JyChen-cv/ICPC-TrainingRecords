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
int a[N + 2], b[N + 2];
int tr[N + 2], sa[N + 2];
int n;
int lowbit(int x) {
	return x & (-x);
}
void add(int p, int x, int *v) {
	while (p <= n) {
		v[p] += x;
		p += lowbit(p);
	}
}
int query(int p, int *v) {
	int res = 0;
	while (p) {
		res += v[p];
		p -= lowbit(p);
	}
	return res;
}
int sum(int l, int r, int *v) {
	if (l > r) std::swap(l, r);
	return query(r, v) - query(l - 1, v);
}
inline int deal(int l, int r) {
	while (l < r) {
		int mid = (l + r + 1) >> 1;
		if (sum(l, mid, tr) == (mid - l + 1)) l = mid;
		else r = mid - 1;
	}
	return r;
}

void solve() {
	std::cin >> n;
	for (int i = 1; i <= n; i++) {
		std::cin >> a[i];
		add(i, a[i], sa);
	}
	for (int i = 1; i <= n; i++) {
		std::cin >> b[i];
		if (b[i] <= 1) add(i, 1, tr);
	}
	int m;
	std::cin >> m;
	while (m--) {
		int op, aa, bb;
		std::cin >> op >> aa >> bb;
		if (op == 1) {
			add(aa, -a[aa], sa);
			add(aa, bb, sa);
			a[aa] = bb;
		}
		else if (op == 2) {
			int ls = sum(aa, aa, tr);
			if (bb == 1 && !ls) add(aa, 1, tr);
			if (bb != 1 && ls) add(aa, -1, tr);
			b[aa] = bb;
		}
		else {
			int res = 0;
			while (aa <= bb) {
				if (b[aa] == 1) {
					int ls = deal(aa, bb);
					res += sum(aa, ls, sa);
					aa = ls + 1;
				}
				else {
					res = std::max(res + a[aa], res * b[aa]);
					aa++;
				}
			}
			std::cout << res << std::endl;
		}
	}
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