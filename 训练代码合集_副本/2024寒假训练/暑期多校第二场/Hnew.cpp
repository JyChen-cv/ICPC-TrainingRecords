#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>

typedef long long ll;
const int N = 2e5;
char mapp[N + 2];
int n, m, qian[N + 2], hou[N + 2], tag[N + 2];
ll ans, ask, sum[N + 2] , pw[100];

void output(long long x, int y) {
	// std::cout << x << " " << y << std::endl;
	for (int i = y - 1; i >= 0; i--) {
		if (x >= pw[i]) {
			printf("%d", 1);
			x -= pw[i];
		}
		else printf("%d", 0);
	}
	puts("");
}

int main()
{
	pw[0] = 1;
	for (int i = 1; i <= 55; i++) pw[i] = pw[i - 1] * 2;

	std::cin >> n >> m;
	scanf("%s", mapp + 1);
	int ls = 0;
	ll q = 0, t = 1;
	for (int i = 1; i <= n; i++) {
		if (mapp[i] == 'B') {
			qian[i] = i;
			sum[i] = q + (t = (i - ls + 1) % 2 ? -t : t);
			tag[i] = t;
			q = sum[i];
			ls = i;
		}
		else qian[i] = ls;
	}
	ls = n + 1;
	for (int i = n; i >= 1; i--) {
		if (mapp[i] == 'B') {
			hou[i] = i;
			ls = i;
		}
		else hou[i] = ls;
	}
	// for (int i = 1; i <= n; i++) {
	// 	std::cout << tag[i] << " ";
	// }
	// puts("");

	for (int i = 1; i <= m; i++) {
		int ls, rs, l, r, len;
		char c[100];
		scanf("%d%d%s", &ls, &rs, c + 1);
		l = std::min((ls ^ ans) % n + 1, (rs ^ ans) % n + 1);
		r = std::max((ls ^ ans) % n + 1, (rs ^ ans) % n + 1);
		len = strlen(c + 1);
		for (int j = 1; j <= len; j++) {
			ask *= 2;
			ask += c[j] - '0';
		}

		if (hou[l] > r) {
			output(ans = ((r - l + 1) % 2 ? -1 : 1) * ask, len);
			continue;
		}
		ll add = sum[qian[r]] - sum[qian[l]];
		std::cout << l << " " << r << " " << add << std::endl;
		add *= tag[i];
		int fanzhuan = (hou[l] - l) % 2;
		if (fanzhuan) add *= -1;

		ans = ask + add;
		ans %= pw[len];
		int zhuanfan = (r - qian[r]) % 2;
		zhuanfan ? output(ans ^= (pw[len] - 1), len) : output(ans, len);
	}
	return 0;
}