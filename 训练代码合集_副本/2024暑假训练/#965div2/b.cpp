#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <vector>
#include <queue>
#include <map>
#include <cstring>
#include <set>

typedef long long ll;
typedef double db;
typedef std::pair<int, int> PII;

void solve() {
	int n;
	std::cin >> n;
	std::vector<PII> q;
	for (int i = 1; i <= n; i++) {
		q.push_back({i, (i + 1) > n ? 1 : (i + 1)});
	}
	for (int i = 1; i <= n; i++) {
		int a;
		std::cin >> a;
		std::cout << q[a - 1].second << " ";
	}
	std::cout << std::endl;
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