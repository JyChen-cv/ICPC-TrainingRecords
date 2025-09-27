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
int pre[N + 2], lft[N + 2];
int solve() {
	int len; std::string a;
	std::cin >> len >> a; a = 'a' + a;
	for (int i = 1; i <= len; i++) {
		if (a[i] == '1') {
			pre[i] = pre[i - 1] + 1;
		}
		else pre[i] = 0;
	}
	for (int i = len; i >= 1; i--) {
		if (a[i] == '2') {
			lft[i] = lft[i + 1] + 1;
		}
		else lft[i] = 0;
	}
	int ans = 0;
	for (int i = 1; i <= len; i++) {
		if (a[i] == '/') {
			ans = std::max(ans, std::min(pre[i - 1], lft[i + 1]) * 2 + 1);
		}
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