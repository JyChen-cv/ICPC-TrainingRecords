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
const int N = 100;
int tag[N + 2];
void solve() {
	int n, m;
	std::cin >> n >> m;
	for (int i = 1; i <= m; i++) {
		int a;
		char b;
		std::cin >> a >> b;
		if (b == 'M' && !tag[a]) {
			std::cout << "Yes" << std::endl;
			tag[a] = 1;
		}
		else std::cout << "No" << std::endl;
	}
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