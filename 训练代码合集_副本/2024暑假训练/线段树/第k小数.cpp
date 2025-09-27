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
typedef std::pair<int, int> PII;
const int N = 2e6, M = 1e4;  // 开nlogn个节点
struct node {
	int ls, rs;
	int cnt;
} seg[N + 2];
int n, m, mapp[N + 2], tot, root[M + 2];

int insert(int u, int l, int r, int p ?, int v) {
	int p = ++tot;
}
void solve() {
	std::cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		std::cin >> mapp[i];
	}
	for (int i = 1; i <= n; i++) {

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