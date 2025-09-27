#include <functional>
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <utility>
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

const int N = 1e5;
struct car {
	int d, v, a;
	bool operator < (const car &t) const {
		return d < t.d;
	}
} c[N + 2];
int mon[N + 2];
PII q[N + 2];

bool check(car &c, int &p, int v) {
	int len = p - c.d;
	int res = c.v * c.v + 2 * c.a * len;
	return res > v * v;
}
void solve() {
	int n, m, l, v;
	std::cin >> n >> m >> l >> v;
	for (int i = 0; i <= n + 1; i++) q[i] = {0ll, 0ll};
	for (int i = 1; i <= n; i++) {
		std::cin >> c[i].d >> c[i].v >> c[i].a;
	}
	for (int i = 1; i <= m; i++) std::cin >> mon[i];
	std::sort(c + 1, c + n + 1); std::sort(mon + 1, mon + m + 1);
	int point = 1;
	for (int i = 1; i <= n; i++) {
		while (mon[point] < c[i].d && point + 1 <= m + 1) point++;
		if (point == m + 1) break;
		if (check(c[i], mon[point], v)) {
			int s = point, e = m;
			while (s < e) {
				int mid = s + e + 1 >> 1;
				if (check(c[i], mon[mid], v)) s = mid;
				else e = mid - 1;
			}
			q[i] = {point, s};
		}
		else if (check(c[i], mon[m], v)) {
			int s = point, e = m;
			while (s < e) {
				int mid = s + e >> 1;
				if (check(c[i], mon[mid], v)) e = mid;
				else s = mid + 1;
			}
			q[i] = {s, m};
		}
		else continue;
	}
	std::sort(q + 1, q + n + 1);
	// for (int i = 1; i <= n; i++) {
	// 	std::cout << q[i].first << " " << q[i].second << std::endl;
	// }
	int cnt = 0;
	for (int i = 1; i <= n + 1; i++) {
		if (q[i] == std::make_pair(0ll, 0ll)) continue;
		cnt = i; break;
	}
	if (q[n] == std::make_pair(0ll, 0ll)) {
		std::cout << 0 << " " << m << std::endl;
		return ;
	}
	int ans = 0; std::priority_queue<int, std::vector<int>, std::greater<int> > mn;
	for (int i = cnt; i <= n; i++) {
		// std::cout << " " << mn.top() << std::endl;
		for (int j = i; !mn.size() || q[j].first <= mn.top(); j++) {
			mn.push(q[j].second); i = j;
		}
		ans++;
		// std::cout << i << " " << ans << " " << mn.top() << std::endl;
		while (mn.size()) mn.pop();
	}
	std::cout << n - cnt + 1 << " " << m - ans << std::endl;
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