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
int a[N + 2], s[N + 2], st[N + 2][23], f[N + 2][23];

inline int query(int x, int y) {
	int len = y - x, k = log(len) / log(2);
	return std::max(st[x][k], st[y - (1 << k) + 1][k]);
}
void solve() {
	int n, m;
	std::cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		std::cin >> a[i];
		s[i] = s[i - 1] + a[i];
	}
	for (int i = 1; i <= n; i++) {
		f[i][0] = i - 1;
		for (int j = 1; j <= 20; j++) {
			f[i][j] = f[f[i][j - 1]][j - 1];
		}
	}
	st[0][0] = -1e9;  // 一个重要的边界
	for (int i = 1; i <= n; i++) {
		st[i][0] = a[i];
		for (int j = 1; j <= 20; j++) {
			st[i][j] = std::max(st[i][j - 1], st[f[i][j - 1]][j - 1]);
		}
	}

	std::priority_queue<PII> era, res;
	for (int i = 1; i <= n; i++) {
		while (s[i] - s[res.top().second - 1] > m || era.top() == res.top()) {
			if (res.top() == era.top()) era.pop();
			res.pop();
		}
		f[i] = res.top().first;
		res.push({q})
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
