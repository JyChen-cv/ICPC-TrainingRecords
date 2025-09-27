#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <vector>

#define int long long
const int N = 2e5;
int mapp[N + 2], mi[N + 2], cnt[N + 2];
int n, tag = 0, cnt_0 = 0;

void solve() {
	std::vector<int> q;
	q.push_back(0);
	std::cin >> n;
	cnt_0 = 0, tag = 0;
	for (int i = 0; i <= n; i++) cnt[i] = 0;
	for (int i = 1; i <= n; i++) {
		std::cin >> mapp[i];
		if (mapp[i]) q.push_back(mapp[i]);
		if (!mapp[i] && !tag) {
			q.push_back(mapp[i]), tag = 1;
		}
		if (!mapp[i]) cnt_0++;
	}
	mi[1] = mapp[1];
	for (int i = 2; i < (int)q.size(); i++) {
		mi[i] = std::min(mapp[i], mi[i - 1]);
	}

	int point = 0, sus = 1;
	for (int i = (int)q.size() - 1; i >= 2; i--) {
		if (q[i] > n) continue;
		cnt[q[i]] = 1;
		while (cnt[point]) point++;
		if (point > mi[i - 1]) sus = 0;
	}

	std::cout << ((sus && cnt_0) ? (n - cnt_0 + 1) : (n - cnt_0)) << std::endl;
}

signed main() {
	std::ios::sync_with_stdio(0);
	std::cin.tie(0), std::cout.tie(0);
	int times;
	std::cin >> times;
	while (times--) {
		solve();
	}
	return 0;
}
