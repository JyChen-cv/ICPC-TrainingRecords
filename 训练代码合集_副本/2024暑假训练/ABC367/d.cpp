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
std::map<int, int> q;
const int N = 2e5;
int n, m, a[N * 2 + 2];
void solve() {
	q.clear();
	std::cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		std::cin >> a[i];
		a[i + n] = a[i];
	}
	for (int i = 1; i <= n * 2; i++) a[i] += a[i - 1];
	// q[0]++;
	for (int i = 1; i < n; i++) {
		q[a[i] % m]++;
	}
	int ans = 0;
	for (int i = n; i < n * 2; i++) {
		ans += q[a[i] % m];
		q[a[i - n + 1] % m]--;
		q[a[i] % m]++;
	}
	std::cout << ans << std::endl;
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