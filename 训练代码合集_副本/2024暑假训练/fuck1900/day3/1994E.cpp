// https://codeforces.com/problemset/problem/1994/E
// 按位考虑，对于一个位置要是存在1个能cover的，那么肯定直接cover，
// 要是有两个以上能cover，那么从这个位置开始的后续所有都是1
// 核心在于：先不要考虑修剪树，先加入再修剪

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

const int N = 1e6;
int root[N + 2];
void solve() {
	int n;
	std::cin >> n;
	for (int i = 1; i <= n; i++) {
		std::cin >> root[i];
		for (int j = 1; j < root[i]; j++) {
			int a;
			std::cin >> a;
		}
	}
	std::sort(root + 1, root + n + 1, [&](const int &a, const int &b)->bool{
		return a > b;
	});

	int bit[30], ans = 0;
	memset(bit, 0, sizeof bit);
	for (int i = 1; i <= n; i++) {
		for (int j = 20; j >= 0; j--) {
			if (root[i] >= (1 << j)) {
				bit[j]++;
				root[i] -= (1 << j);
			}
		}
		for (int j = 20; j >= 0; j--) {
			if (bit[j] == 2) {
				for (int k = j; k >= 0; k--) {
					bit[k] = 1;
				}
				break;
			}
		}
	}
	for (int i = 20; i >= 0; i--) {
		if (bit[i]) ans += (1 << i);
	}
	std::cout << ans << std::endl;
}

// 1 0 0 1 0
// 0 1 1 1 0

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