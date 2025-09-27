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
	int x[] = {0, 0}, y[] = {0, 0};
	std::string a;
	std::cin >> a;
	int res = 0;
	for (int i = 0; i < (int)a.size(); i++) {
		if (a[i] == '2') {
			res++;
			continue;
		}
		if (i % 2) x[a[i] - '0'] ++;
		else y[a[i] - '0']++;
	}
	int ans = std::abs(x[0] - y[0]) + std::abs(x[1] - y[1]);
	ans = std::max((int)(res - ans) % 2, ans - res);
	std::cout << ans << std::endl;
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