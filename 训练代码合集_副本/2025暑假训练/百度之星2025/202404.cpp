#include <algorithm>
#include <cmath>
#include <cstring>
#include <iostream>

#define int long long
const int mod = 998244353;
const int N = 5000;
/*
 * mapp[i][0]表示花费为i的代价下，没有匹配到任何字符串的方案数
 * mapp[i][1]表示花费为i的代价下，匹配到1位到方案数
 * mapp[i][2]表示花费为i的代价下，匹配到2位到方案数
 * 最后一位是滚动数组
 */
int mapp[N + 2][3][2];
void solve() {
	int n, k, rol = 0;  // rol 是滚动变量
	std::string s;
	std::cin >> n >> k >> s;
	s = '0' + s;
	mapp[0][0][0] = 1;  // 初始化
	for (int i = 1; i < (int)s.size(); i++) {
		rol ^= 1;
		for (int j = 0; j <= k; j++) {
			if (s[i] == '1') {
				mapp[j][1][rol] = mapp[j][0][rol ^ 1];
				mapp[j][2][rol] = mapp[j][1][rol ^ 1] + mapp[j][2][rol ^ 1];
				if (j)
					mapp[j][0][rol] =
					    mapp[j - 1][1][rol ^ 1] + mapp[j - 1][0][rol ^ 1],
					mapp[j][0][rol] %= mod;
			} else {
				mapp[j][0][rol] = mapp[j][1][rol ^ 1] + mapp[j][0][rol ^ 1],
				mapp[j][0][rol] %= mod;
				if (j) mapp[j][1][rol] = mapp[j - 1][0][rol ^ 1];
				if (j)
					mapp[j][2][rol] =
					    mapp[j - 1][1][rol ^ 1] + mapp[j - 1][2][rol ^ 1];
			}
		}
		for (int j = 0; j <= k; j++) {
			mapp[j][0][rol ^ 1] = mapp[j][1][rol ^ 1] = mapp[j][2][rol ^ 1] = 0;
		}
		// std::cout << i << ": \n";
		// std::cout << mapp[0][0][rol] << " " << mapp[0][1][rol] << " "
		//           << mapp[0][2][rol] << std::endl;
	}
	int ans = 0;
	for (int i = 0; i <= k; i++) {
		// std::cout << i << ": \n";
		// std::cout << mapp[i][0][rol] << " " << mapp[i][1][rol] << " "
		//           << mapp[i][2][rol] << std::endl;

		ans +=
		    ((mapp[i][0][rol] + mapp[i][1][rol]) % mod + mapp[i][2][rol]) % mod;
		ans %= mod;
	}
	std::cout << ans << std::endl;
}

signed main() {
	std::ios::sync_with_stdio(0);
	std::cin.tie(0), std::cout.tie(0);
	int times = 1;
	while (times--) {
		solve();
	}
	return 0;
}
