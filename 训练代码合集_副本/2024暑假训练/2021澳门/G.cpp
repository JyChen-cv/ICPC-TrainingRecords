#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <vector>

#define int long long
const int N = 1e6;
int mapp[N + 2], n, k, pos[N + 2];
int cov[N + 2][2], dp[N + 2][2]; // 0表示向左边，1表示向右边
int tr[N + 2]; // 开在值域上面的，1到n
int lowbit(int x) {
	return x & (-x);
}
void add(int p, int x) {
	while (p <= n) {
		tr[p] += x;
		p += lowbit(p);
	}
}
int query(int p) {
	int res = 0;
	while (p) {
		res += tr[p];
		p -= lowbit(p);
	}
	return res;
}
int deal(int x) {
	// std::cout << x << std::endl;
	int yj = 0, res = 1e9, lj = 0;
	for (int i = 20; i >= 0; i--) {
		int now = yj + (1 << i);
		if (now > n) continue;
		int all = tr[now] + lj;
		if (all <= x) {
			yj = now;
			lj = all;
		}
		else res = std::min(res, now);
	}
	return (res == 1e9 ? n : res - 1);
}
int calc(int x, int y) {
	// the distance from x to y in the circle
	int res = std::abs(x - y);
	return std::min(res, n - res);
}
void solve() {
	std::cin >> n >> k;
	for (int i = 0; i < n; i++) {
		std::cin >> mapp[i];
		pos[mapp[i]] = i;
	}
	for (int i = 1; i <= n; i++) tr[i] = 0;
	for (int i = 1; i <= n; i++) add(i, 1);
	for (int i = 0, tag = 0; i < n; i++) {  // 0~n-1
		while (tag <= i + k - 1) {
			// jiaru
			add(mapp[tag % n], -1);
			tag++;
		}
		// std::cout << i << ": " << mapp[i] << " " << query(mapp[i]) << std::endl;
		// std::cout << i << " " << tag << std::endl;
		cov[i][1] = deal(query(mapp[i]));
		add(mapp[i], 1);
	}
	for (int i = 1; i <= n; i++) tr[i] = 0;
	for (int i = 1; i <= n; i++) add(i, 1);
	for (int i = n - 1, tag = n - 1; i >= 0; i--) {
		while (tag >= i - k + 1) {
			add(mapp[(tag + n) % n], -1);
			tag--;
		}
		cov[i][0] = deal(query(mapp[i]));
		add(mapp[i], 1);
	}
	// for (int i = 0; i < n; i++) {
	// 	std::cout << i << ": " << cov[i][0] << " " << cov[i][1]  << std::endl;
	// }
	int contain = 1;
	for (int i = 1; i <= n; i++) dp[i][0] = dp[i][1] = 1e15;
	while (pos[contain] <= k - 1 && contain <= n) {
		contain++;
	}
	if (contain == n + 1) {
		std::cout << 0 << std::endl;
		return ;
	}

	dp[contain][0] = calc(k - 1, pos[contain]);
	dp[contain][1] = calc(0, pos[contain]);
	// std::cout << contain << std::endl;
	// std::cout << dp[contain][0] << " " << dp[contain][1] << std::endl;
	int ans = 1e15;
	for (int i = contain; i <= n; i++) {
		int ls1 = cov[pos[i]][0] + 1, ls2 = cov[pos[i]][1] + 1;
		if (ls1 == n + 1) {
			ans = std::min(ans, dp[i][0]);
		}
		if (ls2 == n + 1) {
			ans = std::min(ans, dp[i][1]);
		}
		dp[ls1][0] = std::min(dp[ls1][0], dp[i][0] + calc(pos[i], pos[ls1]));
		dp[ls1][1] = std::min(dp[ls1][1], dp[i][0] + calc(pos[i], (pos[ls1] + k - 1) % n));
		dp[ls2][1] = std::min(dp[ls2][1], dp[i][1] + calc(pos[i], pos[ls2]));
		dp[ls2][0] = std::min(dp[ls2][0], dp[i][1] + calc(pos[i], (pos[ls2] - k + 1 + n) % n));
		// std::cout << i << " " << pos[i] << " " << ls1  << " " << ls2 << std::endl;
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