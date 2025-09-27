#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <vector>
#include <algorithm>

int main()
{
	int t;
	std::cin >> t;
	while (t--) {
		int n, k;
		std::cin >> n >> k;
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= k; j++) {
				printf("%c", 'a' - 1 + j);
			}
		}
		puts("");
	}
	return 0;
}