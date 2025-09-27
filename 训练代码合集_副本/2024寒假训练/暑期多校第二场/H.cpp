#include <iostream>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <vector>
#include <algorithm>

typedef long long ll;
const int N = 2e5;
int qian[N + 2], hou[N + 2], n, m;
char mapp[N + 2];
ll ask, pw[100];
std::vector<int> pos, sum;

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
	scanf("%d%d", &n, &m);
	scanf("%s", mapp + 1);
	int ls = -1;
	pos.push_back(0);
	for (int i = 1; i <= n; i++) {
		if (mapp[i] == 'B') {
			pos.push_back(i);
			ls = i;
		}
		qian[i] = ls;
	}
	pos.push_back(n + 1);
	ls = -1;
	for (int i = n; i >= 1; i--) {
		if (mapp[i] == 'B') {
			ls = i;
		}
		hou[i] = ls;
	}
	sum.push_back(0);
	int t = 1;
	for (int i = 1; i < (int)pos.size(); i++) {
		sum.push_back(sum[((int)sum.size() - 1)] + (t = ((pos[i] - pos[i - 1] - 1) % 2 ? -t : t)) );
	}
	// for (int i = 0; i < (int)sum.size(); i++) {
	// 	std::cout << pos[i] << " " << sum[i] << std::endl;
	// }

	for (int i = 1; i <= m; i++) {
		int lls, rls, l, r;
		scanf("%d%d", &lls, &rls);
		char c[100];
		scanf("%s", c + 1);
		l = std::min((ask ^ lls) % n + 1, (ask ^ rls) % n + 1);
		r = std::max((ask ^ lls) % n + 1, (ask ^ rls) % n + 1);
		// std::cout << l << " " << r << " " << ask << std::endl;
		ask = 0;
		int len = strlen(c + 1);
		for (int j = 1; j <= len;  j++) {
			// std::cout << c[j] << " ";
			ask *= 2;
			ask += c[j] - '0';
		}
		// std::cout << ask << std::endl;
		int ll = hou[l];
		int rr = qian[r];
		long long add = std::abs(sum[rr] - sum[ll - 1]);
		// std::cout << pos[ll] << " " << pos[rr] << " " << add << " " << ll << " " << rr << std::endl;


		int zhuanfan =  r - l + 1 - (rr - ll + 1);
		if (hou[l] > r) {
			zhuanfan = (r - l + 1) % 2;
			if (zhuanfan % 2) ask ^= (pw[len] - 1);
			output(ask, len);
			continue;
		}
		// if (mapp[l] != 'B') {
		// 	fanzhuan = (hou[l] - l) % 2;
		// }
		ask += (zhuanfan % 2 ? -1 : 1) * add;

		if (zhuanfan % 2) {
			ask ^= (pw[len] - 1);
		}
		ask %= pw[len];
		// std::cout << zhuanfan << std::endl;
		output(ask, len);
	}
	return 0;
}