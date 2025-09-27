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
void solve() {
	int n; std::string st;
	std::cin >> n >> st;
	int len = st.size();
	st = '1' + st;
	std::priority_queue<int> q1;
	int ans = 0;
	for (int i = n; i >= 1; i--) {
		if (st[i] == '1') q1.push(i);
		else {
			if (q1.size()) q1.pop();
			ans += i;
		}
	}
	int sz = q1.size() / 2;
	while (sz--) q1.pop();
	while (q1.size()) {
		ans += q1.top();
		q1.pop();
	}
	std::cout << ans << std::endl;
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