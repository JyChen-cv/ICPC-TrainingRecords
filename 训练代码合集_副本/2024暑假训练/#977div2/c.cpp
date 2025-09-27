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
const int N = 2e5;
int a[N + 2], b[N + 2];
std::map<int, int> q;
void solve() {
	q.clear();
	int n, m, k;
	std::cin >> n >> m >> k;
	for (int i = 1; i <= n; i++) {
		std::cin >> a[i];
	}
	for (int i = 1; i <= m; i++) {
		std::cin >> b[i];
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