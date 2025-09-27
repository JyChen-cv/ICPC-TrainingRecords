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
const int N = 5e5;
struct group {
	int x, y, w, id;
	int tx, ty;
	bool operator < (const group &t) const {
		return w < t.w;
	}
} e[N + 2];
int fa[N + 2], sz[N + 2];

int find(int x) {
	if (x == fa[x]) return x;
	else return fa[x] = find(fa[x]);
}

void merge(int x, int y) {
	x = find(x), y = find(y);
	if (x == y) return ;
	fa[x] = fa[y];
}
bool cmp(const group x, const group y) {
	return x.id < y.id;
}
void solve() {
	int n, m;
	std::cin >> n >> m;
	for (int i = 1; i <= n; i++) fa[i] = i;
	for (int i = 1; i <= m; i++) {
		std::cin >> e[i].x >> e[i].y >> e[i].w;
		e[i].id = i;
	}
	std::sort(e + 1, e + m + 1);
	for (int i = 1, j = 1; i <= m; ) {
		j = i;
		while (j + 1 <= m && e[j].w == e[j + 1].w) {
			e[j].tx = find(e[j].x), e[j].ty = find(e[j].y);
			j++;
		}
		e[j].tx = find(e[j].x), e[j].ty = find(e[j].y);
		for (; i <= j; i++) {
			if (find(e[i].x) == find(e[i].y)) continue;
			else merge(e[i].x, e[i].y);
		}
	}
	std::sort(e + 1, e + m + 1, cmp);
	for (int i = 1; i <= n; i++) fa[i] = i;  // 重新初始化
	int q;
	std::cin >> q;
	for (int i = 1; i <= q; i++) {
		int k;
		std::cin >> k;
		std::vector<group> v;
		for (int i = 0; i < k; i++) {
			int a;
			std::cin >> a;
			v.push_back(group({e[a].tx, e[a].ty, e[a].w}));
		}
		std::sort(v.begin(), v.end());
		bool flag = 1;
		for (int i = 0; i < (int)v.size() && flag;) {
			if (v[i].x == v[i].y) {flag = 0; break;}  // 前面已经连通
			merge(v[i].x, v[i].y); // 每个长度的第一条边一定是ok的
			int j = i + 1;
			while (j < (int)v.size() && v[j].w == v[i].w) {
				if (find(v[j].x) == find(v[j].y)) {flag = 0; break;}
				merge(v[j].x, v[j].y);
				j++;
			}
			while (i < j) {
				fa[v[i].x] = v[i].x, fa[v[i].y] = v[i].y;
				i++;
			}
		}
		puts(flag ? "YES" : "NO");
	}
}

int main() {
	std::ios::sync_with_stdio(0);
	std::cin.tie(0), std::cout.tie(0);
	int times = 1;
	// std::cin >> times;
	while (times--) {
		solve();
	}
	return 0;
}