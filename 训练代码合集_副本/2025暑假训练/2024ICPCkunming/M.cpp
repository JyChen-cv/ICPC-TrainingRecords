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
#include <bitset>

#define int long long
typedef long long ll;
typedef double db;
typedef std::pair<int, int> PII;

int n, m;
const int N = 1000;
std::map<std::pair<int, int>, int> dz;
int mapp[N + 2][N + 2];
inline bool check(int x, int y) {
	if (x > n) return 0;
	if (y > m) return 0;
	if (dz[ {x, y}]) return 0;
	dz[ {x, y}] = 1;
	return 1;
}

void solve() {
	dz.clear();
	std::cin >> n >> m;
	int k = n * m;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			mapp[i][j] = 0;
	std::queue<std::pair<int, int>> q;
	q.push({1, 1});
	int po = 0;
	while (q.size()) {
		std::pair<int, int> now = q.front();
		q.pop();
		// if (!mapp[now.first][now.second])
		// std::cout << now.first << " " << now.second << std::endl;
		mapp[now.first][now.second] = ++po;
		if (check(now.first, now.second + 1))
			q.push({now.first, now.second + 1});
		if (check(now.first + 1, now.second))
			q.push({now.first + 1, now.second});
	}
	std::cout << "YES" << std::endl;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			std::cout << mapp[i][j] << " ";
		}
		std::cout << "\n";
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