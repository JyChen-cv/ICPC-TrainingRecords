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
const int mod = 998244353;
const int N = 1e6;
int p[N + 2], inp[N + 2], n;
int d[N + 2];

inline int q_pow(int x, int y) {
	if (y == 0) return 1;
	int mid = q_pow(x, y / 2);
	if (y % 2)
		return mid * mid % mod * x % mod;
	else
		return mid * mid % mod;
}
inline int inv(int x) {
	return q_pow(x, mod - 2);
}
inline int C(int x, int y) {
	return p[x] * inp[y] % mod * inp[x - y] % mod;
}
void ini(int n) {
	for (int i = 0; i <= n; i++) d[i] = 0;
	p[0] = 1;
	for (int i = 1; i <= 1e6; i++) {
		p[i] = p[i - 1] * i % mod;
	}
	inp[(int)1e6] = inv(p[(int)1e6]);
	for (int i = 999999; i >= 0; i--) {
		inp[i] = inp[i + 1] * (i + 1) % mod;
	}
}

int lowbit(int x) {
	return x & (-x);
}
void add(int p, int x, int *v) {
	while (p <= n) { // 开全局变量n
		v[p] += x;
		p += lowbit(p);
	}
}
int query(int p, int *v) {
	int res = 0;
	while (p) {
		res += v[p];
		p -= lowbit(p);
	}
	return res;
}
int sum(int l, int r, int *v) {
	if (l > r) std::swap(l, r);
	return query(r, v) - query(l - 1, v);
}

void solve() {
	std::cin >> n;
	ini(n);
	int ans = 0;
	for (int i = 1; i <= n; i++) {
		int a;
		std::cin >> a;
		add(a, 1, d);
		int t = a - query(a, d);
		ans += t * p[n - i] % mod;
		ans %= mod;
		// std::cout << ans << std::endl;
	}
	std::cout << ans + 1 << std::endl;  // 康托展开的标号默认是从0开始的
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