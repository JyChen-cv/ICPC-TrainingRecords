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
	std::string a;
	std::cin >> a;
	for (int i = a.size() - 1; i >= 0; i--) {
		if (a[i] == '0') a.pop_back();
		else if (a[i] == '.') {
			a.pop_back();
			break;
		}
		else break;
	}
	std::cout << a << std::endl;
}

signed main() {
	std::ios::sync_with_stdio(0);
	std::cin.tie(0), std::cout.tie(0);
	int times = 1;
	// std::cin >> times;
	while (times--) {
		solve();
	}
	return 0;
}