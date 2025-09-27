#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>

#define int long long

const int N = 1e3;
struct node {
	int p, s;
	bool operator<(const node &a) const { return p + s < a.p + a.s; }
} mapp[N + 2];

void solve() {
	int n, m;
	std::cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		std::cin >> mapp[i].p >> mapp[i].s;
	}
	std::sort(mapp + 1, mapp + n + 1);
	int ans = 0, tag = 1;
	for (int i = 1; i <= n; i++) {
		tag = i;
		if (m < mapp[i].p + mapp[i].s) break;
		m -= mapp[i].p + mapp[i].s;
		ans++;
	}

	int res_min = 1e9 + 7;
	for (int i = tag; i <= n; i++) {
		res_min = std::min(res_min, mapp[i].p / 2 + mapp[i].s);
	}
	if (m >= res_min)
		ans++;
	else {
		int dis = 0;
		for (int i = 1; i < tag; i++) {
			dis = std::max(dis, (mapp[i].p + 1) / 2);
		}
		m += dis;
		if (m >= (mapp[tag].p + mapp[tag].s)) ans++;
	}
	std::cout << ans << std::endl;
}

signed main() {
	std::ios::sync_with_stdio(0);
	std::cin.tie(0), std::cout.tie(0);

	int times = 1;
	while (times--) {
		solve();
	}
	return 0;
}
