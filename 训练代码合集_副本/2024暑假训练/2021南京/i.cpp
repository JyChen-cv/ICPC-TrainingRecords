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
const int N = 1e5;
struct node {
	int x, y;
	int typ;  // 1 表示木板，0 表示硬币
	bool operator < (const node & t) const {
		if (x < t.x) return 1;
		else if (x == t.x) return y < t.y;
		else return 0;
	}
};
int dp[N + 2][2]; // 0 表示向右上，1 表示向右下
int k, n, m;
int check(node x, node y) {
	int ls1 = y.x - x.x, ls2 = y.y - x.y;
	if (ls1 == ls2) return 0;
	else if (ls1 == -ls2) return 1;
	else return -1;
}
int online(node x, node y, int op) {
	if (op == 0) {
		int d = y.x - x.x;
		if (d <= y.y && x.y <= y.y) {
			return check(x, y);
		}
		d -= y.y;
		d = d / k + 1;
		y.y = (d / 2 * 2 * k + y.y) * (d % 2 ? -1 : 1);
		return check(x, y);
	}
	else {
		int d = y.x - x.x;
		if (d <= k - y.y && x.y >= y.y) {
			return check(x, y);
		}
		d -= (k - y.y);
		d = d / k + 1;
		y.y = ((d + 1) / 2 * 2 * k - y.y) * (d % 2 ? 1 : -1);
		return check(x, y);
	}
}
void solve() {
	std::cin >> k >> n;
	std::vector<node> q;
	for (int i = 1; i <= n; i++) {
		int a, b;
		std::cin >> a >> b;
		q.push_back({a, b, 1});
	}
	std::cin >> m;
	for (int i = 1; i <= m; i++) {
		int a, b;
		std::cin >> a >> b;
		q.push_back({a, b, 0});
	}
	q.push_back({0, 0, 0});
	std::sort(q.begin(), q.end());

	int ans = 0;
	for (int i = 1; i < (int)q.size(); i++) {
		for (int j = 0; j < i; j++) {
			int ls;
			ls = online(q[j], q[i], 0);  // -1表示不在一条线上，0表示在右上方，1表示在右下方
			// std::cout << j << " " << i << ": 0 ?" << ls << std::endl;
			// std::cout << q[j].x << " " << q[j].y << " " << q[i].x << " " << q[i].y << std::endl;
			if (ls != -1) {
				if (q[j].typ == 0) dp[i][0] = std::max(dp[i][0], dp[j][ls] + 1);
				else dp[i][0] = std::max(dp[i][0], dp[j][ls ^ 1]);
			}
			ls = online(q[j], q[i], 1);
			// std::cout << j << " " << i << ": 1 ?" << ls << std::endl;
			// std::cout << q[j].x << " " << q[j].y << " " << q[i].x << " " << q[i].y << std::endl;
			if (ls != -1) {
				if (q[j].typ == 0) dp[i][1] = std::max(dp[i][1], dp[j][ls] + 1);
				else dp[i][1] = std::max(dp[i][1], dp[j][ls ^ 1]);
			}
		}
		ans = std::max(ans, std::max(dp[i][0], dp[i][1]));
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