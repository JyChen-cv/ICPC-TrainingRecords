#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>

const int N = 1e6;
struct group {
	int x, y;
	bool operator < (const group &t) const {
		return y < t.y;
	}
} mapp[N + 2];
std::vector<group> s, t;

int main()
{
	int n;
	std::cin >> n;
	for (int i = 1; i <= n; i++) {
		std::cin >> mapp[i].x;
	}
	for (int i = 1; i <= n; i++) {
		std::cin >> mapp[i].y;
	}

	std::sort(mapp + 1, mapp + n + 1);
	for (int i = 1; i <= n; i++) {
		if (mapp[i].x < mapp[i].y) s.push_back(mapp[i]);
		else t.push_back(mapp[i]);
	}

	for (int i = 0; i < (int)s.size(); i++) {
		int l = std::lower_bound(t.begin(), t.end(),);
	}

	return 0;
}