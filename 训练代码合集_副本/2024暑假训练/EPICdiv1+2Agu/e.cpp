#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <vector>
#include <queue>
#include <map>
#include <cstring>
#include <set>

#define int long long
typedef long long ll;
typedef double db;
typedef std::pair<int, int> PII;
void solve() {
	int n, ans = 0;
	std::cin >> n;
	std::vector<PII> q;
	for (int i = 1; i <= n; i++) {
		int a, b;
		std::cin >> a >> b;
		int mx = 0;
		while (q.size()) {
			if (q.back().second == b) {
				a += q.back().first - mx;
				q.pop_back();
			}
			else if (q.back().first <= a) {
				mx = std::max(mx, q.back().first);
				q.pop_back();
			}
			else break;
		}
		q.push_back({a, b});
		ans = std::max(ans, a);
		std::cout << ans << " \n"[i == n];
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