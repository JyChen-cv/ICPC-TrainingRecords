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
const int N = 2e5;
const int mod = 1e9 + 7; // 记得开 long long
int a[N + 2], p[N + 2], b[20];
int q_pow(int x, int y) {
	if (!y) return 1;
	int mid = q_pow(x, y / 2);
	if (y % 2) return mid * mid % mod * x % mod;
	else return mid * mid % mod;
}
inline int inv(int x) {
	return q_pow(x, mod - 2);
}

void solve() {
	int n;
	std::cin >> n;
	for (int i = 1; i <= n; i++) {
		std::cin >> a[i];
	}
	for (int i = 1; i <= n; i++) {
		std::cin >> p[i];
		(p[i] *= inv(10000LL)) %= mod;
		// std::cout << p[i] << std::endl;
	}
	int ans = 0;
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			int dp[2][2], rem[2][2]; // 计算当前i和j位置对于答案(i+j)位置的贡献
			memset(dp, 0, sizeof dp);
			dp[0][0] = 1;
			for (int k = 1; k <= n; k++) {
				int ls1 = (a[k] >> i) & 1, ls2 = (a[k] >> j) & 1;  // 取出所有数字的这两位值
				for (int u = 0; u < 2; u++)
					for (int v = 0; v < 2; v++) {
						rem[u][v] = dp[u][v];  // 保存一下k-1的状态
						dp[u][v] = 0; // 清空
					}

				for (int u = 0; u < 2; u++) {
					for (int v = 0; v < 2; v++) {
						(dp[u ^ ls1][v ^ ls2] += rem[u][v] * p[k] % mod) % mod; // 若发生则对最终的贡献
						(dp[u][v] += rem[u][v] * (mod + 1 - p[k]) % mod) % mod; // 若不发生则对最终的贡献
					}
				}
			}
			// std::cout << i << " " << j << ": " << dp[1][1] << std::endl;
			ans += (1LL << (i + j)) * dp[1][1] % mod;  // 只有两位值都是1才会对答案有贡献
			ans %= mod;
		}
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