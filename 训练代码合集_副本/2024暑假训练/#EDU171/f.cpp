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

const int N = 3e4;
int n, w, p[N + 2], tag[N + 2];
void solve() {
	std::cin >> n >> w;
	int cnt = n, res = 0;
	for (int i = 1; i < n; i++) {
		std::cin >> p[i];
	}
	for (int i = 1; i < n; i++) {
		int x, y;
		std::cin >> x >> y;
		if (p[x] == x - 1) {

		}
		else if ()
			w -= y;
		res += y;
		int ans = res * 2 + cnt * w;
		std::cout << ans << " \n"[i == n - 1];
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