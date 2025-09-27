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
const int N = 2e5;
int pre[N + 2], lft[N + 2];
void solve() {
	int n, m; std::string a;
	std::cin >> n >> m >> a;
	int len = a.size();
	a = 'a' + a;
	for (int i = 1; i <= len; i++) {
		pre[i] = pre[i - 1] + 1;
	}
	for (int i = len; i >= 0; i--) {
		lft[i] = lft[i + 1] + 1;
	}
	while (m--) {
		int l, r;
		std::cin >> l >> r;

	}
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