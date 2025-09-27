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
void solve() {
	int n, posl = 0, posr = 0, tagl = 0, tagr = 0;
	int ans = 0;
	std::cin >> n;
	for (int i = 1; i <= n; i++) {
		int a; std::string b;
		std::cin >> a >> b;
		if (b == "L") {
			if (tagl) ans += std::abs(posl - a);
			posl = a;
			tagl = 1;
		}
		else {
			if (tagr) ans += std::abs(posr - a);
			tagr = 1;
			posr = a;
		}
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