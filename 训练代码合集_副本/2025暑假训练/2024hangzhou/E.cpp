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

std::vector<int> q;
std::map<int, int> mp;
int n, k;
void solve() {
	mp.clear(), q.clear();
	std::cin >> n >> k;
	int mx = 0, ans = 0;
	for (int i = 1; i <= n; i++) {
		int a, b;
		std::cin >> a >> b;
		ans += b - a;
		q.push_back(a), q.push_back(b);
		mp[a]++, mp[b]--;
	}
	std::sort(q.begin(), q.end());
	int tag = 0, ini = 0;
	for (int i = 0; i < (int)q.size(); i++) {
		tag += mp[q[i]];
		if (ini) {
			if (q[i] > k)ans += q[i] - std::max(ini, k);
			ini = 0;
		}
		if (!tag) ini = q[i];
	}
	std::cout << ans << std::endl;
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