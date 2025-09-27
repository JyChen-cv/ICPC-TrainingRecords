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
int pos[7], sim1[N + 2], sim2[N + 2];
void solve() {
	int n, m;
	int aa[N + 2];
	std::cin >> n >> m;
	for (int i = 1; i <= 6; i++) pos[i] = 0;
	for (int i = 1; i <= n; i++) sim1[i] = 0;
	for (int i = 1; i <= n; i++) {
		std::string a;
		std::cin >> a;
		if (a == "BG") aa[i] = 1;
		else if (a == "BR") aa[i] = 2;
		else if (a == "BY") aa[i] = 3;
		else if (a == "GR") aa[i] = 4;
		else if (a == "GY") aa[i] = 5;
		else aa[i] = 6;
		for (int j = 1; j <= 6; j++) {
			if (j + aa[i] == 7 || j == aa[i]) continue;
			sim1[i] = std::max(sim1[i], pos[j]);
		}
		pos[aa[i]] = i;
		// std::cout << sim1[i] << " \n"[i == n];
	}
	for (int i = 1; i <= 6; i++) pos[i] = n + 1;
	for (int i = 1; i <= n; i++) sim2[i] = n + 1;
	for (int i = n; i >= 1; i--) {
		for (int j = 1; j <= 6; j++) {
			if (j + aa[i] == 7 || j == aa[i]) continue;
			sim2[i] = std::min(sim2[i], pos[j]);
		}
		pos[aa[i]] = i;
		// std::cout << sim2[i] << " \n"[i == 1];
	}
	for (int i = 1; i <= m; i++) {
		int x, y;
		std::cin >> x >> y;
		if (x > y) std::swap(x, y);
		int ans = 1e9;
		if (aa[x] + aa[y] == 7) {
			if (sim2[x] < y) ans = y - x;
			else if (sim1[y] > x) ans = y - x;
			else {
				// std::cout << x << " " << y << std::endl;
				if (sim1[x] > 0) ans = (y + x - 2 * sim1[x]);
				if (sim2[y] <= n) ans = std::min(ans, sim2[y] * 2 - x - y);
			}
		}
		else ans = y - x;
		std::cout << (ans == 1e9 ? -1 : ans) << std::endl;
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