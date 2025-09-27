#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <queue>
#include <vector>

const int N = 2e5;
int head[N + 2], nxt[N * 2 + 2], ver[N * 2 + 2], tot;
int v[N + 2], du[N + 2], s[N + 2];

struct group {
	int p;
	bool operator < (const group &t) const {
		return s[p] > s[t.p];
	}
};
void add(int x, int y)
{
	tot++;
	ver[tot] = y;
	nxt[tot] = head[x];
	head[x] = tot;
	du[y]++;
}

int main()
{
	std::ios::sync_with_stdio(0);
	std::cin.tie(0);
	int n;
	std::cin >> n;
	if (n == 1) {
		std::cout << "YES" << std::endl;
		return 0;
	}
	for (int i = 1; i < n; i++) {
		int a, b;
		std::cin >> a >> b;
		add(a, b);
		add(b, a);
	}

	std::priority_queue<group> q;
	for (int i = 1; i <= n; i++) {
		s[i] = 1;
		if (du[i] == 1) {
			q.push({i});
			v[i] = 1;
		}
	}

	// v[0] = 1;
	while (q.size()) {
		int x = q.top().p;
		// std::cout << x << std::endl;
		q.pop();
		for (int i = head[x]; i; i = nxt[i]) {
			int y = ver[i];
			if (v[y]) continue;
			if (s[y] < s[x]) {
				// if (n - s[x] > s[x] && du[y] > 2) q.push(x);
				continue;
			}
			du[y]--;
			s[y] += s[x];
			s[x] = 0;
			if (du[y] == 1) {
				q.push({y});
				v[y] = 1;
			}
		}
	}
	int tag = 1;
	for (int i = 1; i <= n; i++) {
		if (v[i] == 0) {
			tag = 0;
			// std::cout << i << std::endl;
		}
	}
	std::cout << (tag ? "YES" : "NO") << std::endl;
	return 0;
}