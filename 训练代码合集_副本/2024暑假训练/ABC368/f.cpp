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
int sg[N + 2];
void solve() {
	sg[1] = 0;
	for (int j = 2; j <= 1e5; j++) {
		int res = 0;
		for (int k = 2; k * k <= j; k++) {
			if (j % k == 0) {
				res = std::max(res, sg[k]);
				res = std::max(res, sg[j / k]);
			}
		}
		sg[j] = res + 1;
	}
	int n;
	std::cin >> n;
	int res = 0;
	for (int i = 1; i <= n; i++) {
		int a;
		std::cin >> a;
		res ^= sg[a];
	}
	puts(res ? "Anna" : "Bruno");
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