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
const int N = 1e6;
int mapp[N + 2];
void solve() {
	int n;
	std::cin >> n;
	int mx = -1e12, mi = 1e12;
	int sum1 = 0, sum2 = 0;
	for (int i = 1; i <= n; i++) {
		std::cin >> mapp[i];
		mx = std::max(mx, mapp[i]), mi = std::min(mi, mapp[i]);
		if (mapp[i] < 0) sum1 += mapp[i];
		else sum2 += mapp[i];
	}
	if (n == 1) std::cout << mapp[1] << std::endl;
	else if (mx < 0) std::cout << (mx * 2 - sum1) << std::endl;
	else if (mi > 0) std::cout << (sum2 - mi * 2) << std::endl;
	else std::cout << (-sum1 + sum2) << std::endl;
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