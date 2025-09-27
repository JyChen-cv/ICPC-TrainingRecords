// https://codeforces.com/problemset/problem/1977/C

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

inline int gcd(int x, int y) {
	return y ? gcd(y, x % y) : x;
}
inline int lcm(int x, int y) {
	if (x > 1e9 || y > 1e9 || x == -1 || y == -1) return -1;  // 越界的话肯定就合法了，直接标记
	int res = gcd(x, y);
	return x * y / res;
}

void solve() {
	int n; std::vector<int> q; std::map<int, int> mp;
	std::cin >> n;
	for (int i = 1; i <= n; i++) {
		int a;
		std::cin >> a; q.push_back(a); mp[a] = 1;
	}
	std::sort(q.begin(), q.end());

	int lm = q[0];
	for (int i = 1; i < (int)q.size(); i++) {
		lm = lcm(lm, q[i]);
	}
	if (lm != q.back()) {
		std::cout << n << std::endl;
	}
	else {
		std::set<int> fac;
		for (int i = 1; i * i <= q.back(); i++) {
			if (q.back() % i) continue;
			fac.insert(i);
			if (i * i != q.back()) fac.insert(q.back() / i);
		}
		// for (auto u : fac) std::cout << u << std::endl;
		int len = 0;
		for (auto i : fac) {
			std::vector<int> deal;
			if (mp[i]) continue;
			for (auto j : q) {
				if (j > i) continue;
				if (i % j == 0) deal.push_back(j);
			}
			if (deal.size() == 0) continue;
			int res = deal[0];
			for (auto j : deal) res = lcm(res, j);
			// std::cout << i << " " << res << std::endl;
			if (res == i) len = std::max(len, (int)deal.size());
		}
		std::cout << len << std::endl;
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