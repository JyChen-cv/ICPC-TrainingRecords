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
int a[N + 2];
int n;

inline bool check(int x) {
	if (n - x <= 2) return 1;
	for (int i = 0; i <= x; i++) {
		int head = i, tail = x - i;
		if (a[head + 1] + a[head + 2] > a[n - tail]) return 1;
	}
	return 0;
}
void solve() {
	std::cin >> n;
	for (int i = 1; i <= n; i++) {
		std::cin >> a[i];
	}
	std::sort(a + 1, a + n + 1);
	int l = 0, r = n;
	while (l < r) {
		int mid = l + r >> 1;
		if (check(mid)) r = mid;
		else l = mid + 1;
	}
	std::cout << l << std::endl;
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