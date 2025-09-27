#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>

#define int long long
int mapp[10][10], cnt = 0;

bool check() {
	for (int i = 1; i <= 5; i++) {
		int tag = 0;
		for (int j = 2; j <= 5; j++) {
			if (mapp[i][j] != mapp[i][j - 1])
				tag = 1;
		}
		if (tag == 0)
			return 0;
	}
//	std::cout << 1 << std::endl;
	for (int j = 1; j <= 5; j++) {
		int tag = 0;
		for (int i = 2; i <= 5; i++) {
			if (mapp[i][j] != mapp[i - 1][j])
				tag = 1;
		}
		if (tag == 0)
			return 0;
	}
//	std::cout << 2 << std::endl;
	int tag = 0;
	for (int i = 2; i <= 5; i++) {
		if (mapp[i][i] != mapp[i - 1][i - 1])
			tag = 1;
	}
	if (tag == 0)
		return 0;
//	std::cout << 3 << std::endl;
	tag = 0;
	for (int i = 2; i <= 5; i++) {
		if (mapp[i - 1][5 + 2 - i] != mapp[i][5 + 1 - i])
			tag = 1;
	}
	if (tag == 0)
		return 0;
	else
		return 1;
}

void dfs(int x, int y, int num1, int num2) {
	if (y > 5) {
		y = 1;
		x++;
	}
	if (x > 5) {
		if (check())
			cnt++;
		return ;
	}
//	std::cout << x << " " << y << std::endl;
	if (num1) {
		mapp[x][y] = 1;
		dfs(x, y + 1, num1 - 1, num2);
	}
	if (num2) {
		mapp[x][y] = 0;
		dfs(x, y + 1, num1, num2 - 1);
	}
}

signed main() {
	dfs(1, 1, 13, 12);
	std::cout << cnt << std::endl;
//	mapp[1][1] = 0, mapp[1][2] = 0, mapp[1][3] = 1, mapp[1][4] = 0, mapp[1][5] = 1;
//	mapp[2][1] = 1, mapp[2][2] = 1, mapp[2][3] = 0, mapp[2][4] = 1, mapp[2][5] = 1;
//	mapp[3][1] = 1, mapp[3][2] = 1, mapp[3][3] = 1, mapp[3][4] = 0, mapp[3][5] = 1;
//	mapp[4][1] = 1, mapp[4][2] = 1, mapp[4][3] = 0, mapp[4][4] = 1, mapp[4][5] = 1;
//	mapp[5][1] = 1, mapp[5][2] = 1, mapp[5][3] = 0, mapp[5][4] = 1, mapp[5][5] = 0;
//	std::cout << check() << std::endl;
	return 0;
}
