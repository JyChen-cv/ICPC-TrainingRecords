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

const int N = 1e5;
int n, m, k;
int cnt[N + 2];
int deal(int x) {
	int res = x / m;
	if (x % m) res++;
	return res;
}

void solve() {
	std::cin >> n >> m >> k;
	for (int i = 1; i <= n; i++) cnt[i] = 0;
	if (k >= m) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= m; j++) {
				int a;
				std::cin >> a;
			}
		}
		std::cout << m << std::endl;
		return ;
	}
	else {
		k = m - k;
		int ans = 0;
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= m; j++) {
				int a;
				std::cin >> a;
				cnt[deal(a)]++;
				// std::cout << a << " " << deal(a) << std::endl;
				if (cnt[deal(a)] >= k && !ans) {
					ans = (i - 1) * m + j;
				}
			}
		}
		std::cout << std::max(ans, m) << std::endl;
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