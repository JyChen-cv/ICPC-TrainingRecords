#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>

int cnt, mon[14] = {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
bool check(int x) {
	if (x % 400 == 0)
		return 1;
	else if (x % 100 == 0)
		return 0;
	else if (x % 4 == 0)
		return 1;
	else
		return 0;
}

int num[12] = {13, 1, 2, 3, 5, 4, 4, 2, 2, 2};
int deal(int x, int y, int z) {
	int all = 0;
	while (x) {
		int res = x % 10;
//		std::cout << res << " " << all << std::endl;
		all += num[res];
		x /= 10;
	}
	if (y <= 9)
		all += num[0] + num[y];
	else {
		while (y) {
			int res = y % 10;
			all += num[res];
			y /= 10;
		}
	}
	if (z <= 9)
		all += num[0] + num[z];
	else {
		while (z) {
			int res = z % 10;
			all += num[res];
			z /= 10;
		}
	}
//	std::cout << all << std::endl;
	return all > 50;
}

void dfs(int y, int m, int d) {
	if (d > mon[m]) {
		d = 1;
		m++;
	}
	if (m > 12) {
		m = 1;
		y++;
		if (check(y))
			mon[2] = 29;
		else
			mon[2] = 28;
	}
	if (y == 2024 && m == 4 && d == 14)
		return ;
	std::cout << y << " " << m << " " << d << std::endl;
	if (deal(y, m, d))
		cnt++;
	dfs(y, m, d + 1);
}

int main() {
	dfs(2000, 1, 1);
//	deal(2000, 1, 1);
	std::cout << cnt << std::endl;
	return 0;
}
