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
const int N = 1e7;
int v[N + 2];
std::vector<int> p;
int q[N + 2];
int deal(int x) {
	if (x == 1) return 1;
	if (q[x]) return q[x] = q[x];
	else return q[v[x]];
}
void solve() {
	int n, ans = 0;
	std::cin >> n;
	for (int i = 1; i <= n; i++) {
		int a;
		std::cin >> a;
		if (a % 2 == 0) continue;
		else ans ^= deal(a);
	}
	puts(ans ? "Alice" : "Bob");
}

signed main() {
	std::ios::sync_with_stdio(0);
	std::cin.tie(0), std::cout.tie(0);

	for (int i = 2; i <= 1e7; i++) {
		if (v[i] == 0) {
			v[i] = i;
			p.push_back(i);
		}
		for (int j = 0; j < p.size(); j++) {
			if (p[j] > v[i] || p[j] > 1e7 / i) break;
			v[i * p[j]] = p[j];
		}
	}
	for (int i = 0; i < (int)p.size(); i++) {
		q[p[i]] = i + 1;
	}
	int times = 1;
	std::cin >> times;
	while (times--) {
		solve();
	}
	return 0;
}