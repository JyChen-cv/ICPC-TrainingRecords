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

const int N = 2e5;
int a[N + 2], pos[N + 2];
int solve() {
	int n;
	std::cin >> n;
	for (int i = 1; i <= n; i++) {
		std::cin >> a[i];
	}
	std::queue<int> q[n + 2];
	for (int i = 0; i <= n; i++) pos[i] = 1e9;
	for (int i = 2; i <= n; i++) {
		// std::cout << i << std::endl;
		if (a[i] == a[i - 1]) {
			int x = -1;
			if (q[a[i]].size()) x = q[a[i]].front();
			while (q[a[i]].size() > 1) q[a[i]].pop();
			if (x != i - 1) {
				int pre = std::max(pos[i - 2], x + 1);
				pos[i] = std::min(pre, i - 2);
			}
			else {pos[i] = std::min(pos[i - 2], i - 2);}
		}
		q[a[i]].push(i);
	}

	int ans = 0;
	// for (int i = 0; i <= n; i++) {
	// 	std::cout << pos[i] << " ";
	// }
	// puts("");
	for (int i = 2; i <= n; i++) {
		ans = std::max(ans, i - pos[i]);
	}
	return ans;
}

signed main() {
	std::ios::sync_with_stdio(0);
	std::cin.tie(0), std::cout.tie(0);
	int times = 1;
	// std::cin >> times;
	while (times--) {
		std::cout << solve() << std::endl;
	}
	return 0;
}