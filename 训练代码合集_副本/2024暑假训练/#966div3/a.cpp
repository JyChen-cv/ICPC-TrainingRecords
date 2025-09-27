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
	std::string a;
	std::cin >> a;
	int tag = 1;
	if (a.size() < 3) tag = 0;
	else if (a[0] != '1' || a[1] != '0') {
		tag = 0;
	}
	else if (a[2] == '0') tag = 0;
	else if (a.size() == 3 && a[2] == '1') tag = 0;
	puts(tag ? "YES" : "NO");
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