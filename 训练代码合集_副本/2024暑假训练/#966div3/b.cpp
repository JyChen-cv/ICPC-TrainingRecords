#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <vector>
#include <queue>
#include <map>
#include <cstring>
#include <set>

#define int long long
typedef long long ll;
typedef double db;
typedef std::pair<int, int> PII;
const int N = 2e5;
int v[N + 2];
void solve() {
	int n;
	std::cin >> n;
	int tag = 1;
	for (int i = 0; i <= n + 1; i++) v[i] = 0;
	for (int i = 1; i <= n; i++) {
		int a;
		std::cin >> a;
		v[a] = 1;
		if (i == 1) continue;
		else if ((v[a - 1] | v[a + 1]) == 0) tag = 0;
	}
	puts(tag ? "YES" : "NO");
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