#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <vector>
#include <queue>
#include <map>
#include <unordered_map>
#include <cstring>
#include <set>
#include <bitset>

#define int long long
typedef long long ll;
typedef double db;
typedef std::pair<int, int> PII;

const int N = 1e5;
int n, k;
struct node {
	int x, y, num;
	bool operator<(const node &t) const {
		if (x == t.x) return y < t.y;
		else return x < t.x;
	}
};
std::vector<node > q, res;

bool contain(int x, node p) {
	if (p.y > x && p.x <= x) return 1;
	else return 0;
}

bool cmp(node a, node b) {
	return a.y > b.y;
}

void solve() {
	q.clear(), res.clear();
	int ans = 0;
	std::vector<int> op;
	std::cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		int a, b;
		std::cin >> a >> b;
		q.push_back({a, b, i});
		ans += b - a;
	}
	std::sort(q.begin(), q.end());

	for (auto i : q) {
		if (i.y <= k) {
			res.push_back(i);
			continue;
		}
		if (contain(k, i)) k = i.y;
		else {
			ans += i.x - k;
			k = i.y;
		}
		op.push_back(i.num);
	}

	std::sort(res.begin(), res.end(), cmp);
	for (auto i : res) op.push_back(i.num);
	std::cout << ans << std::endl;
	for (auto i : op) std::cout << i << " ";
	std::cout << std::endl;
}

signed main() {
	std::ios::sync_with_stdio(0);
	std::cin.tie(0), std::cout.tie(0);
	int times = 1;
	std::cin >> times;
	while (times--) {
		solve();
	}
	return 0;
}