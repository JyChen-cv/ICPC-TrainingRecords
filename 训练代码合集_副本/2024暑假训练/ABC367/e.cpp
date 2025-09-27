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
const int N = 2e5;
int n, k;
int head[N + 2], nxt[N * 2 + 2], ver[N * 2 + 2], tot;
int d[N + 2], v[N + 2], h[N + 2], f[N + 2], dis[N + 2];
std::vector
int find(int x) {
	if (f[x] == x) return x;
	else return f[x] = find(f[x]);
}
void add(int x, int y) {
	tot++;
	ver[tot] = y;
	nxt[tot] = head[x];
	head[x] = tot;
}
bool dfs(int x, int fa) {
	d[x] = d[fa] + 1;
	v[x] = 1;
	int res = 0;
	for (int i = head[x]; i; i = nxt[i]) {
		int y = ver[i];
		if (v[y]) {
			sz[find(x)] = d[x] - d[y] + 1;
			return 1;
		}
		res |= dfs(y, x);
	}
	return h[x] = res;
}
void dfs2(int x, int fa) {
	if (h[x]) return dis[x] = 0;
	for (int i = head[x]; i; i = nxt[i]) {
		int y = ver[i];
		if (h[u])
		}
}
void solve() {
	std::cin >> n >> k;
	for (int i = 1; i <= n; i++) f[i] = i;
	for (int i = 1; i <= n; i++) {
		int fa;
		std::cin >> fa;
		if (find(i) != find(fa)) f[find(i)] = find(fa);
		add(i, fa), add(fa, i);
	}
	for (int i = 1; i <= n; i++) {
		if (!v[i]) dfs(i, 0);
	}
	for (int i = 1; i <= n; i++) {
		v[i] = 0;
	}
	for (int i = 1; i <= n; i++) {
		if (!v[i]) dfs2(i, 0);
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