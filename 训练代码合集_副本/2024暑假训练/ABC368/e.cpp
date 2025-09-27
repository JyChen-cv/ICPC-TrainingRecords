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
const int N = 6e5;  // 开3倍
int d[N + 2], a[N + 2], b[N + 2], s[N + 2], t[N + 2];
int used[N + 2];
std::vector<PII> f[N + 2], G[N + 2];

bool cmp(PII x, PII y) {
	int sx = (x.second ? t : s)[x.first], sy = (y.second ? t : s)[y.first];
	if (sx != sy) return sx < sy;
	else return x.second > y.second;
}
void solve() {
	int n, m, x;
	std::cin >> n >> m >> x;
	for (int i = 1; i <= m; i++) {
		std::cin >> a[i] >> b[i] >> s[i] >> t[i];
		f[a[i]].push_back({i, 0});
		f[b[i]].push_back({i, 1});
	}
	int all = m;  // 前m个点就表示m条边
	for (int i = 1; i <= n; i++) {
		std::sort(f[i].begin(), f[i].end(), cmp);
		for (int j = 0; j < (int)f[i].size(); j++) {
			all++;
			if (j) {  // 给每个点建立一个链表进行链接
				int sjpre = (f[i][j - 1].second ? t : s)[f[i][j - 1].first];
				int sjnow = (f[i][j].second ? t : s)[f[i][j].first];
				G[all - 1].push_back({all, sjpre - sjnow});
			}
			if (f[i][j].second) {
				G[f[i][j].first].push_back({all, 0});
			}
			else G[all].push_back({f[i][j].first, 0});
		}
	}

	std::priority_queue<PII> q;
	for (int i = 1; i <= all; i++) d[i] = -1e18;
	d[1] = x;
	q.push({d[1], 1});
	while (q.size()) {
		int v = q.top().second; q.pop();
		if (used[v]) continue; used[v] = 1;
		for (auto e : G[v]) {
			if (d[e.first] < d[v] + e.second) {
				d[e.first] = d[v] + e.second;
				q.push({d[e.first], e.first});
			}
		}
	}
	for (int i = 2; i <= m; i++) {  // 因为一开始就是满足一个排序关系才能建立边，所以不会出现前面的取0导致后面的反而不够的情况
		std::cout << std::max(0LL, d[i]) << " \n"[i == m];
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