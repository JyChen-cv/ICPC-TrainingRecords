// https://codeforces.com/problemset/problem/1986/F
// 改一下map就行，不想写了（）
// 第二个版本的也是稍微改改就行了（）贪心就行

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
	std::vector<PII> rem;
	int n, m, k;
	std::cin >> n >> m >> k;
	std::vector<int> q(m + 2);
	for (int i = 1; i <= k; i++) {
		PII a; std::cin >> a.first >> a.second;
		rem.push_back(a);
		q[a.second] = std::max(q[a.second], a.first);
	}

	int area = 0;
	q[m + 1] = n;
	for (int i = 1; i <= m; i++) {
		q[i] = std::max(q[i], q[i - 1]);
		area += (n - q[i]);
	}
	// for (int i = 1; i <= m; i++) std::cout << q[i] << std::endl;
	std::cout << area << std::endl;
	for (int i = 0; i < k; i++) {
		// std::cout << rem[i].first << " " << rem[i].second << " " << q[rem[i].second] << std::endl;
		if (rem[i].first > q[rem[i].second - 1] && rem[i].first == q[rem[i].second]) std::cout << 1 << " \n"[i == k - 1];
		else std::cout << 0 << " \n"[i == k - 1];
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

