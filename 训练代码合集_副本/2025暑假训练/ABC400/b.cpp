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

int lim = 1e9;
int mul(int x, int y) {
	int res = x * y;
	if (res > lim) return -1;
	return res;
}
void solve() {
	int n, nn, m, sum = 0, tag = 0;
	std::cin >> n >> m;
	nn = n, n = 1;
	for (int i = 0; i <= m; i++) {
		if (n == -1) tag = 1;
		sum += n;
		if (sum > lim) tag = 1;
		n = mul(n, nn);
	}
	if (tag) std::cout << "inf" << std::endl;
	else std::cout << sum << std::endl;
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