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
char a[6] = {'0', 'a', 'e', 'i', 'o', 'u'};
void solve() {
	int n;
	std::cin >> n;
	int k = n / 5;
	if (n % 5) k++;
	for (int i = 1; i <= 5; i++) {
		if (i <= (n % 5 ? (n % 5) : 5))
			for (int j = 1; j <= k; j++) {
				std::cout << a[i];
			}
		else
			for (int j = 1; j < k; j++) {
				std::cout << a[i];
			}
	}
	std::cout << std::endl;
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