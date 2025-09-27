#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <utility>
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

const int N = 3e5, M = 1e6 * 2;
int head[N + 2], nxt[M * 2 + 2], ver[M * 2 + 2], edge[M * 2 + 2], tot;
int n, m;
void add(int x, int y, int z = 0) {
	tot++;
	edge[tot] = z;
	ver[tot] = y;
	nxt[tot] = head[x];
	head[x] = tot;
}

inline std::pair<int, int> upd(std::pair<int, int> p, int x) {
	if (p.second == 1e18) p.second = 0;
	if (x >= p.first) p.second = p.first, p.first = x;
	else if (x > p.second) p.second = x;
	return p;
}

// bool cmp_less(std::pair<int, int> p1, std::pair<int, int> p2) {
// 	if (p1.first + p1.second == p2.first + p2.second) return 1;
// 	else return p1.first + p1.second < p2.first + p2.second;
// }

std::pair<int, int> d1[N + 2], d2[N + 2];
int v[N + 2];
void dijkstra(int p, int n, std::pair<int, int> d[]) {
	std::priority_queue < std::pair<std::pair<int, int>, int>> q;
	for (int i = 1; i <= n; i++) {
		d[i].first = 1e18; v[i] = 0;
		d[i].second = 1e18;
	}
	d[p].first = 0;
	q.push({{ -d[p].first, -d[p].second}, p});
	while (q.size()) {
		int x = q.top().second; q.pop();
		// std::cout << x << std::endl;
		if (v[x]) continue;
		v[x] = 1;
		for (int i = head[x]; i; i = nxt[i]) {
			int y = ver[i], z = edge[i];
			std::pair<int, int> ls = upd(d[x], z);
			if (ls < d[y]) {
				d[y] = ls;
				q.push({{ -d[y].first, -d[y].second}, y});
			}
		}
	}
}

int cal(std::pair<int, int> p1, std::pair<int, int> p2) {
	p1 = upd(p1, p2.first), p1 = upd(p1, p2.second);
	return p1.first + p1.second;
}

void solve() {
	std::cin >> n >> m;
	for (int i = 1; i <= m; i++) {
		int a, b, c;
		std::cin >> a >> b >> c;
		add(a, b, c), add(b, a, c);
	}
	dijkstra(1, n, d1);
	dijkstra(n, n, d2);
	int ans = 1e18;
	for (int i = 1; i <= n; i++) {
		std::cout << d1[i].first << " " << d1[i].second << " " << d2[i].first << " " << d2[i].second << std::endl;
		ans = std::min(ans, cal(d1[i], d2[i]));
	}
	std::cout << ans << std::endl;
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