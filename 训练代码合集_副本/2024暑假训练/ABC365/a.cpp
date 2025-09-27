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
	if (n % 400 == 0) std::cout << 366 << std::endl;
	else if (n % 4 == 0 && n % 100) std::cout << 366;
	else std::cout << 365 << std::endl;
}

signed main() {
	std::ios::sync_with_stdio(0);
	std::cin.tie(0), std::cout.tie(0);
	int times = 1w;
	// std::cin >> times;
	while (times--) {
		solve();
	}
	return 0;
}