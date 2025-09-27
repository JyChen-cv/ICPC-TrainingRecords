#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <cstring>

#define int long long
int lowbit(int x) {
	return x & (-x);
}
const int N = 1e5 + 3;
int trr[N + 2], tr[N + 2], n, a[N + 2], b[N + 2], c[N + 2];

void add(int p, int x) {
	while (p <= N) {
		tr[p] += x;
		p += lowbit(p);
	}
}

int find(int p) {
	int res = 0;
	while (p) {
		res += tr[p];
		p -= lowbit(p);
	}
	return res;
}

void add2(int p, int x) {
	while (p <= N) {
		trr[p] += x;
		p += lowbit(p);
	}
}

int find2(int p) {
	int res = 0;
	while (p) {
		res += trr[p];
		p -= lowbit(p);
	}
	return res;
}

signed main() {
	std::cin >> n;
	for (int i = 1; i <= n; i++) {
		std::cin >> a[i];
		a[i]++;
		add(a[i], 1);
	}
	for (int i = 1; i <= n; i++) {
		std::cin >> b[i];
		b[i]++;
		// std::cout << i << " " << find(b[i] - 1) << std::endl;
		add2(b[i], find(b[i] - 1));
	}
	int ans = 0;
	for (int i = 1; i <= n; i++) {
		std::cin >> c[i];
		c[i]++;
		// std::cout << i << " " << ans << " " << c[i] << std::endl;
		ans += find2(c[i] - 1);
	}
	std::cout << ans << std::endl;
	return 0;
}