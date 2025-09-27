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
const int N = 4e5;
int a[N + 2], n, k, f[N + 2], fa[N + 2][30];
int getfa(int x, int num) {
	for (int i = 25; i >= 0; i--) {
		if (num >= (1LL << i)) {
			num -= (1LL << i);
			x = fa[x][i];
		}
	}
	return x;
}
int check(int x) {
	int l = 1, r = 0, res = 0;
	for (int i = 1; i <= n * 2; i++) {
		while (res < x) {
			if (++r == n * 2 + 1) break;
			res += a[r];
		}
		if (r == n * 2 + 1) {
			// std::cout << l << " " << r << std::endl;
			for (int j = l; j <= n * 2; j++) {
				f[j] = r;
			}
			break;
		}
		f[l] = r + 1;
		res -= a[l++];
	}
	for (int i = n * 2; i >= 1; i--) {
		fa[i][0] = f[i];
		for (int j = 1; j <= 25; j++) {
			fa[i][j] = fa[fa[i][j - 1]][j - 1];
		}
	}
	int cnt = 0;
	for (int i = 1; i <= n; i++) {
		int ans = getfa(i, k);
		if (ans && ans <= n + i) {
			cnt++;
		}
	}
	return cnt;
}
void solve() {
	std::cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		std::cin >> a[i];
		a[i + n] = a[i];
	}
	int l = 0, r = 2e9;
	while (l < r) {
		int mid = (l + r + 1) >> 1;
		if (check(mid)) {
			l = mid;
		}
		else r = mid - 1;
	}
	std::cout << l << " " << (n - check(l)) << std::endl;
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