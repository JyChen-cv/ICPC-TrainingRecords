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

#define int long long
typedef long long ll;
typedef double db;
typedef std::pair<int, int> PII;
const int N = 1000;
int f[N + 2];
int find(int x) {
	if (x == f[x]) return f[x] = x;
	else return f[x] = find(f[x]);
}
void solve() {
	int n;
	std::cin >> n;
	std::vector<int> ans;
	for (int i = 1; i <= n; i++) f[i] = i;
	for (int i = 1; i < n; i++) {
		for (int j = 1; j <= n; j++) {
			int ls = i;
			while (find(ls) != find(j)) {
				std::cout << "? " << ls << " " << j << std::endl;
				std::cout.flush();
				int a;
				std::cin >> a;
				if (a == ls || a == j) {
					f[find(ls)] = find(j);
					ans.push_back(ls), ans.push_back(j);
					break;
				}
				else ls = a;
			}
		}
	}
	std::cout << "! ";
	for (auto i : ans) std::cout << i << " ";
	std::cout << std::endl;
	std::cout.flush();
}

signed main() {
	// std::ios::sync_with_stdio(0);
	// std::cin.tie(0), std::cout.tie(0);
	int times = 1;
	std::cin >> times;
	while (times--) {
		solve();
	}
	return 0;
}