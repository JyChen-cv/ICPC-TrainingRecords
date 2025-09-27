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
int h, n, m; // 0表示right_up，1表示right_down
struct node {
	int x, y;
	int typ;  // 1 表示木板，0 表示硬币
	bool operator < (const node & t) const {
		if (x < t.x) return 1;
		else if (x == t.x) return y < t.y;
		else return 0;
	}
};
void solve() {
	std::cin >> h >> n;
	std::map<int, int> y;
	std::vector<node> q;
	int tot = 0;
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

	std::sort(q.begin(), q.end());
	int ans = 1, mod = h * 2;
	y[0] = 1;
	for (int i = 0; i < (int)q.size(); i++) {
		int ku = (q[i].x + q[i].y) % mod, kd = (mod - q[i].y + q[i].x) % mod;
		if (q[i].typ == 1) {
			int ls = std::max(y[ku], y[kd]);
			y[ku] = ls, y[kd] = ls;
		}
		else {  // 由于y的限制不能取0和h，所以不会出现两个方向算出来是一样的情况
			if (y[ku] != 0) y[ku]++;
			if (y[kd] != 0) y[kd]++;
		}
		ans = std::max(ans, std::max(y[ku], y[kd]));
	}
	std::cout << ans - 1 << std::endl;
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