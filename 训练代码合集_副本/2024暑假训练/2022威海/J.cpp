// 题目其实是保证一开始不会出现非法的情况的

#include <algorithm>
#include <cmath>
#include <cstring>
#include <iostream>
#include <map>
#include <vector>

std::vector<std::pair<int, int> > q;
std::map<int, int> mp;
std::map<int, int>::iterator po;
int deal(int l, int r) {  // 0 -> duan  // 0 0 qingkuang yanyixia
	int mx = q[r].first;
	int sum1 = 0, cnt1 = 0;
	while ((po->first) <= mx) {
		sum1 += (po->first) * (po->second);
		cnt1 += po->first;
		po++;
	}
	sum1 -= (po->first) * (po->second), cnt1 -= po->first;
	po--;
	int sum2 = std::min(cnt1, q[l].second) * q[l].first;
	cnt1 = std::max(0, cnt1 - q[l].second);
	int lim = q[l].first;
	for (int i = l + 1; i <= r; i++) {
		if (q[i].first != q[i - 1].first + 1)
			break;
		else {
			lim = q[i].first;
			sum2 += std::min(cnt1, q[i].second) * q[i].first;
			cnt1 = std::max(0, cnt1 - q[i].second);
		}
	}
	if (cnt1) {
		sum2 += (lim + 1) * cnt1;  // buhui buhefa
	}
	// shifoubaozheng yikaishi hefa
	return sum1 - sum2;
}

void solve() {
	int n, k;
	mp.clear(), q.clear();
	std::cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		int a;
		std::cin >> a;
		mp[a]++;
	}
	for (int i = 1; i <= k; i++) {
		int a, b;
		std::cin >> a >> b;
		q.push_back({a, b});
	}
	q.push_back({0, 1e9});
	std::sort(q.begin(), q.end());
	po = mp.begin();
	int cnt = 0, poi = 0;
	while (poi < (int)q.size()) {
		while (poi < (int)q.size()) {

		}
	}

	if (cnt % 2)
		puts("Pico");
	else
		puts("FuuFuu");
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

/*
5
2 0
1 2
2 1
1 2
0 1
3 2
3 3 4
0 2
1 1
3 2
2 3 3
1 2
0 1
5 4
6 7 8 12 17
1 1
2 1
9 0
10 1
*/