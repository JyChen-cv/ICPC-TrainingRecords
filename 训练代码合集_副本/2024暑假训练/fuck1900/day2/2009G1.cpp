// https://codeforces.com/problemset/problem/2009/G1

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

const int N = 4e5;
int a[N + 2], ans[N + 2];
int g[N + 2], f[N + 2], mul = 0;
std::vector<int> res[N + 2];

void add(int x) {
	g[f[x]]--; f[x]++; g[f[x]]++;
	mul = std::max(mul, f[x]);
}
void erase(int x) {
	g[f[x]]--; f[x]--; g[f[x]]++;
	mul = g[mul] > 0 ? mul : mul - 1;
}

void solve() {
	int n, k, q; mul = 0;
	std::cin >> n >> k >> q;
	for (int i = 0; i <= n * 2; i++) f[i] = g[i] = 0, res[i].clear();
	for (int i = 1; i <= n; i++) {
		std::cin >> a[i]; a[i] += n - i + 1;
		// std::cout << a[i] << " \n"[i == n];
	}

	for (int i = 1; i <= q; i++) {
		int x, y;
		std::cin >> x >> y;
		res[x].push_back(i);
	}
	for (int i = 0; i <= k - 1; i++) add(a[i]);
	for (int i = 1; i + k - 1 <= n; i++) {
		erase(a[i - 1]), add(a[i + k - 1]);
		for (auto j : res[i]) ans[j] = k - mul;
	}
	for (int i = 1; i <= q; i++) std::cout << ans[i] << "\n";
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