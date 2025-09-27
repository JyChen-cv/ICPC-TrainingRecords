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

const int N = 1e6 * 4;
struct node {
	int l, r;
} sgt[N + 2];
int mapp[N + 2];
struct trie {

} tri[N + 2];  // 这里要开大
void insert(int x) {

}

void pushup(node &p, node &l, node &r) {

}
void pushup(int p) {
	pushup(sgt[p], sgt[p << 1], sgt[p << 1 | 1]);
}

void eva(node &u, int x) {

}

void pushdown(node &p, node &l, node &r) {

}
void pushdown(int p) {
	pushdown(sgt[p], sgt[p << 1], sgt[p << 1 | 1]);
}

void build(int p, int l, int r) {
	if (l == r) {
		return ;
	}
	sgt[p].l = l, sgt[p].r = r;
	int mid = l + r >> 1;
	build(p << 1, l, mid), build(p << 1 | 1, mid + 1, r);
	pushup(p);
}

void solve() {
	int n, m;
	std::cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		std::cin >> mapp[i];
	}
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