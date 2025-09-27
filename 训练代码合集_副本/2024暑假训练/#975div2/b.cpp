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
const int N = 1e5;
int a[N + 2];
std::map<int, int> ans;
void solve() {
	ans.clear();
	int n, m;
	std::cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		std::cin >> a[i];
	}
	for (int i = 2; i <= n; i++) {
		int cnt = a[i] - a[i - 1] - 1;
		// std::cout << cnt << std::endl;
		ans[(i - 1) * (n - i + 1)] += cnt;
	}
	for (int i = 1; i <= n; i++) {
		int cnt = i * (n - i + 1) - 1;
		// std::cout << cnt << std::endl;
		ans[cnt]++;
	}
	for (int i = 1; i <= m; i++) {
		int b;
		std::cin >> b;
		std::cout << ans[b] << " \n"[i == m];
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