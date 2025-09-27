#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>

const int N = 2e5;
int head[N + 2], ver[N + 2], nxt[N + 2], tot;
int mapp[N + 2], dep[N + 2], f[N + 2][20];
int cnt[N + 2][22];

void add(int x, int y) {
	tot++;
	ver[tot] = y;
	nxt[tot] = head[x];
	head[x] = tot;
}

void dfs(int x, int fa) {
	std::cout << x << " " << fa << std::endl;
//	f[x][0] = fa;
	for (int i = 1; i <= 20; i++) {
		f[x][i] = f[f[x][i - 1]][i - 1];
	}
	for (int i = 1; i <= 20; i++) {
		cnt[x][i] += cnt[fa][i];
	}
	cnt[x][mapp[x]]++;
	for (int i = head[x]; i; i = nxt[i]) {
		int y = ver[i];
		if (y == fa)
			continue;
		f[y][0] = x;
		dep[y] = dep[x] + 1;
		dfs(y, x);
	}
}

int lca(int x, int y) {
	if (dep[x] < dep[y])
		std::swap(x, y);
	for (int i = 20; i >= 0; i--) {
		if (dep[f[x][i]] >= dep[y])
			x = f[x][i];
	}
	if (x == y)
		return x;
	for (int i = 20; i >= 0; i--) {
		if (f[x][i] != f[y][i]) {
			x = f[x][i];
			y = f[y][i];
		}
	}
	return f[x][0];
}

int main() {
	int n, m;
	std::cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		std::cin >> mapp[i];
	}
	for (int i = 1; i < n; i++) {
		int a, b;
		std::cin >> a >> b;
		add(a, b);
		add(b, a);
	}
	dep[1] = 1;
	dfs(1, 0);
	for (int i = 1; i <= n; i++) {
		std::cout << i << "?" << f[i][0] << std::endl;
	}

	for (int i = 1; i <= m; i++) {
		int c, d;
		std::cin >> c >> d;
		int ans = lca(c, d);
//		std::cout << ans << std::endl;
		ans = f[ans][0];
		int res = 0;
		for (int j = 1; j <= 20; j++) {
			if (cnt[c][j] + cnt[d][j] - cnt[ans][j] * 2 != 0)
				res++;
		}
		std::cout << res << std::endl;
	}

	return 0;
}
/*
7 2
1 2 3 2 2 2 1
1 2
1 3
3 4
3 5
5 6
5 7
5 3
5 6
*/
