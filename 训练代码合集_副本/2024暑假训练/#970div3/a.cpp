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
	int a, b;
	std::cin >> a >> b;
	if (a == 0 && b == 0) {
		std::cout << "YES" << std::endl;
		return;
	}
	if (a % 2) std::cout << "NO" << std::endl;
	else if (a != 0) std::cout << "YES" << std::endl;
	else if (b % 2)std::cout << "NO" << std::endl;
	else std::cout << "YES" << std::endl;
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