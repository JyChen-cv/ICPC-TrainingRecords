#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <vector>
#include <queue>
#include <map>
#include <cstring>
#include <set>

#define int long long
typedef long long ll;
typedef double db;
typedef std::pair<int, int> PII;
const int N = 2e5;
int head[N + 2], e1[N * 2 + 2], e2[N * 2 + 2], ver[N * 2 + 2], nxt[N * 2 + 2], tot;
bool v[N + 2], vv[N + 2];
int d1[N + 2], d2[N + 2], d3[N + 2];
int n, m;
int t0, t1, t2;
void add(int x, int y, int z1, int z2) {
	tot++;
	e1[tot] = z1, e2[tot] = z2;
	ver[tot] = y;
	nxt[tot] = head[x];
	head[x] = tot;
}
void dijkstra(int p, int *d, int ini) {
	for (int i = 0; i <= n + 1; i++) {
		d[i] = 1e15;
		v[i] = 0;
	}
	std::priority_queue<PII> q;
	d[1] = ini;
	q.push({ini, 1});
	while (q.size()) {
		int x = q.top().second; q.pop();
		if (v[x]) continue;
		v[x] = 1;
		for (int i = head[x]; i; i = nxt[i]) {
			int y = ver[i], z = e1[i];
			if (!(d[x] <= t1 && d[x] + z <= t1) && !(d[x] >= t2)) z = e2[i];
			if (d[x] <= t2) z = std::min(z, e1[i] + t2 - d[x]);
			if (d[y] > d[x] + z) {
				d[y] = d[x] + z;
				q.push({ -d[y], y});
			}
		}
	}
}
void solve() {
	std::cin >> n >> m;
	tot = 0;
	for (int i = 1; i <= n; i++) {
		head[i] = 0;
	}
	std::cin >> t0 >> t1 >> t2;
	for (int i = 1; i <= m; i++) {
		int a, b, c, d;
		std::cin >> a >> b >> c >> d;
		add(a, b, c, d), add(b, a, c, d);
	}
	int l = -1, r = t0;
	while (l < r) {
		int mid = (l + r + 1) >> 1;
		dijkstra(1, d1, mid);
		if (d1[n] <= t0) l = mid;
		else r = mid - 1;
	}
	std::cout << l << std::endl;
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