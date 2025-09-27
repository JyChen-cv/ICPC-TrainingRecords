#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <iterator>
#include <vector>
#include <queue>
#include <map>
#include <cstring>
#include <set>

typedef long long ll;
typedef double db;
typedef std::pair<int, int> PII;
void solve() {
	int n, m, k, d;
	std::cin >> n >> m >> k;
	d = k / 2;
	std::vector<PII> q;
	for (int i = 1; i <= d; i++) {
		q.push_back({i + n, m});
	}
	for (int i = 1; i <= d; i++) {
		q.push_back({n - i, m});
	}
	if (k % 2) q.push_back({n, m});
	for (int i = 0; i < (int)q.size(); i++) {
		std::cout << q[i].first << " " << q[i].second << std::endl;
	}
}

int main() {
	std::ios::sync_with_stdio(0);
	std::cin.tie(0), std::cout.tie(0);
	int times = 1;
	std::cin >> times;
	while (times--) {
		solve();
	}
	return 0;
}