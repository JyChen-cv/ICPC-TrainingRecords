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

const int mod = 1e9 + 7;
const int N = 5e3, M = 5e3;
int head[N + 2], nxt[M * 2 + 2], ver[M * 2 + 2], edge[M * 2 + 2], tot, p[N + 2];
int n, k, sum;
int f[N + 2][N + 2], g[N + 2][N + 2], C[N + 2][N + 2], s[N + 2];
int lf[N + 2], lg[N + 2];

void add(int x, int y, int z = 0) {
	tot++;
	edge[tot] = z;
	ver[tot] = y;
	nxt[tot] = head[x];
	head[x] = tot;
}

void dfs(int x, int fa) {
	s[x] = 1;
	f[x][0] = 1, g[x][0] = p[x];
	for (int i = head[x]; i; i = nxt[i]) {
		int y = ver[i];
		if (y == fa) continue;
		dfs(y, x);
		for (int t = s[x] + s[y] - 1; t >= 0; t--) {
			lf[t] = 0, lg[t] = 0;
		}
		for (int t = s[x] - 1; t >= 0; t--) {
			for (int j = 0; j < s[y]; j++) {
				lf[t + j] += f[x][t] * f[y][j] % mod * C[t + j][j] % mod;
				lg[t + j] += (g[x][t] * f[y][j] % mod + f[x][t] * g[y][j] % mod) % mod * C[t + j][j] % mod;
				lf[t + j] %= mod;
				lg[t + j] %= mod;
				// if (x == 2 && y == 3) {
				// 	std::cout << t << " " << j << std::endl;
				// 	std::cout << lf[t] << std::endl;
				// 	std::cout << (f[x][t - 1 - j] * f[y][j] % mod * C[t][j + 1] % mod) << std::endl;
				// 	// continue;
				// }
				lf[t + j + 1] += f[x][t] * f[y][j] % mod * C[t + j + 1][j + 1] % mod;
				lg[t + j + 1] += g[x][t] * f[y][j] % mod * C[t + j + 1][j + 1] % mod;
				lf[t + j + 1] %= mod;
				lg[t + j + 1] %= mod;

			}
		}

		for (int t = s[x] + s[y] - 1; t >= 0; t--) {
			f[x][t] = lf[t], g[x][t] = lg[t];
		}
		s[x] += s[y];
	}
}

void solve() {
	std::cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		head[i] = p[i] = 0;
	}
	tot = 0;
	for (int i = 0; i <= n; i++)
		for (int j = 0; j <= k; j++) f[i][j] = g[i][j] = 0;
	for (int i = 1; i <= n; i++) {
		std::cin >> p[i];
		sum += p[i];
	}
	for (int i = 1; i < n; i++) {
		int a, b;
		std::cin >> a >> b;
		add(a, b), add(b, a);
	}

	dfs(1, 0);
	// for (int i = 1; i <= n; i++) {
	// 	std::cout << "f(" << i << "):";
	// 	for (int j = 0; j <= k; j++) {
	// 		std::cout << f[i][j] << " ";
	// 	}
	// 	std::cout << std::endl;
	// }
	// for (int i = 1; i <= n; i++) {
	// 	std::cout << "g(" << i << "):";
	// 	for (int j = 0; j <= k; j++) {
	// 		std::cout << g[i][j] << " ";
	// 	}
	// 	std::cout << std::endl;
	// }
	std::cout << g[1][k] << std::endl;
}

signed main() {
	std::ios::sync_with_stdio(0);
	std::cin.tie(0), std::cout.tie(0);
	C[0][0] = 1;
	for (int i = 1; i <= 5e3; i++) {
		C[i][0] = 1;
		for (int j = 1; j < i; j++) {
			C[i][j] = C[i - 1][j - 1] + C[i - 1][j];
			C[i][j] %= mod;
		}
		C[i][i] = 1;
	}

	int times = 1;
	std::cin >> times;
	while (times--) {
		solve();
	}
	return 0;
}