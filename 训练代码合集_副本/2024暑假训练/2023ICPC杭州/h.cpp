#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <vector>

#define int long long
const int mod = 1e9 + 7;
const int N = 5e5;
int head[N + 2], nxt[N * 2 + 2], ver[N * 2 + 2], d[N + 2], a[N + 2], b[N + 2], w[N + 2], in[N + 2];
int tot, ans[N + 2], poa[N + 2];

inline int qpow(int x, int y) {
	if (!y) return 1;
	int mid = qpow(x, y / 2);
	if (y % 2)
		return mid * mid % mod * x % mod;
	else
		return mid * mid % mod;
}
inline int inv(int x) {
	return qpow(x, mod - 2);
}

void add(int x, int y) {
	tot++;
	ver[tot] = y;
	nxt[tot] = head[x];
	head[x] = tot;
}

void dfs(int x, int fa) {
	d[x] = d[fa] + 1;
	ans[x] = (a[x] + w[x] * in[d[x]] % mod) % mod;
	for (int i = head[x]; i; i = nxt[i]) {
		int y = ver[i];
		dfs(y, x);
	}
}

void solve() {
	int n;
	std::cin >> n;
	tot = 0;
	for (int i = 1; i <= n; i++) {
		head[i] = 0;
		d[i] = ans[i] = poa[i] = 0;
	}
	for (int i = 1; i <= n; i++) {
		std::cin >> a[i];
	}
	for (int i = 1; i <= n; i++) {
		std::cin >> b[i];
	}
	for (int i = 1; i <= n; i++) {
		std::cin >> w[i];
	}
	std::vector<int> root;
	for (int i = 1; i <= n; i++) {
		if (a[i] < a[b[i]]) {
			root.push_back(i);
		} else if (a[i] >= a[b[i]] + w[b[i]] || i == b[i]) {
			ans[i] = a[i];
			continue;
		} else {
			add(b[i], i);
		}
	}
	d[0] = 0;
	for (int i = 0; i < (int)root.size(); i++) {
		dfs(root[i], 0);
	}
	for (int i = 1; i <= n; i++) {
		std::cout << ans[i] << " \n"[i == n];
	}
}

signed main() {
	std::ios::sync_with_stdio(0);
	std::cin.tie(0);
	std::cout.tie(0);
	poa[0] = 1;
	for (int i = 1; i <= N; i++) poa[i] = (poa[i - 1] * i) % mod;
	in[N] = inv(poa[N]);
	for (int i = N - 1; i >= 0; i--) in[i] = in[i + 1] * (i + 1) % mod;
	int t;
	std::cin >> t;
	while (t--) {
		solve();
	}
	return 0;
}