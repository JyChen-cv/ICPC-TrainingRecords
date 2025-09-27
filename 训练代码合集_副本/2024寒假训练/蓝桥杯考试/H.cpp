#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>

const int N = 1e5;

struct group {
	int x, y;
} mapp[N + 2];
int v[N + 2];

bool cmp(group x, group y) {
	if (x.x > y.x)
		return 1;
	else if (x.x == y.x)
		return x.y > y.y;
	else
		return 0;
}

int main() {
	int n, m;
	std::cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		std::cin >> mapp[i].x;
		mapp[i].y = i;
	}

	for (int i = 1; i <= n; i++) {
		int tag = 0, pos = 0;
		for (int j = i; j <= n; j++) {
			if (v[j])
				continue;
			if (mapp[j].x > tag && m >= (j - i)) {
				tag = mapp[j].x;
				pos = j;
			}
		}
		if (pos == 0) {
			for (int j = i; j <= n; j++) {
				std::cout << -1 << " ";
			}
			break;
		} else {
			v[pos] = 1;
			m -= (pos - i);
			std::cout << mapp[pos].x << " ";
		}
	}
	return 0;
}
