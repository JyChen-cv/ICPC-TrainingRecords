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
#include <bitset>

#define int long long
typedef long long ll;
typedef double db;
typedef std::pair<int, int> PII;
const int N = 2e5;
int n;
struct node {
	int v, num, poi;
	PII ans;
} a[N + 2];

bool cmp1(const node &a, const node &b) {
	return a.v > b.v;
}
bool cmp2(const node &a, const node &b) {
	return a.num < b.num;
}

void solve() {
	std::cin >> n;
	std::cout << "YES" << std::endl;
	for (int i = 1; i <= n; i++) {
		std::cin >> a[i].v; a[i].num = i;
	}
	std::sort(a + 1, a + n + 1, cmp1);
	int tag = 1, rem = n;
	a[1].ans = {1, 1};
	for (int i = 2; i <= n; i++) {
		if (a[i - 1].v == 0) {
			rem = i - 1;
			break;
		}
		a[i - 1].poi = a[i].num;

		a[i].ans = a[i - 1].ans;
		a[i].ans.first++;
		a[i].ans.second = a[i - 1].ans.second + tag * (a[i - 1].v - 1);
		tag *= -1;
	}
	a[rem].poi = a[rem].num;
	for (int i = rem + 1; i <= n; i++) {
		a[i].ans = {i, 1};
		a[i].poi = a[i].num;
	}
	std::sort(a + 1, a + n + 1, cmp2);
	for (int i = 1; i <= n; i++) {
		std::cout << a[i].ans.first << " " << a[i].ans.second << std::endl;
	}
	for (int i = 1; i <= n; i++) {
		std::cout << a[i].poi << " ";
	}
	puts("");
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