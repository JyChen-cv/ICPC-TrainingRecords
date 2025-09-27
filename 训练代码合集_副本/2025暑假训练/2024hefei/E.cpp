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

const int N = 1e3;
std::vector<int> dx[N * N + 2], dy[N * N + 2];
std::map<int, int> q;

int deal(std::vector<int> &d) {
	std::sort(d.begin(), d.end());
	// for (auto i : d) std::cout << "? " << i << std::endl;
	int pre = 0, suf = 0, res = 0;
	for (auto i : d) suf += i;
	for (int i = 0; i < (int)d.size(); i++) {
		int cnt1 = i, cnt2 = d.size() - i;
		res += suf - cnt2 * d[i];
		res += cnt1 * d[i] - pre;
		suf -= d[i], pre += d[i];
	}
	// std::cout << res << std::endl;
	return res;
}

void solve() {
	int n, m, all = 0, ans = 0;
	std::cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			int a;
			std::cin >> a;
			if (q[a]) a = q[a];
			else {
				q[a] = ++all;
				a = all;
			}
			// std::cout << a << std::endl;
			dx[a].push_back(i), dy[a].push_back(j);
		}
	}
	for (int i = 1; i <= all; i++) {
		ans += deal(dx[i]);
		ans += deal(dy[i]);
	}
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