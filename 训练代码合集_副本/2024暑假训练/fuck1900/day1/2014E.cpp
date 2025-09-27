// https://codeforces.com/problemset/problem/2014/E

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
const int N = 2e5 * 2, M = 3e5 * 2;  // 这里m应该是开3倍空间啊
int n, m, h;
int tag[N + 2];
int head[N + 2], nxt[M * 2 + 2], ver[M * 2 + 2], edge[M * 2 + 2], tot;

int d1[N + 2], d2[N + 2], v[N + 2];
void dijkstra(int p, int n, int d[]) {
	std::priority_queue<PII> q;
	for (int i = 1; i <= n; i++) {
		d[i] = 1e18; v[i] = 0;
	}
	d[p] = 0;
	q.push({0, p});
	while (q.size()) {
		int x = q.top().second; q.pop();
		if (v[x]) continue;
		v[x] = 1;
		for (int i = head[x]; i; i = nxt[i]) {
			// std::cout << i << " " << nxt[i] << std::endl;
			int y = ver[i], z = edge[i];
			if (d[y] > d[x] + z) {
				d[y] = d[x] + z;
				q.push({ -d[y], y});
			}
		}
	}
}


void add(int x, int y, int z = 0) {
	tot++;
	edge[tot] = z;
	ver[tot] = y;
	nxt[tot] = head[x];
	head[x] = tot;
}

void solve() {
	tot = 0;
	std::cin >> n >> m >> h;
	for (int i = 1; i <= n * 2; i++) head[i] = 0;
	for (int i = 1; i <= n * 2; i++) tag[i] = 0;
	for (int i = 1; i <= h; i++) {
		int a;
		std::cin >> a;
		tag[a] = h;
	}
	for (int i = 1; i <= n; i++) {
		if (tag[i]) add(i, i + n, 0);
	}
	for (int i = 1; i <= m; i++) {
		int a, b, w;
		std::cin >> a >> b >> w;
		add(a, b, w), add(b, a, w);
		add(a + n, b + n, w / 2), add(b + n, a + n, w / 2);
	}
	dijkstra(1, n * 2, d1); dijkstra(n, n * 2, d2);

	int ans = 1e18;
	for (int i = 1; i <= n; i++) {
		int d_1 = std::min(d1[i], d1[i + n]);
		int d_2 = std::min(d2[i], d2[i + n]);
		ans = std::min(ans, std::max(d_1, d_2));
	}
	if (ans == 1e18) std::cout << -1 << std::endl;
	else std::cout << ans << std::endl;
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