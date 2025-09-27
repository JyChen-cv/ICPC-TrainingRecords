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
int cnt[N + 5], n, k;
void solve() {
	std::cin >> n >> k;
	int tag = 0;
	for (int i = 0; i <= n + 2; i++) cnt[i] = 0;
	for (int i = 1; i <= n; i++) {int a; std::cin >> a; if (a <= n + 2) cnt[a]++;}
	for (int i = 0; i <= n + 2; i++) {
		// std::cout << i << " " << cnt[i] << std::endl;
		if (cnt[i] <= 0) {tag = i; break;}
		if (i + k <= n + 2) cnt[i + k] += cnt[i] - 1;
	}
	std::cout << tag << std::endl;

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