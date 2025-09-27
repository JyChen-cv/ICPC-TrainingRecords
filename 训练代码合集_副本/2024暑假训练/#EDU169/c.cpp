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
int mapp[N + 2];
bool cmp(int x, int y) {
	return x > y;
}
void solve() {
	int n, k;
	std::cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		std::cin >> mapp[i];
	}

	std::sort(mapp + 1, mapp + n + 1, cmp);
	int sum1 = 0, sum2 = 0;
	int tag = 0;
	if (n % 2) n--, tag = 1;
	for (int i = 1; i <= n; i++) {
		if (i % 2) sum1 += mapp[i];
		else sum2 += mapp[i];
	}
	int s = sum1 - sum2;
	s = std::max(0LL, s - k) + (tag ? mapp[n + 1] : 0);
	std::cout << s << std::endl;
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