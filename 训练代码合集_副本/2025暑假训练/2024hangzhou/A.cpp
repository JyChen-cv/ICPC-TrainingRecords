#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <random>
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

const int N = 30;
int f[N + 2];

int find(int x) {
	if (f[x] == x) return x;
	else return f[x] = find(f[x]);
}

void solve() {
	std::string a, b, c;
	std::cin >> a >> b >> c;
	if (a.size() != b.size()) {
		std::cout << "NO" << std::endl;
		return ;
	}
	if (a.size() != c.size()) {
		std::cout << "YES" << std::endl;
		return ;
	}

	int n = a.size();
	for (int i = 0; i <= 30; i++) f[i] = i;
	for (int i = 0; i < n; i++) {
		int la = a[i] - 'a' + 1;
		int lb = b[i] - 'a' + 1;
		if (find(la) == find(lb)) continue;
		else f[find(la)] = find(lb);
	}
	int tag = 0;
	for (int i = 0; i < n; i++) {
		int la = a[i] - 'a' + 1;
		int lc = c[i] - 'a' + 1;
		if (find(la) != find(lc)) {
			tag = 1 ;
			break;
		}
	}
	std::cout << (tag ? "YES" : "NO") << std::endl;
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