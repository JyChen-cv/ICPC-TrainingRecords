#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>

const int N = 2e5;
struct node {
	int x, y, val;
	bool operator < (const node& t) const {
		return val < t.val;
	}
} mapp[N + 2];
int fa[N + 2], tag[N + 2], vv[N + 2];
int head[N + 2], edge[N * 2 + 2], nxt[N * 2 + 2], ver[N * 2 + 2], tot;
int ff[N + 2][25], mi[N + 2][25], dep[N + 2];

void add(int x, int y, int z) {
	tot++;
	ver[tot] = y;
	nxt[tot] = head[x];
	head[x] = tot;
	edge[tot] = z;
}

int find(int x) {
	if (fa[x] == x) return x;
	else return fa[x] = find(fa[x]);
}

void dfs(int x, int f, int v) {
	// std::cout << x << " " << f << " " << v << std::endl;

	ff[x][0] = f;
	mi[x][0] = v;
	for (int i = 1; i <= 20; i++) {
		ff[x][i] = ff[ff[x][i - 1]][i - 1];
		mi[x][i] = std::min(mi[x][i - 1], mi[ff[x][i - 1]][i - 1]);
	}

	for (int i = head[x]; i; i = nxt[i]) {
		int y = ver[i], z = edge[i];
		if (f == y) continue;
		dep[y] = dep[x] + 1;
		dfs(y, x, z);
	}
}

void lca(int x, int y, int &an1, int &an2) {
	// std::cout << mi[x][0] << " " << mi[y][0] << std::endl;
	an1 = 0x3f3f3f3f, an2 = 0;

	if (dep[x] > dep[y]) std::swap(x, y);
	for (int i = 20; i >= 0; i--) {
		if (dep[ff[y][i]] < dep[x]) continue;
		else {
			// std::cout << y << " " << i << " " << mi[y][i] << std::endl;
			an1 = std::min(an1, mi[y][i]);
			y = ff[y][i];
		}
	}
	// std::cout << an1 << " " << x << " " << y << std::endl;
	if (x == y) {
		an2 = x;
		return ;
	}

	for (int i = 20; i >= 0; i--) {
		if (ff[x][i] != ff[y][i]) {
			an1 = std::min(an1, mi[x][i]);
			an1 = std::min(an1, mi[y][i]);
			x = ff[x][i];
			y = ff[y][i];
			// std::cout << i << " " << mi[x][i] << std::endl;
		}
	}
	// std::cout << x << " " << y << " " << an1 << std::endl;
	an1 = std::min(an1, mi[x][0]);
	an1 = std::min(an1, mi[y][0]);
	an2 = ff[x][0];
	return ;
}

int main()
{
	for (int i = 0; i <= 20; i++) mi[0][i] = 0x3f3f3f3f;
	int t = 0, ttt;
	std::cin >> ttt;
	while (++t <= ttt) {
		for (int i = 1; i <= tot; i++) head[i] = 0;
		tot = 0;

		int n, m;
		std::cin >> n >> m;
		for (int i = 1; i <= m; i++) {
			tag[i] = 0;
			std::cin >> mapp[i].x >> mapp[i].y >> mapp[i].val;
		}
		// if (ttt == 10000) {
		// 	if (t != 108)continue;
		// 	else {
		// 		std::cout << n << " " << m << std::endl;
		// 		for (int i = 1; i <= m; i++) {
		// 			std::cout << mapp[i].x << " " << mapp[i].y << " " << mapp[i].val << std::endl;
		// 		}
		// 		continue;
		// 	}
		// }
		std::sort(mapp + 1, mapp + m + 1);
		for (int i = 1; i <= n; i++) {
			fa[i] = i;
			vv[i] = 0;
		}
		for (int i = 1; i <= m; i++) {
			if (find(mapp[i].x) != find(mapp[i].y)) {
				// std::cout << mapp[i].x << " " << mapp[i].y << " " << i << std::endl;
				fa[find(mapp[i].x)] = find(mapp[i].y);
				add(mapp[i].x, mapp[i].y, mapp[i].val);
				add(mapp[i].y, mapp[i].x, mapp[i].val);
				tag[i] = 1;
			}
		}
		for (int i = 1; i <= n; i++) {
			if (vv[find(i)]) continue;
			vv[find(i)] = 1;
			dep[i] = 1;
			dfs(i, 0, 0x3f3f3f3f);
		}

		int ans = 0x3f3f3f3f, res = 0;
		int rec, rec2;
		for (int i = 1; i <= m; i++) {
			if (tag[i]) continue;
			if (find(mapp[i].x) != find(mapp[i].y)) continue;
			int ans1, ans2, ls;
			lca(mapp[i].x, mapp[i].y, ans1, ans2);
			ls = ans2;
			// std::cout << mapp[i].x << "? " << mapp[i].y << " " << ans1 << " " << ans2 << std::endl;
			ans2 = dep[mapp[i].x] + dep[mapp[i].y] - dep[ans2] * 2 + 1;
			if (ans1 < ans) {
				ans = ans1;
				res = ans2;
				rec = i;
				rec2 = ls;
			}
			else if (ans1 == ans && ans2 < res) {
				res = ans2;
				rec = i;
				rec2 = ls;
			}
			// std::cout << ans1 << " " << ans2 << std::endl;
		}
		std::cout << ans << " " << res << std::endl;
		std::vector<int> q1, q2;
		int qq = mapp[rec].x, kk = mapp[rec].y;
		while (qq != rec2) {
			q1.push_back(qq);
			qq = ff[qq][0];
		}
		while (kk != rec2) {
			q2.push_back(kk);
			kk = ff[kk][0];
		}
		for (int i = 0; i < (int)q1.size(); i++) {
			std::cout << q1[i] << " ";
		}
		std::cout << rec2 << " ";
		for (int i = (int)q2.size() - 1; i >= 0; i--) {
			std::cout << q2[i] << " ";
		}
		std::cout << std::endl;
	}
	return 0;
}