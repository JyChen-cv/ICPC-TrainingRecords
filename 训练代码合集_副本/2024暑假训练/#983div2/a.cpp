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
	int n, cnt[2];
	cnt[0] = cnt[1] = 0;
	std::cin >> n;
	for (int i = 1; i <= n * 2; i++) {
		int a;
		std::cin >> a;
		cnt[a]++;
	}
	if (cnt[1] <= n) {
		std::cout << cnt[1] % 2 << " " << cnt[1] << std::endl;
	}
	else {
		std::cout << cnt[1] % 2 << " " << cnt[0] << std::endl;
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