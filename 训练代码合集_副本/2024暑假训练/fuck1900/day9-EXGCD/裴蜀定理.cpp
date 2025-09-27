// https://www.luogu.com.cn/problem/P4549

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

const int N = 20;
int a[N + 2], n;
inline int gcd(int x, int y) {
	return y ? gcd(y, x % y) : x;
}
inline int lcm(int x, int y) {
	int res = gcd(x, y);
	return x * y / res;
}
void solve() {
	std::cin >> n;
	for (int i = 1; i <= n; i++) {std::cin >> a[i]; if (a[i] < 0) a[i] = -a[i];}
	for (int i = 2; i <= n; i++) {
		a[i] = gcd(a[i], a[i - 1]);
	}
	std::cout << a[n] << std::endl;
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