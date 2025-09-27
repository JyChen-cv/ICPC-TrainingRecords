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
#include <bitset>

#define int long long
typedef long long ll;
typedef double db;
typedef std::pair<int, int> PII;

const int N = 1e5;
int a[N + 2], b[N + 2];
std::vector<int> q, plan, ans;

int n, m, k, len;
int deal(int ed) {
	plan.clear();
	for (int i = 0; i < (int)q.size(); i++) {
		if (plan.empty() || q[i] - k >= *plan.rbegin()) plan.push_back(q[i]);
	}
	// for (auto i : plan) {
	// 	std::cout << i << std::endl;
	// }
	for (int i = plan.size() - 1; i >= 0; i--) {
		if (plan[i] + k > ed) {
			plan[i] = ed - k;
		}
		ed = plan[i];
	}
	if (plan[0] <= 0) return -1;
	else return plan.size();
}

void solve() {
	ans.clear();
	std::cin >> n >> m >> k >> len;
	for (int i = 1; i <= n; i++) {
		std::cin >> a[i];
	}
	for (int i = 1; i <= m; i++) {
		std::cin >> b[i];
	}
	std::sort(a + 1, a + n + 1), std::sort(b + 1, b + m + 1);
	b[0] = 0, b[m + 1] = len + 1;
	int point = 0, tag = 1;
	for (int i = 0; i <= m; i++) {
		int l = b[i], r =  b[i + 1];
		// std::cout << l << " " << r << std::endl;
		q.clear();
		while (point + 1 <= n && a[point + 1] < r) {
			point++;
			if (a[point] > l) q.push_back(a[point] - l);
		}
		int res = 0;
		if (q.size()) res = deal(r - l);
		if (res) {
			if (res == -1) {
				tag = 0;
				break;
			}
			else {
				for (auto i : plan) {
					ans.push_back(i + l);
				}
			}
		}
	}
	if (tag) {
		std::cout << ans.size() << std::endl;
		for (auto i : ans) std::cout << i << " ";
		std::cout << std::endl;
	}
	else std::cout << -1 << std::endl;
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