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
void solve() {
	int n;
	std::cin >> n;
	for (int i = 1; i <= n; i++) {
		std::cin >> a[i];
	}
	if (n == 1)  {
		std::cout << 1 << std::endl;
		return ;
	}
	for (int i = 1; i < n; i++) {
		a[i] = a[i + 1] - a[i];
	}
	int len = 1, ans = n;
	for (int i = 2; i < n; i++) {
		if (a[i] == a[i - 1]) len++;
		else {
			// std::cout << len << " " << ans << std::endl;
			ans += (len + 1) * len / 2;
			len = 1;
		}
	}
	ans += (len + 1) * len / 2;
	std::cout << ans << std::endl;
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