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
const int N = 1e6;
double a[N + 2], s[N + 2];
int n;
std::vector<PII> q;
bool deal(PII x, PII &y) {
	if ((s[y.second] - s[y.first - 1]) * (x.second - x.first + 1) < (s[x.second] - s[x.first - 1]) * (y.second - y.first + 1)) {
		y.first = x.first;
		return 1;
	}
	return 0;
}
void solve() {
	scanf("%lld", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%lf", a + i);
		s[i] = s[i - 1] + a[i];
	}
	for (int i = 1; i <= n; i++) {
		PII now = std::make_pair(i, i);
		while (q.size() && deal(q.back(), now))
			q.pop_back();
		q.push_back(now);
	}
	for (int i = 0; i < (int)q.size(); i++) {
		db ans = (s[q[i].second] - s[q[i].first - 1]) / (q[i].second - q[i].first + 1);
		for (int j = q[i].first; j <= q[i].second; j++) {
			printf("%.10lf\n", ans);
		}
	}
}

signed main() {
	// std::ios::sync_with_stdio(0);
	// std::cin.tie(0), std::cout.tie(0);
	int times = 1;
	// std::cin >> times;
	while (times--) {
		solve();
	}
	return 0;
}