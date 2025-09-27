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
const int N = 100;
int v[N + 2];
void solve() {
	std::string a, b;
	std::cin >> a >> b;
	int ans = 0;
	for (int i = 0; i < (int)a.size(); i++) {
		if (a[i] == b[i]) continue;
		if (a[i] > b[i]) {
			v[i] = 1;
		}
		else {
			v[i] = -1;
		}
		ans++;
	}
	std::cout << ans << std::endl;
	for (int i = 0; i < (int)a.size(); i++) {
		if (v[i] > 0) {
			a[i] = b[i];
			std::cout << a << std::endl;
		}
	}
	for (int i = (int)a.size() - 1; i >= 0; i--) {
		if (v[i] < 0) {
			a[i] = b[i];
			std::cout << a << std::endl;
		}
	}
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