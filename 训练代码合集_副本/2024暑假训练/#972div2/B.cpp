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

#define int long long
typedef long long ll;
typedef double db;
typedef std::pair<int, int> PII;
std::multiset<int> q;
void solve() {
	q.clear();
	int tot, n, m;
	std::cin >> tot >> n >> m;
	for (int i = 1; i <= n; i++) {
		int a;
		std::cin >> a;
		q.insert(a);
	}
	while (m--) {
		int a;
		std::cin >> a;
		q.insert(a);
		auto pos = q.find(a), nxt = ++pos; pos--;
		if (pos == q.begin()) {
			std::cout << (*nxt - 1) << std::endl;
		}
		else if (nxt == q.end()) {
			auto pre = --pos;
			std::cout << (tot - *pre) << std::endl;
		}
		else {
			auto pre = --pos;
			std::cout << (*nxt - *pre) / 2 << std::endl;
		}
		q.erase(q.find(a));
	}
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