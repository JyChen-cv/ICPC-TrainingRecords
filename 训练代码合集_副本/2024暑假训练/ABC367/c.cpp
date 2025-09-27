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
std::vector<int> q;
int n, k;
int a[10], sum = 0;
void dfs(int x) {
	if (x == n + 1) {
		if (sum % k == 0) {
			for (auto i : q) std::cout << i << " ";
			std::cout << std::endl;
		}
		return ;
	}
	for (int i = 1; i <= a[x]; i++) {
		q.push_back(i);
		sum += i;
		dfs(x + 1);
		sum -= i;
		q.pop_back();
	}
}
void solve() {
	std::cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		std::cin >> a[i];
	}
	dfs(1);
}

signed main() {
	std::ios::sync_with_stdio(0);
	std::cin.tie(0), std::cout.tie(0);
	int times = 1;
	// std::cin >> times;
	while (times--) {
		solve();
	}
	return 0;
}