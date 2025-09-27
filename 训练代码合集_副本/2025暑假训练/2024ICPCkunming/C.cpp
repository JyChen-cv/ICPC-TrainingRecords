#include <algorithm>
#include <bitset>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <unordered_map>
#include <vector>

#define int long long
typedef long long ll;
typedef double db;
typedef std::pair<int, int> PII;

inline int updiv(int x, int y) { return (x % y) ? (x / y + 1) : (x / y); }

void solve() {
	int n, k, t = 0, ini = 1;
	std::cin >> n >> k;

	if (k >= std::sqrt(n)) {
		while (n > k) {
			int ls = updiv(n, k);
			int tag = n / k * k;
			int len = updiv((n - tag), ls);
			if (!len) len = 1;
			t += len;
			n -= len * ls;
			// std::cout << n << " " << tag << " " << len << " " << t << " " <<
			// ls
			//         << std::endl;
		}
		t += (n - 1);

		int now = 1;
		while (t) {
			int tag = now * (k - 1) + 1;
			int nt = updiv(tag - ini, now);
			if (nt > t) {
				ini += t * now;
				break;
			}
			else {
				ini += nt * now;
				t -= nt;
				now ++;
			}
		}
	} else {
		while (n > 1) {
			t++;
			n -= updiv(n, k);
		}

		while (t--) {
			ini += updiv(ini, k - 1);
		}
	}
	// std::cout << t << std::endl;
	std::cout << ini << std::endl;
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
