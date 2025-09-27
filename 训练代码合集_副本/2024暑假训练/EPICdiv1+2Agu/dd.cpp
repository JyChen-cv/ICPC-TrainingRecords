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
const int N = 3e5;
int fa[N + 2], pos[N + 2], mapp[N + 2], sz[N + 2];
bool contain(int x1, int y1, int x2, int y2) {
	// 1 \in 2
	if (x1 >= x2 && y1 <= y2) return 1;
	else return 0;
}
std::multiset<int> c[N + 2];
bool check(int x) {
	if (sz[x] == 1) return 1;
	auto ls = c[x].end();
	ls--;
	int mi = *c[x].begin(), mx = *ls;
	return contain(mi, mx, pos[x], pos[x] + sz[x]);
}
void dt(int x) {
	auto ls = c[fa[x]].find(pos[x]);
	c[fa[x]].erase(ls);
	ls = c[fa[x]].find(pos[x] + sz[x]);
	c[fa[x]].erase(ls);
}
void ad(int x) {
	c[fa[x]].insert(pos[x]), c[fa[x]].insert(pos[x] + sz[x]);
}
void solve() {
	// d2 version
	int n, m;
	std::cin >> n >> m;
	for (int i = 0; i <= n; i++) c[i].clear();
	for (int i = 2; i <= n; i++) {
		std::cin >> fa[i];
	}
	for (int i = 1; i <= n; i++) {
		std::cin >> mapp[i];
		pos[mapp[i]] = i;
		sz[i] = 1;
	}
	for (int i = n; i >= 1; i--) sz[fa[i]] += sz[i];
	int ans = 0;
	sz[0] = n; pos[0] = 1;
	for (int i = n; i >= 1; i--) {
		ad(i);
		if (check(i)) {
			// std::cout << "!" << i << std::endl;
			ans++;
		}
	}

	for (int i = 1; i <= m; i++) {
		int a, b;
		std::cin >> a >> b;
		std::vector<int> q;
		q.push_back(mapp[a]), q.push_back(mapp[b]), q.push_back(fa[mapp[a]]), q.push_back(fa[mapp[b]]);
		std::sort(q.begin(), q.end());
		q.erase(unique(q.begin(), q.end()), q.end());
		for (auto j : q) {
			if (j == 0) continue;
			ans -= check(j);
		}
		// std::cout << ans << std::endl;
		dt(mapp[a]), dt(mapp[b]);
		std::swap(pos[mapp[a]], pos[mapp[b]]);
		std::swap(mapp[a], mapp[b]);
		ad(mapp[a]), ad(mapp[b]);
		for (auto j : q) {
			if (j == 0) continue;
			ans += check(j);
		}
		// std::cout << ans << std::endl;
		puts(ans == n ? "YES" : "NO");
	}
}

int main() {
	std::ios::sync_with_stdio(0);
	std::cin.tie(0), std::cout.tie(0);
	int times = 1;
	std::cin >> times;
	while (times--) {
		solve();
	}
	return 0;
}