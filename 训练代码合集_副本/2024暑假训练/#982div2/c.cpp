// 一开始转化到背包，但是其实和背包还是不一样的，这个相当于是只有容量恰好等于重量才能选取，然后容量是越来越大的，很明显前面那个恰好相等才能选比背包严格多了

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

const int N = 3e5;
int a[N + 2], w[N + 2];
int n;
std::map<ll, std::vector<ll> > adj;
std::map<int, bool> v;
int len;

void dfs(int x) {
	len = std::max(len, x);
	v[x] = 1;
	for (auto y : adj[x]) {
		if (v[y]) continue;
		dfs(y);
	}
}
void solve() {
	adj.clear(); v.clear();
	std::cin >> n; len = 0;
	for (int i = 1; i <= n; i++) {
		std::cin >> a[i];
		w[i] = a[i] - (n - i + 1);
		if (w[i] < 0) continue;
		// std::cout << i << " " << w[i] << std::endl;
		adj[w[i]].push_back(w[i] + i - 1);
	}
	dfs(0);
	std::cout << len + n << std::endl;
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