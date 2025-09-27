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
int solve() {
	int len; std::string a;
	std::cin >> len >> a;
	if (len % 2 == 0) return 0;
	if (a[len / 2] != '/') return 0;
	for (int i = 0; i < (len / 2); i++) if (a[i] != '1') return 0;

	for (int i = (len / 2) + 1; i < len; i++) if (a[i] != '2') return 0;
	return 1;
}

signed main() {
	std::ios::sync_with_stdio(0);
	std::cin.tie(0), std::cout.tie(0);
	int times = 1;
	// std::cin >> times;
	while (times--) {
		int ans = solve();
		puts(ans == 1 ? "Yes" : "No");
	}
	return 0;
}