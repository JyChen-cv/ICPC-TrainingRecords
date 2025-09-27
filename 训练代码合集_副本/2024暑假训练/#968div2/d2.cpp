#include <algorithm>
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
const int N = 2e5;
int v[N + 2], a[N + 2], res;
const int M = N;
int head[N + 2], nxt[M * 2 + 2], ver[M * 2 + 2], tot, f[N + 2];
void add(int x, int y) {
	tot++;
	ver[tot] = y;
	nxt[tot] = head[x];
	head[x] = tot;
}
int dfs(int x) {
	if (f[x]) return f[x];
	int ls = x, du = 0;
	for (int i = head[x]; i; i = nxt[i]) {
		int y = ver[i];
		if (y == x) continue;
		ls = std::max(ls, dfs(y));
		du++;
	}
	if (du >= 2) res = std::max(res, ls);
	return f[x] = ls;
}
void solve() {
	int n, m, fw = 0;
	std::cin >> n >> m;
	tot = 0; res = 0;

	for (int i = 1; i <= n; i++) {
		int k, fr, to;
		std::cin >> k;
		for (int j = 1; j <= k; j++) {
			std::cin >> a[j];
			if (a[j] <= k) v[a[j]] = 1;
		}
		// for (int j = 0; j <= 5; j++) std::cout << v[j] << " \n"[j == 5];
		int point = -1;
		while (v[point + 1]) {
			point++;
		}
		point++;
		fr = point;
		// std::cout << point << std::endl;
		while (v[point + 1]) {
			point++;
		}
		point++;
		to = point;
		// std::cout << point << std::endl;
		for (int j = 1; j <= k; j++) {
			if (a[j] <= k) v[a[j]] = 0;
		}
		add(fr, to);
		fw = std::max(fw, to);
		res = std::max(res, fr);
	}
	int ans = 0;
	for (int i = 0; i <= fw; i++) {
		dfs(i);
	}
	// std::cout << res << std::endl;
	for (int i = 0; i <= std::min(fw, m); i++) {
		int ls = std::max(f[i], res);
		// std::cout << f[i] << " " << res << std::endl;
		ans += ls;
	}
	if (fw < m) {
		ans += (m + fw + 1) * (m - fw) / 2;
	}

	// if (m > res) {
	// 	ans = (m - res) * (m + res + 1) / 2;
	// 	ans += (res + 1) * res;
	// }
	// else ans = (m + 1) * res;
	std::cout << ans << std::endl;
	for (int i = 0; i <= fw; i++) {
		head[i] = 0;
		f[i] = 0;
	}
}

signed main() {
	std::ios::sync_with_stdio(0);
	std::cin.tie(0), std::cout.tie(0);
	int times = 1;
	std::cin >> times;
	while (times--) {
		solve();
	}
	return 0;
}