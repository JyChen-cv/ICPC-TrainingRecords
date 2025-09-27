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
const int N = 2e5;
int pos[N + 2], v[N + 2], dep[N + 2], sz[30], mx;
int n, m, mapp[N + 2];
int lowbit(int x) {
	return x & (-x);
}
void deal(int x) {
	if (x >= mx && x <= n) {
		deal(x / 2);
		return ;
	}
	v[x] = v[x * 2] & v[x * 2 + 1];
	// std::cout << x << ": " << v[x] << " ";
	if (pos[x * 2] == pos[x] + 1 && pos[x * 2 + 1] == pos[x] + sz[dep[n] - dep[x]]) {
		v[x] &= 1;
	}
	else if (pos[x * 2 + 1] == pos[x] + 1 && pos[x * 2] == pos[x] + sz[dep[n] - dep[x]]) {
		v[x] &= 1;
	}
	else v[x] = 0;
	// std::cout << pos[x] << " " << pos[x * 2] << " " << pos[x * 2 + 1] << " " << sz[dep[n] - dep[x]] << std::endl;
	if (x == 1) return ;
	else deal(x / 2);

}
void solve() {
	std::cin >> n >> m;
	for (int i = 2; i <= n; i++) {
		int a;
		std::cin >> a;
	}
	dep[1] = 1;
	for (int i = 1; i <= n; i++) {
		std::cin >> mapp[i];
		pos[mapp[i]] = i;
		v[i] = 0;
		if (i >= 2)dep[i] = dep[i / 2] + 1;
	}
	for (int i = 20; i >= 0; i--) {
		if (sz[i] <= n) {
			mx = sz[i];
			break;
		}
	}
	for (int i = mx; i <= n; i++) {
		v[i] = 1;
		deal(i);
	}
	for (int i = 1; i <= m; i++) {
		int a, b;
		std::cin >> a >> b;
		std::swap(pos[mapp[a]], pos[mapp[b]]);
		std::swap(mapp[a], mapp[b]);
		// std::cout << mapp[a] << " " << pos[mapp[a]] << " " << mapp[b] << " " << pos[mapp[b]] << std::endl;
		deal(mapp[a]), deal(mapp[b]);
		puts(v[1] ? "YES" : "NO");
		// for (int j = 1; j <= n; j++) {
		// 	std::cout << v[j] << " \n"[j == n];
		// }
	}
}

int main() {
	std::ios::sync_with_stdio(0);
	std::cin.tie(0), std::cout.tie(0);
	sz[0] = 1;
	for (int i = 1; i <= 20; i++) sz[i] = 1 << i;
	int times = 1;
	std::cin >> times;
	while (times--) {
		solve();
	}
	return 0;
}