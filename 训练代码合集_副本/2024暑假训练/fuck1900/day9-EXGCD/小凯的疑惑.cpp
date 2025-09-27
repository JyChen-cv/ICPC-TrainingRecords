// https://www.luogu.com.cn/problem/P3951

// 找最后一个没有正整数解的数字
// 扩展问题：找第一个有正整数解的数字
// 首先要有一个结论的认识，两个互质的数字a,b，一个数的k倍对另一个数取模是0-(b-1)的一组排列
// 然后就从同于系的角度出发，最后一个无法表示的数字一定是a*(b-1)-b=a*b-a-b;

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

inline int exgcd(int a, int b, int &x, int &y) {
	if (b == 0) {x = 1, y = 0; return a;}
	int d = exgcd(b, a % b, x, y);
	int z = x; x = y, y = z - y * (a / b);
	return d;
}

void solve() {
	int a, b;
	std::cin >> a >> b;
	std::cout << (a * b) - a - b << std::endl;
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