#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>

const int N = 2e5;
int fa[N + 2], mapp[N + 2];

int find(int x) {
	if (fa[x] == x) return x;
	return fa[x] = find(fa[x]);
}

int main()
{
	int t;
	std::cin >> t;
	while (t--) {
		int n;
		std::cin >> n;
		for (int i = 1; i <= n; i++) fa[i] = i;
		int a, b = 0, tag = 0;
		for (int i = 1; i <= n; i++) {
			std::cin >> mapp[i];
			if (mapp[i] == mapp[i - 1]) fa[i] = find(tag);
			else tag = i;
		}
		int m;
		std::cin >> m;
		for (int i = 1; i <= m; i++) {
			int a, b;
			std::cin >> a >> b;
			if (find(a) == find(b)) std::cout << "-1 -1" << std::endl;
			else {
				if (mapp[a] == mapp[b]) std::cout << a << " " << find(b) - 1 << std::endl;
				else std::cout << a << " " << b << std::endl;
			}
		}
		std::cout << std::endl;
	}
	return 0;
}