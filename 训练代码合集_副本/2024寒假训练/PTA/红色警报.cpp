#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>

const int N = 1e5;
int head[N + 2], nxt[N + 2], ver[N + 2], tot;
int v[N + 2], fa[N + 2];

void add(int x, int y) {
	tot++;
	ver[tot] = y;
	nxt[tot] = head[x];
	head[x] = tot;
}

int find(int x) {
	if (fa[x] == x) return x;
	else return fa[x] = find(fa[x]);
}

void deal(int x) {
	int fx = find(x);
	for (int i = head[x]; i; i = nxt[i]) {
		int y = ver[i];
		int fy = find(y);
		if (fy != fx) fa[fy] = fx;
	}
}

int check(int x) {
	// std::cout << x << std::endl;
	int fx = find(x), tag = -1, res = 0;
	for (int i = head[x]; i; i = nxt[i]) {
		int y = ver[i];
		if (v[y] == 1) continue;
		int fy = find(y);
		if (fy != tag && tag != -1) {
			res = 1;
		}
		tag = fy;
	}
	for (int i = head[x]; i; i = nxt[i]) {
		int y = ver[i];
		if (v[y] == 1) continue;
		int fy = find(y);
		if (fy != fx) fa[fy] = fx;
	}
	return res;
}

int main()
{
	std::ios::sync_with_stdio(0);
	std::cin.tie(0);
	// std::cout.tie(0);

	int n, m;
	std::cin >> n >> m;
	for (int i = 1; i <= n; i++) fa[i] = i;
	for (int i = 1; i <= m; i++) {
		int a, b;
		std::cin >> a >> b;
		a++, b++;
		add(a, b);
		add(b, a);
	}
	int k;
	std::cin >> k;
	std::vector<int> q;
	for (int i = 1; i <= k; i++) {
		int a;
		std::cin >> a;
		a++;
		q.push_back(a);
		v[a] = 1;
	}
	for (int i = 1; i <= n; i++) {
		if (v[i] == 0) deal(i);
	}

	std::vector<std::pair<int, int>> ans;
	for (int i = (int)q.size() - 1; i >= 0; i--) {
		v[q[i]] = 0;
		ans.push_back(std::make_pair(check(q[i]), q[i] - 1));
		// for (int i = 1; i <= n; i++) {
		// std::cout << fa[i] << " ";
		// }
		// std::cout << std::endl;
	}
	for (int i = (int)ans.size() - 1; i >= 0; i--) {
		if (ans[i].first) std::cout << "Red Alert: City " << ans[i].second << " is lost!";
		else std::cout << "City " << ans[i].second << " is lost.";
		if (i > 0) std::cout << std::endl;
	}
	if (k == n) std::cout << std::endl << "Game Over.";
	return 0;
}