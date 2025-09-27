// 很巧妙的题目
// 首先根据期望的贡献公式把贡献分成两个部分（自己的贡献和两两相互的贡献）
// （平方的期望一般都这么处理，不然就只能按照定义枚举E(x^2)的x进行计算，这显然是无法做到的）
// 然后第一部分直接可以统计
// 第二部分其实是一个路径问题，而且是一个与树的结构无关的统计！
// 想到了什么！
// 显然可以转化成点分治的思考方式来解决。不过这里由于统计的性质比较简单，所以并不用真的去用点分治重新建树计算，直接简单的换根dp就可以了
// 由于这里是边的最近公共祖先，所以和点的讨论稍微有些区别
// 后续转移的过程中还用到了一些简单的线性代数知识作数学优化，不然最坏情况就会变成 O(n^2)

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
const int N = 1e5, M = 1e5;
int head[N + 2], nxt[M * 2 + 2], ver[M * 2 + 2], edge[M * 2 + 2], tot;
int n, sz[N + 2], res1, res2, sm[N + 2];

inline int q_pow(int x, int y) {
	if (!y) return 1;
	int mid = q_pow(x, y / 2);
	if (y % 2) return mid * mid % mod * x % mod;
	else return mid * mid % mod;
}

inline int inv(int x) {
	return q_pow(x, mod - 2);
}

void add(int x, int y, int z = 0) {
	tot++;
	edge[tot] = z;
	ver[tot] = y;
	nxt[tot] = head[x];
	head[x] = tot;
}

void dfs(int x, int fa) {
	sz[x] = 1;
	int res = 0;
	for (int i = head[x]; i; i = nxt[i]) {
		int y = ver[i];
		if (y == fa) continue;
		dfs(y, x);
		sz[x] += sz[y];
		(sm[x] += sm[y]) %= mod;
		(res += sm[y] * sm[y] % mod) %= mod;
	}
	// 这里是一个数学优化，处理两个边不在同一个子树内的情况，自带2倍
	(res2 += sm[x] * sm[x] % mod) %= mod;
	(res2 += mod - res) %= mod;
	for (int i = head[x]; i; i = nxt[i]) {
		int y = ver[i];
		if (y == fa) continue;
		// 这里的2倍是这个题目的关键，这一点只能在写代码前想清楚，你要的结果是一个（对称的）表，那必然有二倍
		(res2 += 2LL * q_pow((n - sz[y]), 2) % mod * ((sm[y] - sz[y] * sz[y] % mod + mod) % mod) % mod) %= mod;
	}

	(sm[x] += sz[x] * sz[x] % mod) %= mod; // 统计子树的sz和
	(res1 += sz[x] * sz[x] % mod * (n - sz[x]) % mod * (n - sz[x]) % mod) %= mod;
	// std::cout << x << " " << res1 << " " << res2 << std::endl;
}

void solve() {
	std::cin >> n; tot = res1 = res2 = 0;
	for (int i = 1; i <= n; i++) head[i] = sz[i] = sm[i] = 0;
	for (int i = 1; i < n; i++) {
		int a, b;
		std::cin >> a >> b;
		add(a, b), add(b, a);
	}
	dfs(1, 0);
	// for (int i = 1; i <= n; i++) {
	// 	std::cout << sm[i] << std::endl;
	// }
	// std::cout << res1 << " " << res2 << std::endl;
	int ans = (res1 + res2) % mod;
	// std::cout << ans * n % mod * (n - 1) % mod << std::endl;
	int frac = n * (n - 1) % mod * inv(2) % mod;
	(frac *= frac) %= mod;
	std::cout << (ans * inv(frac) % mod) << std::endl;
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