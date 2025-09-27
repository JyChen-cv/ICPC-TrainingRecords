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
const int N = 2e5;
struct group {
	int a, b;
	bool operator < (const group &t) const {
		if (a < t.a) return 1;
		else if (a == t.a) return b < t.b;
		return 0;
	}
} mapp[N + 2];
int n, k;
bool check(int x) {
	int cnt = 0, res = k;
	for (int i = n - 1; i >= 1; i--) {
		if (mapp[i].a >= x) {
			cnt++;
		}
		else {
			if (mapp[i].b == 0) continue;
			if (res + mapp[i].a >= x) {
				cnt++;
				res -= (x - mapp[i].a);
			}
			else break;
		}
	}
	return cnt >= ((n - 1) / 2 + 1);
}
void solve() {
	std::cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		std::cin >> mapp[i].a;
	}
	for (int i = 1; i <= n; i++) {
		std::cin >> mapp[i].b;
	}
	std::sort(mapp + 1, mapp + n + 1);
	int ans = 0;
	if (mapp[n].b == 1) {
		ans = mapp[n].a + mapp[n / 2].a; // 去掉自己
		ans += k;
	}
	else {
		ans = mapp[n].a;
		int l = 0, r = 1e9;
		while (l < r) {
			int mid = (l + r + 1) >> 1;
			if (check(mid)) l = mid;
			else r = mid - 1;
		}
		ans += l;
	}
	int res = 0;
	for (int i = n; i >= 1; i--) {
		if (mapp[i].b) {
			res = i;
			break;
		}
	}
	if (res) {
		int median = 0;
		if (res <= n / 2) median = mapp[n / 2 + 1].a;
		else median = mapp[n / 2].a;
		// std::cout << res << " " << mapp[res].a << " " << median << std::endl;
		ans = std::max(ans, mapp[res].a + median + k);
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