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
int a[N + 2], b[N + 2], n;

void solve() {
	std::cin >> n;
	for (int i = 1; i <= n; i++) {
		std::cin >> a[i];
		b[i] = a[i];
	}
	a[n + 1] = b[n + 1] = 0;
	int m = 0, l = 1e15;
	for (int i = n; i >= 1; i--) a[i] += a[i + 1];
	for (int i = n; i >= 1; i--) {
		int res = a[i] / (n - i + 1);
		if (a[i] % (n - i + 1)) res++;
		m = std::max(m, res);
	}
	for (int i = 1; i <= n; i++) b[i] += b[i - 1];
	for (int i = 1; i <= n; i++) {
		int res = b[i] / i;
		l = std::min(l, res);
	}
	std::cout << m - l << std::endl;
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