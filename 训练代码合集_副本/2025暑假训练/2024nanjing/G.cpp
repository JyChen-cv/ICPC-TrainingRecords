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
const int N = 2e5, M = 4e5;
int head[N + 2], nxt[M * 2 + 2], ver[M * 2 + 2], tot, root;
int sz[N + 2], mx[N + 2], v[N + 2], S;
void add(int x, int y) {
	tot++;
	ver[tot] = y;
	nxt[tot] = head[x];
	head[x] = tot;
}

void find(int x, int fa) {
	sz[x] = 1, mx[x] = 0;
	for (int i = head[x]; i; i = nxt[i]) {
		int y = ver[i];
		if (y == fa || v[y]) continue;
		find(y, x);
		sz[x] += sz[y];
		mx[x] = std::max(mx[x], sz[y]);
	}
	mx[x] = std::max(mx[x], S - sz[x]);
	if (mx[x] < mx[root]) root = x;
}

std::vector<std::pair<int, int> > q;
void deal(int x) {
	find(x, 0);
	S = sz[x], root = 0, mx[0] = 1e9;

	// std::cout << "now: " << x << " " << S << std::endl;
	find(x, 0);
	// 先找到重心
	// std::cout << "root: " << root << std::endl;
	find(root, 0);
	q.clear();
	for (int i = head[root]; i; i = nxt[i]) {
		int y = ver[i];
		if (v[y]) continue;
		q.push_back({ -sz[y], i});
	}
	std::sort(q.begin(), q.end());
	// for (auto i : q) {
	// 	std::cout << i.first << std::endl;
	// }
	if (q.size() == 0) {
		std::cout << "! " << root << std::endl, std::cout.flush();
		return ;
	}
	else if (q.size() == 1) {
		std::cout << "? " << root << " " << ver[q[0].second] << std::endl, std::cout.flush();
		int a;
		std::cin >> a; // 只可能是0/2
		std::cout << "! " << (a ? ver[q[0].second] : root) << std::endl, std::cout.flush();
		return ;
	}

	std::cout << "? " << ver[q[0].second] << " " << ver[q[1].second] << std::endl, std::cout.flush();
	int a;
	std::cin >> a; // 可能是0/1/2
	// std::cout << "a: " << a << std::endl;
	if (a == 1) {
		if (q.size() == 2) {
			std::cout << "! " << root << std::endl, std::cout.flush();
			return ;
		}
		v[ver[q[0].second]] = v[ver[q[1].second]] = 1;
		deal(root);
	}
	else if (a == 2) {
		v[ver[q[0].second]] = v[root] = 1;
		deal(ver[q[1].second]);
	}
	else {
		v[ver[q[1].second]] = v[root] = 1;
		deal(ver[q[0].second]);
	}
}

void solve() {
	int n;
	std::cin >> n;
	tot = 0, root = 0;
	for (int i = 0; i <= n; i++) {
		head[i] = v[i] = 0;
	}
	for (int i = 1; i <= n; i++) {
		int a, b;
		std::cin >> a >> b;
		if (a) add(i, a), add(a, i);
		if (b) add(i, b), add(b, i);
	}

	deal(1);
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