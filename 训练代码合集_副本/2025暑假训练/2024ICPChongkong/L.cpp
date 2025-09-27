#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <utility>
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

const int N = 200;
std::string mapp[N + 2];
int rmd[N * 2 + 2];
int n, m;

inline int cal(int x, int y) {
	return x + (m - y);
}

std::string gen(std::vector<std::pair<int, int>> &q, int k) {
	std::string res;
	for (int i = 1; i < (int)q.size(); i++) {
		int dx = q[i].first - q[i - 1].first;
		int dy = q[i].second - q[i - 1].second;
		for (int j = 1; j <= dx; j++) res += 'D';
		for (int j = 1; j <= dy; j++) res += 'R';
	}
	// std::cout << 1 << std::endl;
	int nx = 1, ny = 1;
	for (auto i : res) {
		mapp[nx][ny] = mapp[nx][ny] == 'B' ? 'W' : 'B';
		if (i == 'R') ny++;
		else nx++;
	}
	return res;
}

void solve() {
	std::cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		std::cin >> mapp[i];
		mapp[i] = 'a' + mapp[i];
	}

	std::vector<std::string> ans;
	int tag = 1;
	memset(rmd, 0, sizeof(rmd));
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			rmd[i + j - 1] ^= (mapp[i][j] == 'B');
		}
	}
	for (int i = 2; i <= n + m - 1; i++) {
		if (rmd[i] != rmd[i - 1]) tag = 0;
	}

	if (tag) {
		// B -> 1 , W -> 0
		// std::cout << "111" << std::endl;
		for (int k = 1; k <= n + m - 1; k++) {
			std::vector<std::pair<int, int>> q;
			q.push_back({1, 1});
			for (int i = 1; i <= n; i++) {
				for (int j = 1; j <= m; j++) {
					if (cal(i, j) == k && mapp[i][j] == 'B') {
						q.push_back({i, j});
					}
				}
			}
			q.push_back({n, m});
			if (q.size() == 2) continue;
			// for (auto i : q) {
			// 	std::cout << k << " " << i.first << " " << i.second << std::endl;
			// }
			ans.push_back(gen(q, k));
		}
	}
	else {
		tag = 1;
		memset(rmd, 0, sizeof(rmd));
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= m; j++) {
				rmd[i + j - 1] ^= (mapp[i][j] == 'W');
			}
		}
		for (int i = 2; i <= n + m - 1; i++) {
			if (rmd[i] != rmd[i - 1]) tag = 0;
		}

		if (tag) {
			// B -> 0 , W -> 1
			// std::cout << "111" << std::endl;
			for (int k = 1; k <= n + m - 1; k++) {
				std::vector<std::pair<int, int>> q;
				q.push_back({1, 1});
				for (int i = 1; i <= n; i++) {
					for (int j = 1; j <= m; j++) {
						if (cal(i, j) == k && mapp[i][j] == 'W') {
							q.push_back({i, j});
						}
					}
				}
				q.push_back({n, m});
				if (q.size() == 2) continue;
				ans.push_back(gen(q, k));
			}
		}
	}

	if (tag) {
		std::cout << "YES" << std::endl;
		std::cout << ans.size() << std::endl;
		for (auto i : ans) {
			std::cout << i << std::endl;
		}
	}
	else std::cout << "NO" << std::endl;
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