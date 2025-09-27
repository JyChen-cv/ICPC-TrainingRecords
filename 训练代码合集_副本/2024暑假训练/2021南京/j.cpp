#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <vector>
#include <queue>
#include <map>
#include <cstring>
#include <set>

#define int long long
typedef long long ll;
typedef double db;
typedef std::pair<int, int> PII;
std::vector<int> pol;
bool v[100005];
std::map<PII, int> rem;
int deal(int x, int y) {
	if (rem[ {x, y}]) return rem[ {x, y}];
	int k = y - x;
	if (x == 1 || y == 1) return 0;
	if (k == 1) return x - 1;

	std::vector<int> q;
	for (int i = 0; i < (int)pol.size(); i++) {
		if (pol[i] > k) break;
		int tag = 0;
		while (k % pol[i] == 0) {
			k /= pol[i];
			tag = 1;
		}
		if (tag) q.push_back(pol[i]);
	}
	if (k != 1) q.push_back(k);
	int res = 1e9;
	for (int i = 0; i < (int)q.size(); i++) {
		// if (q[i] > x) break;
		int lst = x % q[i];
		res = std::min(res, deal(x / q[i], y / q[i]) + lst + 1);
		res = std::min(res, deal(x / q[i] + 1, y / q[i] + 1) + q[i] - lst + 1);
	}
	return rem[ {x, y}] = std::min(res, x - 1);
}
void solve() {
	rem.clear();
	int a, b;
	std::cin >> a >> b;
	if (a > b) std::swap(a, b);
	std::cout << deal(a, b) << std::endl;
}

signed main() {
	std::ios::sync_with_stdio(0);
	std::cin.tie(0), std::cout.tie(0);
	for (int i = 1; i <= 1e5; i++) v[i] = 1;
	for (int i = 2; i <= 1e5; i++) {
		if (!v[i]) continue;
		pol.push_back(i);
		for (int j = 2; j * i <= 1e5; j++) {
			v[i * j] = 0;
		}
	}
	int times = 1;
	std::cin >> times;
	while (times--) {
		solve();
	}
	return 0;
}