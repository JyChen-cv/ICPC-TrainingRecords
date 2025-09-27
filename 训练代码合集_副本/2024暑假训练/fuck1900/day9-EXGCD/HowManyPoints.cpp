// https://lightoj.com/problem/how-many-points

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

int solve() {
	int x1, y1, x, y;
	std::cin >> x1 >> y1 >> x >> y;
	x -= x1, y -= y1;
	if (x < 0) x = -x;
	if (y < 0) y = -y;
	int g = gcd(x, y);
	return g + 1;
}

signed main() {
	std::ios::sync_with_stdio(0);
	std::cin.tie(0), std::cout.tie(0);
	int times = 1, cnt = 1;
	std::cin >> times;
	while (times--) {
		int ans = solve();
		std::cout << "Case " << cnt << ": " << ans << std::endl;
		cnt++;
	}
	return 0;
}