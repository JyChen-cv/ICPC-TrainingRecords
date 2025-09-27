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
#include <bitset>

#define int long long
typedef long long ll;
typedef double db;
typedef std::pair<int, int> PII;
void solve() {
	int n, x, k; std::string s;
	std::cin >> n >> x >> k >> s;
	int ans = 0;
	if (x)
		for (auto i : s) {
			if (k == 0) break;
			else k--;
			if (i == 'L') x--;
			else x++;
			if (x == 0) {
				ans++;
				break;
			}
		}

	if (!x) {
		int cst = 0;
		for (auto i : s) {
			if (i == 'L') x--;
			else x++;
			cst++;
			if (x == 0) {
				ans += k / cst;
				break;
			}
		}
	}

	std::cout << ans << std::endl;
	return ;
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