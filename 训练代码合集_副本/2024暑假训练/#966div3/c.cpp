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
const int N = 2e5;
int mapp[N + 2];
void solve() {
	int n;
	std::cin >> n;
	for (int i = 0; i < n; i++) {
		std::cin >> mapp[i];
		if (mapp[i] == 0) mapp[i] = 1e10;
	}
	int m;
	std::cin >> m;
	for (int i = 1; i <= m; i++) {
		std::string a;
		std::cin >> a;
		if (a.size() != n) {
			puts("NO");
			continue;
		}
		int tag = 1;
		std::map<char, int> q;
		std::map<int, char> l;
		for (int j = 0; j < (int)a.size(); j++) {
			if (!q[a[j]]) {
				q[a[j]] = mapp[j];
			}
			else if (mapp[j] != q[a[j]]) tag = 0;
			if (!l[mapp[j]]) l[mapp[j]] = a[j];
			else if (a[j] != l[mapp[j]]) tag = 0;
		}
		puts(tag ? "YES" : "NO");
	}
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