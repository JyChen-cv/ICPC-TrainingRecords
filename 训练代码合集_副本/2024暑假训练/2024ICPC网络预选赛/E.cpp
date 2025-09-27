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
const int N = 2e5, M = 5e5;
int head[N + 2], nxt[M * 2 + 2], ver[M * 2 + 2], edge[M * 2 + 2], tot;
int ban[N + 2][2], rem[N + 2][2];
void add(int x, int y, int z = 0) {
	tot++;
	edge[tot] = z;
	ver[tot] = y;
	nxt[tot] = head[x];
	head[x] = tot;
}
int n, m, d, k;

void solve() {
	std::cin >> n >> m >> d;
	tot = 0;
	for (int i = 0; i <= n; i++) {
		ban[i][0] = ban[i][1] = -1;
		rem[i][0] = rem[i][1] = -1;
		head[i] = 0;
	}
	for (int i = 1; i <= m; i++) {
		int a, b;
		std::cin >> a >> b;
		add(a, b), add(b, a);
	}
	std::cin >> k;
	std::queue<PII> q;
	for (int i = 1; i <= k; i++) {
		int a;
		std::cin >> a;
		q.push({a, 0});
		ban[a][0] = 0;
	}
	while (q.size()) {
		PII now = q.front(); q.pop();
		int x = now.first, dis = now.second + 1;
		for (int i = head[x]; i; i = nxt[i]) {
			int y = ver[i];
			// std::cout << x << " " << y << std::endl;
			if (ban[y][dis % 2] != -1 || dis > d) continue;
			else {
				ban[y][dis % 2] = dis;
				q.push({y, dis});
			}
		}
	}

	q.push({1, 0});
	rem[1][0] = 0;
	while (q.size()) {
		PII now = q.front(); q.pop();
		int x = now.first, dis = now.second + 1;
		for (int i = head[x]; i; i = nxt[i]) {
			int y = ver[i];
			// std::cout << x << " " << y << std::endl;
			if (rem[y][dis % 2] != -1 || (ban[y][dis % 2] != -1 && ban[y][dis % 2] <= dis)) continue;
			else {
				// std::cout << y << std::endl;
				rem[y][dis % 2] = x;
				q.push({y, dis});
			}
		}
	}
	// for (int i = 1; i <= n; i++) {
	// 	std::cout << i << ": " << ban[i][0] << " " << ban[i][1] << std::endl;
	// }

	std::vector<int> ans1, ans2;
	int tag = n, nn = 0;
	while (rem[tag][nn] && rem[tag][nn] != -1) {
		// std::cout << tag << std::endl;
		ans1.push_back(tag);
		tag = rem[tag][nn];
		nn ^= 1;
	}
	if (!rem[tag][nn]) ans1.push_back(tag);
	tag = n, nn = 1;
	while (rem[tag][nn] && rem[tag][nn] != -1) {
		// std::cout << tag << std::endl;
		ans2.push_back(tag);
		tag = rem[tag][nn];
		nn ^= 1;
	}
	if (!rem[tag][nn])ans2.push_back(tag);
	// std::cout << ans1.size() << " " << ans2.size() << std::endl;
	if (!ans1.size() && !ans2.size()) {
		std::cout << -1 << std::endl;
	}
	else if (ans1.size() && (!ans2.size() || ans1.size() < ans2.size())) {
		std::cout << ans1.size() - 1 << std::endl;
		for (int i = (int)ans1.size() - 1; i >= 0; i--) {
			std::cout << ans1[i] << " \n"[i == 0];
		}
	}
	else {
		std::cout << ans2.size() - 1 << std::endl;
		for (int i = (int)ans2.size() - 1; i >= 0; i--) {
			std::cout << ans2[i] << " \n"[i == 0];
		}
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