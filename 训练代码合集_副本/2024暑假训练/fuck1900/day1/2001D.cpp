// https://codeforces.com/problemset/problem/2001/D
// 难度在如何写代码

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
const int N = 3e5;

int n, a[N + 2], att[N + 2];
void solve() {
	std::cin >> n;
	for (int i = 1; i <= n; i++) std::cin >> a[i], att[a[i]] = i;

	int cl = 0, cr = 0;
	std::vector<int> ans;
	while (1) {

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