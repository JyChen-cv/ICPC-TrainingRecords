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
	int n; std::string a;
	std::cin >> n >> a;
	int ls = sqrt(n);
	if (ls * ls != n) {
		std::cout << "No" << std::endl;
		return ;
	}
	int tag = 1;
	for (int i = 0; i < ls; i++) {
		int st = i * ls, ed = (i + 1) * ls;
		if (i == 0 || i == ls - 1)
			for (int j = st; j < ed; j++) {
				if (a[j] != '1') tag = 0;
			}
		else {
			if (a[0] != '1' || a[ls - 1] != '1') tag = 0;
			for (int j = st + 1; j < ed - 1; j++) {
				if (a[j] != '0') tag = 0;
			}
		}
	}
	std::cout << (tag ? "Yes" : "No") << std::endl;

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