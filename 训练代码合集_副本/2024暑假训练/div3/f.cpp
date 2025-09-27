#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <vector>

#define int long long
const int N = 1e5;
int v[N + 2], mapp[N + 2];

void solve() {
	int n, m;
	std::cin >> n >> m;
	for (int i = 1; i <= m; i++) v[i] = 0;
	for (int i = 1; i * i <= m; i++) {
		if (m % i == 0) {
			v[i] = 1;
			v[m / i] = 1;
		}
	}
	for (int i = 1; i <= n; i++) {
		std::cin >> mapp[i];
	}
	int ans = 1;
	std::vector<int> q;
	q.push_back(1);
	for (int i = 1; i <= n; i++) {
		if (m % mapp[i]) continue;
		int mx = (int)q.size();
		for (int j = 0; j < mx; j++) {
			if (q[j] * mapp[i] == m) {
				q.clear();
				q.push_back(1);
				q.push_back(mapp[i]);
				ans++;
				break;
			} else if (q[j] * mapp[i] <= m && v[q[j] * mapp[i]]) {
				q.push_back(q[j] * mapp[i]);
			}
		}
		std::sort(q.begin(), q.end());
		q.erase(unique(q.begin(), q.end()), q.end());
	}
	std::cout << ans << std::endl;
}

signed main() {
	std::ios::sync_with_stdio(0);
	std::cin.tie(0);
	std::cout.tie(0);
	int t;
	std::cin >> t;
	while (t--) {
		solve();
	}
	return 0;
}