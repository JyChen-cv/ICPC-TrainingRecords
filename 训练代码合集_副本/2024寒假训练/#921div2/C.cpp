#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <vector>
#include <algorithm>

const int N = 1e6;
char mapp[N + 2];
bool tag[30];

int main()
{
	int t;
	std::cin >> t;
	while (t--) {
		int n, k, m, num = 0, ans = 0;
		std::string occ;
		std::cin >> n >> k >> m;
		scanf("%s", mapp + 1);
		for (int i = 1; i <= m; i++) {
			if (!tag[mapp[i] - 'a' + 1] && mapp[i] <= 'a' - 1 + k) {
				tag[mapp[i] - 'a' + 1] = 1;
				num++;
			}
			if (num == k) {
				occ += mapp[i];
				ans++;
				for (int i = 1; i <= k; i++) tag[i] = 0;
				num = 0;
			}
		}
		if (ans >= n) std::cout << "YES" << std::endl;
		else {
			std::cout << "NO" << std::endl;
			for (int i = 1; i <= k; i++) {
				if (!tag[i]) {
					occ += 'a' - 1 + i;
					break;
				}
			}
			for (int i = ans + 1; i <= n; i++) {
				if (i + 1 <= n)occ += 'a';
			}
			std::cout << occ << std::endl;
		}
		for (int i = 1; i <= k; i++) tag[i] = 0;
	}
	return 0;
}