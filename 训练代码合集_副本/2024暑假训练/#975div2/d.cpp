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
std::vector<int> q[N + 2];
inline PII uni(PII x, PII y) {
	PII res = {std::max(x.first, y.first), std::min(x.second, y.second)};
	if (res.first > res.second) res.first = 1e9;
	return res;
}
void solve() {
	int n;
	std::cin >> n;
	PII ans = {1, n};
	for (int i = 1; i <= n; i++) {
		q[i].clear();
	}
	for (int i = 1; i <= n; i++) {
		int a;
		std::cin >> a;
		if (q[a].size() == 2) q[a].pop_back();
		q[a].push_back(i);
	}
	PII ini = {n + 1, -1};
	int tag = 0;
	for (int i = 1; i <= n; i++) {
		if (!q[i].size()) continue;
		ini.first = std::min(ini.first, q[i].front());
		ini.second = std::max(ini.second, q[i].back());
		// std::cout << ini.first << " " << ini.second << std::endl;
		if (ini.second - ini.first + 1 > i) {
			tag = 1; break;
		}
	}
	if (tag) {
		std::cout << "0" << std::endl;
		return ;
	}
	for (int i = 1; i <= n; i++) {
		if (!q[i].size()) continue;
		if (q[i].back() - q[i].front() >= i) {
			ans.first = 1e9;
			break;
		}
		PII ls = {q[i].back() - i + 1, q[i][0] + i - 1};
		// std::cout << i << " " << ls.first << " " << ls.second << std::endl;
		ans = uni(ans, ls);
	}
	std::cout << ans.second - ans.first + 1 << std::endl;
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