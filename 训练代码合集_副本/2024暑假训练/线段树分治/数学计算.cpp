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

const int N = 1e5;
int mod, n, ans[N + 2];
struct group {
	int l, r;
	std::vector<int> q;
} sgt[N * 4 + 2];
void build(int u, int l, int r) {
	if (l == r) {
		sgt[u] = {l, r};  // 修改3
		return ;
	}
	sgt[u] = {l, r};
	int mid = (l + r) >> 1;
	build(u << 1, l, mid), build(u << 1 | 1, mid + 1, r);
}

void deal(int u, int x, int l, int r) {
	if (sgt[u].l >= l && sgt[u].r <= r) {
		sgt[u].q.push_back(x);
		return;
	}
	int mid = (sgt[u].l + sgt[u].r) >> 1;
	if (l <= mid) deal(u << 1, x, l, r);
	if (r > mid) deal(u << 1 | 1, x, l, r);
}

void dfs(int u, int res) {
	for (auto i : sgt[u].q) {
		(res *= i) %= mod;
	}
	if (sgt[u].l == sgt[u].r) {
		ans[sgt[u].l] = res;
		return ;
	}
	dfs(u << 1, res), dfs(u << 1 | 1, res);
}

void solve() {
	std::cin >> n >> mod;
	std::vector<int> nm(n + 2);
	std::vector<PII> inter(n + 2);
	for (int i = 1; i <= n; i++) {
		int op, x;
		std::cin >> op >> x;
		if (op == 1) {
			nm[i] = x;
			inter[i] = {i, n};
		}
		else {
			inter[x].second = i - 1;
		}
	}

	build(1, 1, n);
	for (int i = 0; i <= n; i++) {
		if (!nm[i]) continue;
		// std::cout << i << " " << nm[i] << " " << inter[i].first << " " << inter[i].second << std::endl;
		deal(1, nm[i], inter[i].first, inter[i].second);
	}
	dfs(1, 1);
	for (int i = 1; i <= n; i++) std::cout << ans[i] << std::endl;
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