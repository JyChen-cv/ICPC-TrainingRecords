#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <vector>
#include <queue>
#include <map>
#include <cstring>
#include <set>

#define int long long
typedef long long ll;
typedef double db;
typedef std::pair<int, int> PII;
const int N = 2e5;
int mapp[N + 2], s[N + 2];
void solve() {
	int n;
	std::cin >> n;
	for (int i = 1; i <= n; i++) {
		std::cin >> mapp[i];
		s[i] = s[i - 1] + mapp[i];
	}
	std::string a;
	std::cin >> a;
	a = '0' + a;
	int l = 1, r = n, ans = 0;
	while (l < r) {
		while (a[l] != 'L' && l + 1 < r) l++;
		while (a[r] != 'R' && l < r - 1) r--;
		if (a[l] != 'L' || a[r] != 'R') break;
		ans += s[r] - s[l - 1];
		// std::cout << l << " " << r << std::endl;
		l++, r--;
	}
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