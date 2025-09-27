#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <vector>

const int N = 2e5;
std::pair<int, int> mapp[N + 2];

int main()
{
	int t;
	std::cin >> t;
	while (t--) {
		int n;
		std::cin >> n;
		for (int i = 1; i <= n; i++) {
			std::cin >> mapp[i].first;
		}
		for (int i = 1; i <= n; i++) {
			std::cin >> mapp[i].second;
		}
		std::sort(mapp + 1, mapp + n + 1);
		for (int i = 1; i <= n; i++) {
			std::cout << mapp[i].first << " ";
		}
		puts("");
		for (int i = 1; i <= n; i++) {
			std::cout << mapp[i].second << " ";
		}
		puts("");
	}
	return 0;
}