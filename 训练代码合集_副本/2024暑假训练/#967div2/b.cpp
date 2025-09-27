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
	int n;
	std::cin >> n;
	if (n % 2 == 0) std::cout << -1 << std::endl;
	else {
		for (int i = 1; i <= n + 1; i += 2) {
			std::cout << i << " ";
		}
		for (int i = n - 1; i >= 2; i -= 2) {
			std::cout << i << " ";
		}
		std::cout << std::endl;
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