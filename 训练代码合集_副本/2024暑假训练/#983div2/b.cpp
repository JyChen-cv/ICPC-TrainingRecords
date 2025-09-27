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
void solve() {
	int n, k;
	std::cin >> n >> k;
	if (n == 1 && k == 1) {
		std::cout << 1 << std::endl;
		std::cout << 1 << std::endl;
		return ;
	}
	if (k == 1 || k == n) {
		std::cout << -1 << std::endl;
		return ;
	}
	int l = k - 1, r = n - k;
	std::vector<int> ans;
	ans.push_back(1), ans.push_back(k), ans.push_back(k + 1);
	if (l % 2 == 0) {
		ans.push_back(k - 1);
	}
	if (r % 2 == 0) {
		ans.push_back(k + 2);
	}
	std::sort(ans.begin(), ans.end());
	std::cout << ans.size() << std::endl;
	for (auto i : ans) std::cout << i << " ";
	puts("");
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