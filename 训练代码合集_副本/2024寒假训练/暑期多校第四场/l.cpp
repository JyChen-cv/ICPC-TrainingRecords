#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>

const int N = 1e6;
#define int long long
struct group {
	std::string a, c;
	int b;
	void in() {
		std::cin >> a >> b >> c;
	}
} mapp[N + 2];
bool bm[N + 2], bn[N + 2];
int ans = 0;

signed main()
{
	std::ios::sync_with_stdio(0);
	std::cin.tie(0);

	int n, m, k;
	std::cin >> n >> m >> k;
	for (int i = 1; i <= k; i++) {
		mapp[i].in();
	}
	for (int i = k; i >= 1; i--) {
		if (mapp[i].a == "row") {
			if (bn[mapp[i].b]) continue;
			if (mapp[i].c == "on") {
				ans += m;
			}
			n--;
			bn[mapp[i].b] = 1;
		}
		else {
			if (bm[mapp[i].b]) continue;
			if (mapp[i].c == "on") {
				ans += n;
			}
			m--;
			bm[mapp[i].b] = 1;
		}
	}
	std::cout << ans << std::endl;
	return 0;
}