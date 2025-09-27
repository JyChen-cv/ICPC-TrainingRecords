// https://www.luogu.com.cn/problem/P2054

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

int n, m, k;
__int128 mod;  // 记得开 long long
inline int q_pow(int x, int y) {
	if (!y) return 1;
	int mid = q_pow(x, y / 2);
	if (y % 2) return (__int128)mid * mid % mod * x % mod;
	else return (__int128)mid * mid % mod;
}

inline int inv(int x) {
	return q_pow(x, mod - 2);
}

inline int exgcd(int a, int b, int &x, int &y) {
	if (b == 0) {x = 1, y = 0; return a;}
	int d = exgcd(b, a % b, x, y);
	__int128 z = x; x = y, y = z - y * (a / b);
	return d;
}

void solve() {
	std::cin >> n >> m >> k;
	mod = n + 1;
	int col = q_pow(2, m);
	// std::cout << col << std::endl;
	int x, y;
	int g = exgcd(col, n + 1, x, y);
	int d = n + 1;  // 其实一定保证了互质，n为偶数保证了不互指的这种情况是不存在的
	x = (__int128)x * k % mod;
	((x %= d) += d) %= d;  // 找到了最小的正整数解
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