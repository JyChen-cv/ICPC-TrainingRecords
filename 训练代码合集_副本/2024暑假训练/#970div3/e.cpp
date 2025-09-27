#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <iterator>
#include <string>
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
int cnt[2][30], d[2][30], ls[2][30];
void solve() {
	int n;
	std::string a;
	std::cin >> n >> a;
	for (int i = 0; i < 28; i++) cnt[0][i] = cnt[1][i] = 0, d[0][i] = d[1][i] = 0;
	if (n == 1) {
		std::cout << 1 << std::endl;
		return ;
	}
	if (n % 2) {
		int ans = 0;
		for (int i = 0; i < (int)a.size(); i++) {
			cnt[i % 2][a[i] - 'a' + 1]++;
		}
		for (int i = a.size() - 1; i >= 0; i -= 1) {
			for (int j = 1; j <= 26; j++) {
				ls[0][j] = cnt[0][j] - d[0][j] + d[1][j];
				ls[1][j] = cnt[1][j] - d[1][j] + d[0][j];
			}
			ls[i % 2][a[i] - 'a' + 1]--;
			// std::cout << ls[0][1] << " " << ls[0][2] << " " << ls[1][1] << " " << ls[1][2] << std::endl;
			int mx1 = 0, mx2 = 0;
			for (int j = 1; j <= 26; j++) {
				mx1 = std::max(mx1, ls[0][j]);
				mx2 = std::max(mx2, ls[1][j]);
			}
			ans = std::max(ans, mx1 + mx2);
			d[i % 2][a[i] - 'a' + 1]++;
			// d[(i % 2) ^ 1][a[i - 1] - 'a' + 1]++;
		}
		// std::cout << ans << std::endl;
		int k = n / 2;
		ans = k * 2 - ans + 1;
		std::cout << ans << std::endl;
	}
	else {
		int ans = 0;
		for (int i = 0; i < (int)a.size(); i++) {
			cnt[i % 2][a[i] - 'a' + 1]++;
		}
		int mx1 = 0, mx2 = 0;
		for (int i = 1; i <= 26; i++) {
			mx1 = std::max(mx1, cnt[0][i]);
			mx2 = std::max(mx2, cnt[1][i]);
		}
		int k = n / 2;
		ans += k * 2 - mx1 - mx2;
		std::cout << ans << std::endl;
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