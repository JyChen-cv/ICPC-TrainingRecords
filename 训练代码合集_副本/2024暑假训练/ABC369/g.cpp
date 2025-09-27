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
const int N = 2e5, M = 2e5;
int head[N + 2], nxt[M * 2 + 2], ver[M * 2 + 2], edge[M * 2 + 2], tot;
std::vector<int> der;
void add(int x, int y, int z = 0) {
	tot++;
	edge[tot] = z;
	ver[tot] = y;
	nxt[tot] = head[x];
	head[x] = tot;
}

int dfs(int x, int fa) {
	// std::cout << x << " " << fa << std::endl;
	std::vector<int> res;
	for (int i = head[x]; i; i = nxt[i]) {
		int y = ver[i], z = edge[i];
		if (y == fa) continue;
		res.push_back(dfs(y, x) + z * 2);
	}
	std::sort(res.begin(), res.end());
	for (int i = 0; i < (int)res.size() - 1; i++) {
		der.push_back(res[i]);
	}
	// std::cout << res.back() << std::endl;
	if (res.size())	return res.back();
	else return 0;
}

bool cmp(int x, int y) {
	return x > y;
}
void solve() {
	int n;
	std::cin >> n;
	for (int i = 1; i < n; i++) {
		int a, b, c;
		std::cin >> a >> b >> c;
		add(a, b, c), add(b, a, c);
	}
	der.push_back(dfs(1, 0));
	std::sort(der.begin(), der.end(), cmp);
	int all = 0;
	for (int i = 0; i < der.size(); i++) {
		all += der[i];
		std::cout << all << std::endl;
	}
	for (int i = der.size(); i < n; i++) std::cout << all << "\n";
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