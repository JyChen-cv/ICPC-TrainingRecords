#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <vector>
#include <queue>
#include <map>
#include <cstring>
#include <set>

typedef long long ll;
typedef double db;
typedef std::pair<int, int> PII;
const int N = 3e5;
int mapp[N + 2], b[N + 2];
void solve() {
	int n;
	std::cin >> n;
	for (int i = 1; i <= n; i++) {
		std::cin >> mapp[i];
	}
	int tag = 1;
	for (int i = 1; i <= n; i++) {
		std::cin >> b[i];
		if (b[i] != mapp[i]) tag = 0;
	}
	if (!tag) {
		tag = 1;
		for (int i = 1; i <= n; i++) {
			if (b[i] != mapp[n + 1 - i]) tag = 0;
		}
	}
	puts(tag ? "Bob" : "Alice");
}

int main() {
	std::ios::sync_with_stdio(0);
	std::cin.tie(0), std::cout.tie(0);
	int times = 1;
	std::cin >> times;
	while (times--) {
		solve();
	}
	return 0;
}