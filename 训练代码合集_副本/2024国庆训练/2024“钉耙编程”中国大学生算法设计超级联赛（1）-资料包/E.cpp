#include <iostream>
#include <map>
using namespace std;

using ll = long long;
ll mod = 998244353LL;
#define int long long
const int N = 1e7;
int rem[N + 10], invr[N + 10];

inline ll quick(ll a , ll tim) {
	ll ans = 1;
	while (tim) {
		if (tim & 1) ans = ans * a % mod;
		a = a * a % mod;
		tim >>= 1;
	}
	return ans;
}
inline ll inv(ll i) {
	return quick(i , mod - 2);
}

int cnt[32];
inline ll C(int n, int m)
{
	if (n == 0) return 1;
	return rem[n] * invr[n - m] % mod ;
}
std::map<char , int> qqqqqq;
void solve() {
	int n, tag = 0, tot = 0, qwe = 0;
	std::cin >> n;
	for (int i = 1; i <= n; i++) {
		char a; int b;
		std::cin >> a >> b;
		cnt[++qwe] = b;
		tot += b;
		if (b % 2) tag++;
	}
// if (n == 1) {
//  std::cout << (tot % 2 ? 1 : 0 ) << std::endl;
//  return ;
// }
	if (tag >= 2) {
		std::cout << inv(2) << std::endl;
		return ;
	}
	else if (tot % 2) {
		int res = 1, lsls = 1;
		for (int i = 1; i <= n; i++) {
			if (cnt[i] % 2) {
				lsls = cnt[i];
				cnt[i]--;
			}
			res *= C(cnt[i], cnt[i] / 2);
			res %= mod;
		}
		res *= rem[tot / 2];
		res %= mod;
		res *= lsls;
		res %= mod;
		int all = rem[tot];
		// std::cout << tot << std::endl;
		// std::cout << res << " " << all << std::endl;
		int ans = (all + res) % mod * inv(2) % mod * inv(all) % mod;
		// ans = ans * lsls % mod * inv(tot + 1) % mod;
		std::cout << ans << std::endl;
		return ;
	}
	else {
		int res = 1;
		for (int i = 1; i <= n; i++) {
			res *= C(cnt[i], cnt[i] / 2);
			res %= mod;
		}
		res *= rem[tot / 2];
		res %= mod;
		int all = rem[tot];
		int ans = (all - res + mod) % mod * inv(2) % mod * inv(all) % mod;
		// std::cout << res << " " << all << std::endl;
		std::cout << ans << std::endl;
		return ;
	}
}

signed main() {
	std::ios::sync_with_stdio(0);
	std::cin.tie(0), std::cout.tie(0);
	rem[0] = 1;
	for (int i = 1; i <= (int)1e7; i++) {
		rem[i] = rem[i - 1] * i % mod;
	}
	invr[(int)1e7] = inv(rem[(int)1e7]);
	for (int i = 9999999; i >= 0; i--) invr[i] = invr[i + 1] * (i + 1) % mod;

// std::cout << C(1e7, 1e7) % mod << std::endl;
	int times;
	std::cin >> times;
	while (times--) {
		solve();
	}
	return 0;
}