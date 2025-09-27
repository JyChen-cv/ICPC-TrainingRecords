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
const int N = 3e5;
int a[N + 2], v[N + 2], f[N + 2];
void solve() {
	int n;
	std::cin >> n;
	for (int i = 1; i <= n; i++) {
		std::cin >> a[i];
	}
	int ans = 0;
	for (int i = n; i >= 1; i--) {
		if (v[a[i]] == 0) ans++;
		v[a[i]]++;
	}
	int cnt = 1;
	for (int i = 1; i <= n; i++) {
		if (f[a[i]]) continue;
		if (v[a[i]] == 1 && f[a[i]] == 0) {
			std::cout << a[i] << " ";
			f[a[i]] = 1;
			cnt++;
			continue;
		}

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