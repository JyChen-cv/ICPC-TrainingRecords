#include <algorithm>
#include <iostream>
#include <vector>

const int N = 2e5;
int nxt[N * 2 + 2], head[N + 2], ver[N * 2 + 2], tot;
int sz[N + 2], n, m;
std::vector<int> q;

void add(int x, int y) {
	tot++;
	ver[tot] = y;
	nxt[tot] = head[x];
	head[x] = tot;
}

void dfs(int x, int fa) {
	sz[x] = 1;
	for (int i = head[x]; i; i = nxt[i]) {
		int y = ver[i];
		if (y == fa) continue;
		dfs(y, x);
		sz[x] += sz[y];
	}
	if (sz[x] != n) q.push_back(sz[x] * (n - sz[x]));
}

void solve() {
	q.clear(); tot = 0;
	std::cin >> n >> m;
	for (int i = 1; i <= n; i++) head[i] = 0;
	for (int i = 1; i < n; i++) {
		int a, b; std::cin >> a >> b;
		add(a, b), add(b, a);
	}
	dfs(1, 0);
	std::sort(q.begin(), q.end(), [](const int a, const int b) {
		return a > b;
	});
	int ans = 0;
	for (int i = 0; i < (int)q.size(); i++) {
		if (i < m - 1) ans += q[i];
		else ans += q[i] * 2;
	}
	std::cout << ans << std::endl;
}

int main() {
	std::ios::sync_with_stdio(0);
	std::cin.tie(nullptr), std::cout.tie(nullptr);
	int times;
	std::cin >> times;
	while (times--) {
		solve();
	}
	return 0;
}