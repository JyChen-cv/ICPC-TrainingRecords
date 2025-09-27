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
int a[N + 2], rem[N + 2], v[N + 2];
std::string b;
int f[N + 2];
int find(int x) {
	if (x == f[x]) return f[x] = x;
	else return f[x] = find(f[x]);
}
void dfs(int x) {
	if (v[x]) return ;
	v[x] = 1;
	f[find(a[x])] = find(x);
	rem[find(x)] += b[x] == '0';
	dfs(a[x]);
}
void solve() {
	int n;
	std::cin >> n;
	for (int i = 1; i <= n; i++) f[i] =  i, rem[i] = v[i] = 0;
	for (int i = 1; i <= n; i++) {
		std::cin >> a[i];
		rem[i] = 0;
	}
	std::cin >> b; b = 'a' + b;
	for (int i = 1; i <= n; i++) {
		dfs(i);
		std::cout << rem[find(i)] << " \n"[i == n];
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