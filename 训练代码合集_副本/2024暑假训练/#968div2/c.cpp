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
std::pair<int, char> a[30];
void solve() {
	int n;
	std::string s;
	std::cin >> n >> s;
	for (int i = 1; i <= 30; i++) a[i] = {0, 'a' + i - 1};
	for (int i = 0; i < (int)s.size(); i++) {
		a[s[i] - 'a' + 1].first--;
	}
	std::sort(a + 1, a + 26 + 1);
	std::string ans;
	for (int i = 1; i <= 26; i++) {
		while (a[i].first) {
			ans += a[i].second;
			a[i].first++;
		}
	}
	// std::cout << ans << std::endl;
	int point2 = (ans.size() + 1) / 2, point = 0;
	while (point2 < ans.size()) {
		std::cout << ans[point] << ans[point2];
		point++, point2++;
	}
	if (point < (ans.size() + 1) / 2) std::cout << ans[point];
	std::cout << std::endl;
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