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
int a[N + 2], b[N + 2];
void solve() {
	int n, k;
	std::cin >> n >> k;
	for (int i = 1; i <= n; i++) std::cin >> a[i];
	for (int i = 1; i <= n; i++) std::cin >> b[i];

	auto check = [&](const int x) -> int {
		int res = 0;
		for (int i = 1; i <= n; i++) {
			int len = a[i] - x;
			if (len < 0)  continue;
			res += len / b[i] + 1;
		}
		return res <= k;
	};
	int l = 0, r = 1e9 + 5;
	while (l < r) {
		int mid = l + r >> 1;
		if (check(mid)) r = mid;
		else l = mid + 1;
	}
	int ans = 0;
	for (int i = 1; i <= n; i++) {
		int len = a[i] - l;
		if (len < 0) continue;
		else {
			ans += (a[i] + a[i] - len / b[i] * b[i]) * (len / b[i] + 1) / 2;
		}
	}
	int res = 0;
	for (int i = 1; i <= n; i++) {
		int len = a[i] - l;
		if (len < 0)  continue;
		res += len / b[i] + 1;
	}
	if (l > 0) ans += (k - res) * (l - 1);
	std::cout << ans << std::endl;
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