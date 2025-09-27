// 每次重新算高斯消元代价太高，来到了O(n^5)
// 现在这种5次方做法和直接把n^2个方程全部一起做高斯消元的复杂度一样
// 改成每次增量插入线形基，会提高到O(n^4)
// bitset会自动优化一个64的常数

#include <algorithm>
#include <bitset>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <unordered_map>
#include <vector>

#define int long long
typedef long long ll;
typedef double db;
typedef std::pair<int, int> PII;

const int N = 250, M = 250;
int head[N + 2], nxt[M * 2 + 2], ver[M * 2 + 2], edge[M * 2 + 2], tot, d[N + 2],
    f[N + 2], com[N * N + 2], val[N + 2];
int n, k;
std::bitset < N + 2 > am[N + 2], tst[N + 2];
std::vector<std::vector<int> > rem;

bool operator<(std::bitset < N + 2 > a, std::bitset < N + 2 > b) {
	for (int i = N; i >= 0; i--) {
		if (a[i] > b[i])
			return 0;
		else if (a[i] < b[i])
			return 1;
	}
	return 0;  // 严格小于
}

void add(int x, int y, int z = 0) {
	tot++;
	edge[tot] = z;
	ver[tot] = y;
	nxt[tot] = head[x];
	head[x] = tot;
}

void dfs(int x, int fa) {
	d[x] = d[fa] + 1;
	f[x] = fa;
	for (int i = head[x]; i; i = nxt[i]) {
		int y = ver[i];
		if (y == fa) continue;
		dfs(y, x);
	}
}
void deal(int x, int y) {
	std::vector<int> q;
	q.push_back(x), q.push_back(y);
	if (d[x] < d[y]) std::swap(x, y);
	while (d[x] > d[y]) q.push_back(f[x]), x = f[x];
	if (x != y) {
		while (x != y) {
			q.push_back(f[x]), q.push_back(f[y]);
			x = f[x], y = f[y];
		}
	}
	q.pop_back();  // 肯定有一个和y重复的
	if (q.size() == k + 1) {
		rem.push_back(q);
	}
}

bool check(int t) {
	for (int i = 0; i <= t; i++) tst[i] = am[i];
	// std::cout << t << std::endl;
	// for (int i = 1; i <= t; i++) {
	// 	for (int j = n; j >= 1; j--) {
	// 		std::cout << tst[i][j];
	// 	}
	// 	std::cout << " " << val[i];
	// 	std::cout << std::endl;
	// }

	for (int i = 1; i <= t; i++) {
		for (int j = i + 1; j <= t; j++) {
			if (tst[i] < tst[j]) {
				std::swap(tst[i], tst[j]);
				std::swap(val[i], val[j]);
			}
		}
		if (tst[i] == 0) return 0;
		// 没有冲突导致无解的情况
		// 无解只可能是方程不线性无关

		for (int k = n; k >= 1; k--) {
			if (tst[i][k]) {
				for (int l = 1; l <= t; l++) {
					if (l != i && tst[l][k]) {
						tst[l] ^= tst[i];
						val[l] ^= val[i];
					}
				}
				break;
			}
		}
	}
	// std::cout << t << std::endl;
	// for (int i = 1; i <= t; i++) {
	// 	for (int j = n; j >= 1; j--) {
	// 		std::cout << tst[i][j];
	// 	}
	// 	std::cout << " " << val[i];
	// 	std::cout << std::endl;
	// }
	return 1;
}
void solve() {
	std::cin >> n >> k;
	for (int i = 1; i < n; i++) {
		int a, b;
		std::cin >> a >> b;
		add(a, b), add(b, a);
	}

	dfs(1, 0);
	// for (int i = 1; i <= n; i++) {
	// 	std::cout << d[i] << " " << f[i] << std::endl;
	// }
	for (int i = 1; i <= n; i++) {
		for (int j = i + 1; j <= n; j++) {
			deal(i, j);
		}
	}
	// std::cout << rem.size() << std::endl;

	// 增广第0列先暂时都不写，后续再补充
	int t = 1;
	am[1][1] = 1;
	for (int i = 0; i < (int)rem.size(); i++) {
		am[++t].reset();
		for (auto j : rem[i]) {
			am[t][j] = 1;
		}
		if (check(t))
			com[i] = 1;
		else
			t--;
		// std::cout << i << std::endl;
	}
	if (t == n) {
		std::cout << "YES" << std::endl;
		std::cout << "? ";
		std::cout << n - 1 << std::endl;
		for (int i = 0; i < (int)rem.size(); i++) {
			if (com[i]) std::cout << rem[i][0] << " " << rem[i][1] << " ";
		}
		std::cout << "\n";
		std::cout.flush();
		val[1] = 0;
		for (int i = 2; i <= n; i++) {
			std::cin >> val[i];
		}
		check(t);
		std::cout << "! ";
		for (int i = n - 1; i >= 1; i--) {
			std::cout << val[i] << " ";
		}
		std::cout << std::endl;
		std::cout.flush();
	}
	else std::cout << "NO" << std::endl;
	std::cout.flush();
}
signed main() {
	// std::ios::sync_with_stdio(0);
	// std::cin.tie(0), std::cout.tie(0);
	int times = 1;
	// std::cin >> times;
	while (times--) {
		solve();
	}
	return 0;
}
