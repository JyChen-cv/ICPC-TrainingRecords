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
const int N = 2e5;
int pos[N + 2], val[N + 2];
void solve() {
	int n;
	std::cin >> n;
	for (int i = 1; i <= n; i++) {
		std::cin >> pos[i];
	}
	for (int i = 1; i <= n; i++) {
		std::cin >> val[i];
	}
	int t = pos[2];
	while (t != 2) {
		std::cout << t << std::endl;
		t = pos[t];
	}
	for (int i = 1; i <= n; i++) {
		int a;
		std::cin >> a;
		std::cout << val[a] << std::endl;
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