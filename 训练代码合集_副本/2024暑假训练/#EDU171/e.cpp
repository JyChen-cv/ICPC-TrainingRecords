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
int a[N + 2], cnt[N + 2];
void solve() {
	for (int i = 0; i <= 70; i++) cnt[i] = 0;
	int n;
	std::cin >> n;
	for (int i = 1; i <= n; i++) {
		std::cin >> a[i];
		if (!a[i]) cnt[0]++;
		for (int j = 61; j >= 0; j--) {
			if (a[i] >= (1ll << j)) {
				cnt[j + 1]++;
				break;
			}
		}
	}

	int ans = 0;
	for (int i = 0; i <= 70; i++) {
		if (i)cnt[i] += cnt[i - 1];
		ans = std::max(ans, cnt[i] - i);
	}
	std::cout << ans << std::endl;
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