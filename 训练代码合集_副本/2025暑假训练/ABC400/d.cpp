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

const int MaxN = 100;
int n, h, x_1, y_1, x_2, y_2;
int dx[5] = {0, 1, -1, 0, 0};
int dy[5] = {0, 0, 0, 1, -1};
std::string mapp[MaxN];
struct node {
	int x, y;
	int val;
	bool operator < (const node &t) const {
		return val < t.val;
	}
};
std::priority_queue<node> q;

int check(int x, int y) {
	if (x < 1 || x > n || y < 1 || y > h) {
		return 0;
	}
	if (mapp[x][y] == '.') return 2;
	else return 1;
}

void solve() {
	std::cin >> n >> h;
	for (int i = 1; i <= n; i++) {
		std::cin >> mapp[i];
		mapp[i] = '#' + mapp[i];
	}
	std::cin >> x_1 >> y_1 >> x_2 >> y_2;
	q.push(node{x_1, y_1, 0});
	while (q.size()) {
		int ix = q.top().x, iy = q.top().y;
		q.pop();
		for (int i = 1; i <= 4; i++) {
			int cx = ix + dx[i], cy = iy + dy[i];
			int tag = check(cx, cy);
			if (tag == 2) {

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