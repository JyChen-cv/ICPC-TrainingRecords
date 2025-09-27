// https://www.luogu.com.cn/problem/P1516

// gcd只要保证前两个参数为正就好了，至于翻的倍数正不正无所谓，解是不是正也控制不了

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
	int x, y, m, n, l;
	std::cin >> x >> y >> m >> n >> l;
	y = x - y, n -= m;
	if (n < 0) {
		y = -y, n = -n;
	}
	int r1, r2;
	int gcd = exgcd(n, l, r1, r2);
	if (y % gcd) {
		std::cout << "Impossible" << std::endl;
		return ;
	}
	r1 *= y / gcd, r2 *= y / gcd;
	int d = l / gcd;
	((r1 %= d) += d) %= d;
	std::cout << r1 << std::endl;
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