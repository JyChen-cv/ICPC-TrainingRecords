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
#include <bitset>

#define int long long
typedef long long ll;
typedef double db;
typedef std::pair<int, int> PII;

const int N = 5000, M = 10000;
int head[N + 2], nxt[M * 2 + 2], ver[M * 2 + 2], edge[M * 2 + 2], tot;
int n, sz[N + 2], f[N + 2], pw[N + 2], g[N + 2], dep[N + 2];

const int mod = 998244353;  // 记得开 long long
inline int q_pow(int x, int y) {
	if (!y) return 1;
	int mid = q_pow(x, y / 2);
	if (y % 2) return mid * mid % mod * x % mod;
	else return mid * mid % mod;
}

inline int inv(int x) {
	return q_pow(x, mod - 2);
}

void add(int x, int y, int z = 0) {
	tot++;
	edge[tot] = z;
	ver[tot] = y;
	nxt[tot] = head[x];
	head[x] = tot;
}

int deal(std::vector<int> &son) {
	int S = 0;
	for (auto i : son) {
		S += i;
	}
	int nmt = pw[S], dmt = 1;
	for (auto i : son) {
		dmt *= pw[i], dmt %= mod;
	}
	return nmt * inv(dmt) % mod;
}

void dfs(int x, int fa) {
	f[x] = 1, dep[x] = dep[fa] + 1;
	std::vector<int> son;
	for (int i = head[x]; i; i = nxt[i]) {
		int y = ver[i];
		if (y == fa) continue;
		dfs(y, x);
		sz[x] += sz[y];
		son.push_back(sz[y]);
		f[x] *= f[y], f[x] %= mod;
	}
	f[x] *= deal(son), f[x] %= mod;
	sz[x]++;
}

inline int C(int x, int y) {
	// choose y from x
	if (x < y || y < 0) return 0;
	return pw[x] * inv(pw[y]) % mod * inv(pw[x - y]) % mod;
}

int dfs2(int x, int fa, int tag, int pre) {
	int flag = 0;
	std::vector<int> son;
	for (int i = head[x]; i; i = nxt[i]) {
		int y =  ver[i];
		if (y == fa) continue;
		int ls = dfs2(y, x, tag, pre);
		if (ls) flag = y;
		else son.push_back(sz[y]);
	}
	if (!flag) {
		g[x] = f[x];
		return false;
	}
	else {
		// 除了tag都不固定位置
		int res = 1;
		res *= C(n - tag, sz[tag]), res %= mod;
		res *=
		    return true;
	}
}

void solve() {
	std::cin >> n;
	for (int i = 2; i <= n; i++) {
		int a;
		std::cin >> a;
		add(i, a), add(a, i);
	}
	dfs(1, 0);
	std::cout << "ALL: " << f[1] << std::endl;

	std::cout << f[1] << std::endl;
	for (int i = 2; i <= n; i++) {
		dfs2(1, 0, i, dep[]);
		std::cout << g[1] << " ";
	}
	std::cout << std::endl;
}

signed main() {
	std::ios::sync_with_stdio(0);
	std::cin.tie(0), std::cout.tie(0);
	pw[0] = 1;
	for (int i = 1; i <= 5000; i++) {
		pw[i] = pw[i - 1] * i % mod;
	}
	int times = 1;
	// std::cin >> times;
	while (times--) {
		solve();
	}
	return 0;
}