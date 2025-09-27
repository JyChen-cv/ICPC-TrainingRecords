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

int n, ov;
int mapp[60][3], q[60][3];
char ans[60];
bool used[60];

int cvt_i(char x) {
	if (x <= 'z' && x >= 'a') return x - 'a';
	else return x - 'A' + 26;
}
char cvt_c(int x) {
	if (x < 26) return x + 'a';
	else return x - 26 + 'A';
}
std::string cvt_s(int x, int base = n) {
	std::string res;
	while (x) {
		res += cvt_c(x % base);
		x /= base;
	}
	if (res.empty()) res += 'a';
	// std::reverse(res.begin(), res.end());
	return res;
}

void dfs(int i) {
	if (i == n) {
		ov = 1;
		for (int t = 0; t < n; t++) std::cout << ans[t];
		std::cout << "\n";
		return;
	}
	for (int j = 0; j < n; j++) {
		if (used[j]) continue;
		bool ok = true;
		for (int k = 0; k < 3; k++)
			if (mapp[i][k] != q[j][k]) { ok = false; break; }
		if (!ok) continue;
		used[j] = true;
		ans [i] = cvt_c(j);
		dfs(i + 1);
		if (ov) return;
		used[j] = false;
	}
}


void solve() {
	memset(mapp, 0, sizeof(mapp));
	memset(q, 0, sizeof(q));
	memset(ans, 0, sizeof(ans));
	memset(used, 0, sizeof(used));
	ov = 0;
	std::cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			int a = i * j;
			std::string b = cvt_s(a);
			// std::cout << ls << " " << lls << std::endl;
			mapp[cvt_i(b[0])][0]++;
			if (b.size() > 1) {
				mapp[cvt_i(b[1])][1]++;
				if (b[0] == b[1]) mapp[cvt_i(b[0])][2]++;
			}
		}
	}
	// for (int i = 0; i < n; i++) std::cout << i << ": " << mapp[i] << std::endl;
	for (int i = 1; i <= n * n; i++) {
		std::string b;
		std::cin >> b;
		std::reverse(b.begin(), b.end());
		q[cvt_i(b[0])][0]++;
		if (b.size() > 1) {
			q[cvt_i(b[1])][1]++;
			if (b[0] == b[1]) q[cvt_i(b[0])][2]++;
		}
	}
	// for (int i = 0; i < n; i++) {
	// 	std::cout << "mapp " << i << ": " << mapp[i][0] << " " << mapp[i][1] << " " << mapp[i][2] << std::endl;
	// 	std::cout << "q " << i << ": " << q[i][0] << " " << q[i][1] << " " << q[i][2] << std::endl;
	// }

	dfs(0);
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