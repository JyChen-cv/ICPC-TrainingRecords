// https://codeforces.com/problemset/problem/1991/E

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

const int N = 2e4, M = 2e4;
int head[N + 2], nxt[M * 2 + 2], ver[M * 2 + 2], edge[M * 2 + 2], tot;
void add(int x, int y, int z = 0) {
	tot++;
	edge[tot] = z;
	ver[tot] = y;
	nxt[tot] = head[x];
	head[x] = tot;
}

int f[N + 2];
inline int find(int x) {
	if (x == f[x]) return f[x] = x;
	else return f[x] = find(f[x]);
}

int n, m;
void solve() {
	std::cin >> n >> m;
	tot = 0;
	for (int i = 1; i <= n; i++) head[i] = 0;
	for (int i = 1; i <= n * 2; i++) f[i] = i;
	for (int i = 1; i <= m; i++) {
		int a, b;
		std::cin >> a >> b;
		add(a, b), add(b, a);
	}
	int tag = 1;
	for (int x = 1; x <= n; x++) {
		for (int i = head[x]; i; i = nxt[i]) {
			int y = ver[i];
			int lx = find(x), ly = find(y);
			if (lx == ly) tag = 0;
			f[ly] = find(x + n); f[lx] = find(y + n);
		}
	}

	int a, b;
	if (tag) {
		std::vector<int> q1, q2;
		for (int i = 1; i <= n; i++) {
			if (find(i) == find(1)) q1.push_back(i);
			else q2.push_back(i);
		}
		std::cout << "Bob" << std::endl;

		for (int i = 1; i <= n; i++) {
			std::cin >> a >> b;
			if (a > b) std::swap(a, b);
			if (a == 1 && q1.size()) {
				std::cout << q1.back() << " " << 1 << std::endl; q1.pop_back();
			}
			else if ((a == 2 || b == 2 ) && q2.size()) {
				std::cout << q2.back() << " " << 2 << std::endl; q2.pop_back();
			}
			else {
				if (q1.size()) {std::cout << q1.back() << " " << 3 << std::endl; q1.pop_back();}
				else {std::cout << q2.back() << " " << 3 << std::endl; q2.pop_back();}
			}
		}
	}
	else {
		std::cout << "Alice" << std::endl;
		for (int i = 1; i <= n; i++) {
			// std::cout << 1 << std::endl;
			std::cout << "1 2\n";
			std::cin >> a >> b;
		}
	}
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