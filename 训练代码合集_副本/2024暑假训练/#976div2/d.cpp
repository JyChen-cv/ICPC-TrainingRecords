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

const int N = 2e5;
int f[N + 2], ans;
inline int find(int x) {
	if (x == f[x]) return f[x] = x;
	else return f[x] = find(f[x]);
}
inline void uni(int x, int y) {
	int xx = find(x), yy = find(y);
	if (xx == yy) return ;
	else {
		f[xx] = yy;
		ans--;
	}
}
std::vector<PII> q[12][12];
struct node {
	int a, d, k;
	bool operator < (const node &t) const {
		return a < t.a;
	}
} mapp[N + 2];
void solve() {
	int n, m;
	std::cin >> n >> m;
	ans = n;
	for (int i = 1; i <= n; i++) f[i] = i;
	for (int i = 0; i <= 10; i++)
		for (int j = 0; j <= 10; j++) q[i][j].clear();
	for (int i = 1; i <= m; i++) {
		int a, d, k;
		std::cin >> a >> d >> k;
		mapp[i] = {a, d, k};
	}
	std::sort(mapp + 1, mapp + m + 1);
	for (int i = 1; i <= m; i++) {
		int a, d, k;
		a = mapp[i].a, d = mapp[i].d, k = mapp[i].k;
		int s = a, e = a + d * k;
		while (q[d][a % d].size() && q[d][a % d].back().second >= s) {
			s = std::min(s, q[d][a % d].back().first);
			e = std::max(e, q[d][a % d].back().second);
			q[d][a % d].pop_back();
		}
		q[d][a % d].push_back({s, e}); // 闭区间
	}
	for (int i = 1; i <= 10; i++) {
		for (int j = 0; j < i; j++) {
			if (!q[i][j].size()) continue;
			// std::cout << i << " " << j << " " << q[i][j].size() << std::endl;
			for (int k = 0; k < (int)q[i][j].size(); k++) {
				int s = q[i][j][k].first, e = q[i][j][k].second;
				// std::cout << "! : " << s << " " << e << std::endl;
				for (int l = s; l + i <= e; l += i) {
					uni(l, l + i);
				}
			}
		}
	}
	std::cout << ans << std::endl;
}

// 1 2      1 0
// 1        3 1
// 3        1 0
// 1 3      2 1
// 2        2 0
// 2        2 1
// 1 2 3    1 0
// 1        2 1

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