#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <queue>

const int N = 2e4;
int n, m;
int f[N + 2], q[N + 2], g[N + 2];

int main() {
	std::cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		int v, w, s;
		std::cin >> v >> w >> s;
		memcpy(g, f, sizeof(f));
		for (int j = 0; j < v; j++) {
			int fro = 0, tal = -1;
			for (int k = j; k <= m; k += v) {
				while (fro <= tal && k - q[fro] > s * v) fro++;
				while (fro <= tal && g[q[tal]] - (q[tal] - j) / v * w <= g[k] - (k - j) / v * w) tal--;
				q[++tal] = k;
				f[k] = g[q[fro]] + (k - q[fro]) / v * w;
			}
		}
	}
	std::cout << f[m] << std::endl;
	return 0;
}