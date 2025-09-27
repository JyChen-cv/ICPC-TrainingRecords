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
const int N = 1e5;
ll mapp[N + 2];
void solve() {
	int n;
	std::map<int, int> f;
	std::cin >> n;
	for (int i = 1; i <= n; i++) {
		std::cin >> mapp[i];
		mapp[i] -= i;	// 现在应该是判断想等就可以了
		f[i] = mapp[i];	//
	}
	ll ans = 0;
	int q;
	std::cin >> q;
	while (q--) {
		int t, g;
		std::cin >> t >> g;
		g -= t;
		// 就是在first中进行查找
		auto it = std::prev(f.upper_bound(t));  // 返回上一个迭代器？为毛不直接lowerbound,因为后面可能删掉了，所以不定能找到
		int x = it->second;

		if (x < g) {	// 如果是向右移动
			f[t] = x;
			it = f.find(t);
			while (true) {
				auto nxt = std::next(it);
				if (nxt == f.end()) {
					ans += (n - t) * (g - x);
					x = g;
					break;
				}
			}
			while (true) {
				if (it == f.begin()) {
					ans += t * (x - g);
					x = g;
				}
			}
		}
	}
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