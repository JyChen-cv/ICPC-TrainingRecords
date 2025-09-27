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

int n, k;
std::string q, res;

inline bool check(int x) {
	if (res[x] != 'n') return 0;
	if (res[x + 1] != 'a') return 0;
	if (res[x + 2] != 'n') return 0;
	if (res[x + 3] != 'j') return 0;
	if (res[x + 4] != 'i') return 0;
	if (res[x + 5] != 'n') return 0;
	if (res[x + 6] != 'g') return 0;
	return 1;
}

int deal(int x) {
	if (x > q.size()) return 0;
	std::string a = q.substr(0, x), b = q.substr(x);
	res.clear();
	res = b + a;
	// std::cout << res << std::endl;
	int bk = 0;
	for (int i = 0; i + 6 < (int)res.size(); i++) {
		if (check(i)) bk++;
	}
	return bk;
}
void solve() {
	std::cin >> n >> k >> q;
	k = std::min(k, (int)6);
	int ans = 0;
	for (int i = 0; i <= k; i++) {
		ans = std::max(ans, deal(i));
	}
	std::cout << ans << std::endl;
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