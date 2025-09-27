#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <vector>
#include <queue>
#include <map>
#include <cstring>
#include <set>

typedef long long ll;
typedef double db;
typedef std::pair<int, int> PII;
void solve() {
	ll n, m, k;
	std::cin >> n >> m >> k;
	if (n > k) n = k;
	if (m > k) m = k;
	std::cout << ( m * n ) << std::endl;
}
int main() {
	std::ios::sync_with_stdio(0);
	std::cin.tie(0), std::cout.tie(0);
	int times = 1;
	std::cin >> times;
	while (times--) {
		solve();
	}
	return 0;
}