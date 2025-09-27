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

const int N = 1e3;
int rem[N + 2][N + 2][2];
int deal0(int x, int y) {
	return (x + y) % 2;
}
int deal1(int x, int y, int z) {
	if (rem[x][y][z] != -1) return rem[x][y][z];
	int v[4];
	memset(v, 0, sizeof v);
	if (z == 1) {
		if (x > 1 && y > 1) v[deal0(x - 1, y - 1)] = 1;
	}
	if (x > 1) v[deal1(x - 1, y, z)] = 1;
	if (y > 1) v[deal1(x, y - 1, z)] = 1;
	for (int i = 0; i <= 3; i++) {
		if (!v[i]) return rem[x][y][z] = i;
	}
}
void solve() {
	int n;
	std::cin >> n;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			std::cout << deal1(i, j, 1) << " ";
		}
		std::cout << std::endl;
	}
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