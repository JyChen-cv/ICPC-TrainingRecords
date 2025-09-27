#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>

typedef int ll;
int pri[2000000 + 2];
int nx = 0;
bool tag[20000005], data[20000005];

inline ll cul(ll x)
{
	ll res = 1;
	for (int i = 0; i < nx; i++) {
		ll v = pri[i], cnt = 0;
		if (v * v > x) break;
		while (x % v == 0) {
			cnt++;
			x /= v;
		}
		res *= (cnt + 1);
	}
	if (x != 1) res *= 2;
	return res;
}
int tot = 0;
void deal(int n) {
	for (int i = 0; i < n; i++) data[i] = 1;
	for (int i = 2; i < n; i++) {
		if (data[i]) {
			pri[nx++] = i;
		}
		for (int j = 0; pri[j] <= i && pri[j] * i <= n && j < nx; j++)
		{
			data[i * pri[j]] = false;
			if (i % pri[j] == 0) break;
			tot++;
		}
	}
}

int main()
{
	deal(20000000);
//    std::cout<<tot<<' '<<nx<<std::endl;

	int n, ans = 0;
	std::cin >> n;
	for (int i = 0; i < nx; i++) {
		ll ls = n - pri[i];
		if (ls <= 0) break;
		ll res = cul(ls);
		if (res != 2) ans += res;
		// std::cout << ls << " " << cul(ls) << std::endl;
	}
	std::cout << ans << std::endl;
	return 0;
}