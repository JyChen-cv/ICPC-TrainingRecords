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
	std::string a;
	std::cin >> a;

	int len = a.size();
	if (len % 2) return 0;
	for (int i = 1; i < (int)a.size(); i += 2) {
		if (a[i] != a[i - 1]) return 0;
	}
	std::map<char, int> q;
	for (auto i : a) q[i]++;
	for (auto i : q) if (i.second > 2) return 0;
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