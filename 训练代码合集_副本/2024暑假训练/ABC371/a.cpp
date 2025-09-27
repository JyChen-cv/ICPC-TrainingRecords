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
int a1, a2, a3;
char a[4];
void solve() {
	for (int i = 1; i <= 3; i++) {
		std::cin >> a[i];
	}
	if (a[1] == '>') a1++;
	else a2++;
	if (a[2] == '>') a1++;
	else a3++;
	if (a[3] == '>') a2++;
	else a3++;
	if (a1 == 1) std::cout << "A" << std::endl;
	else if (a2 == 1) std::cout << "B" << std::endl;
	else std::cout << "C" << std::endl;
}

signed main() {
	std::ios::sync_with_stdio(0);
	std::cin.tie(0), std::cout.tie(0);
	int times = 1;
	// std::cin >> times;
	while (times--) {
		solve();
	}
	return 0;
}