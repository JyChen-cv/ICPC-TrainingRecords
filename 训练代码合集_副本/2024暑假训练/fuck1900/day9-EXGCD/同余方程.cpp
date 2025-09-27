// https://www.luogu.com.cn/problem/P1082

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

inline int exgcd(int a, int b, int &x, int &y) {
	if (b == 0) {x = 1, y = 0; return a;}
	int d = exgcd(b, a % b, x, y);
	int z = x; x = y, y = z - y * (a / b);
	return d;
}

void solve() {
	int a, b, x, y;
	std::cin >> a >> b;
	int gcd = exgcd(a, b, x, y);
	gcd = b / gcd;
	((x %= gcd) += gcd) %= gcd;
	std::cout << x << std::endl;
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