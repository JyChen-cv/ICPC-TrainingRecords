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
const int N = 5000, M = 5000;
int head[N + 2], nxt[M * 2 + 2], ver[M * 2 + 2], edge[M * 2 + 2], tot;
int n, m, k, w[N + 2], d[N + 2], v[N + 2], ans[N + 2];

void add(int x, int y, int z = 0) {
	tot++;
	edge[tot] = z;
	ver[tot] = y;
	nxt[tot] = head[x];
	head[x] = tot;
}
void solve() {
	std::cin >> n >> m >> k;
	for (int i = 1; i <= n; i++) {
		std::cin >> w[i];
	}
	for (int i = 1; i <= m; i++) {
		int a, b, c;
		std::cin >> a >> b >> c;
		add(a, b, c), add(b, a, c);
	}
	for (int i = 1; i <= n; i++) {
		d[i] = 1e9;
	}
	std::priority_queue<PII> q;
	for (int i = 1; i <= n; i++) {
		d[w[i]] = 0, v[w[i]] = 1;
		q.push({0, w[i]});
	}
	while (q.size()) {
		PII t = q.top();
		int x = t.second, val = t.first;
		for (int i = head[x]; i; i = nxt[i]) {
			int y = ver[i];
			if (v[y]) continue;
		}
	}

	for (int i = 1; i <= n; i++) std::cout << ans[i] << " \n"[i == n];
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