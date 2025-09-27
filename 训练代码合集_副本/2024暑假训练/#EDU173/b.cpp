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
	int n, d;
	std::cin >> n >> d;
	std::cout << "1 ";
	if (n >= 3 || d % 3 == 0) {
		std::cout << "3 ";
	}
	if (d == 5) std::cout << "5 ";
	if (n >= 3 || d == 7) std::cout << "7 ";
	if (n >= 6 || d == 9 || (n >= 3 && d % 3 == 0)) std::cout << "9 ";
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