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
inline int gcd(int x, int y) {
	return y ? gcd(y, x % y) : x;
}
inline int lcm(int x, int y) {
	int res = gcd(x, y);
	return x * y / res;
}

// 做法说实话有点伪，最坏情况很难构造罢了
// 这个大搜索不知道如何调整才能保证正确，
// 理论上搜索范围不是26，是2*log(a)/log(2)
int ans = 1e9;
int MAX = 26;
void dfs(int x, int y, int res) {
	if (x == 0 || y == 0) {
		ans = std::min(ans, res + 1);
		return ;
	}
	if (res > MAX) return ;
	if (res > ans) return ;
	int ls = gcd(x, y);
	x /= ls, y /= ls;
	// std::cout << x << " " << y << " " << res << " " << ans << std::endl;
	if (x % 2) {
		dfs(x - 1, y, res + 1);
		dfs(x, y - 1, res + 1);
	}
	else {
		dfs(x, y - 1, res + 1);
		dfs(x - 1, y, res + 1);
	}
}

void solve() {
	int a, b;
	ans = 1e9;
	std::cin >> a >> b;
	MAX = 2 * log(a) / log(2);
	dfs(a, b, 0);
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