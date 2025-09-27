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
const int N = 2e5;
int a[N + 2], b[N + 2], f[N + 2][22], ga[N + 2][22], gb[N + 2][22];
int rem_a[N + 2][22], rem_b[N + 2][22];

int gcd(int x, int y) {
	return y ? gcd(y, x % y) : x;
}
inline int query_a(int l, int r) {
	int len = r - l + 1;
	if (len <= 0) return 0;
	int k = log(len) / log(2);
	return gcd(ga[r][k], ga[l + (1 << k) - 1][k]);  // 感觉这里没问题了
}
inline int query_b(int l, int r) {
	int len = r - l + 1;
	if (len <= 0) return 0;
	int k = log(len) / log(2);
	return gcd(gb[l][k], gb[r - k + 1][k]);
}
inline int fd_a(int x, int tag) {
	// 考虑gcd函数一定是单调递减的，在上面二分
	int l = 1, r = x;
	while (l < r) {
		int mid = (l + r) >> 1;
		if (query_a(mid, x) >= tag) r = mid;
		else l = mid + 1;
	}
	return l;
}
inline int fd_b(int x, int tag) {
	int l = 1, r = x;
	while (l < r) {
		int mid = (l + r) >> 1;
		if (query_b(mid, x) >= tag) r = mid;
		else l = mid + 1;
	}
	return l;
}
inline int cal_a(int s, int e, int tag, int tag2) {
	int l = s, r = e;
	while (l < r) {
		int mid = (l + r + 1) >> 1;
		if (gcd(query_a(1, mid), tag2) == gcd(tag, tag2)) l = mid;
		else r = mid - 1;
	}
	return l;
}
inline int cal_b(int s, int e, int tag, int tag2) {
	int l = s, r = e;
	while (l < r) {
		int mid = (l + r + 1) >> 1;
		if (gcd(query_b(1, mid), tag2) == gcd(tag, tag2)) l = mid;
		else r = mid - 1;
	}
	return l;
}

void solve() {
	int n;
	std::cin >> n;
	// memset(a, 0, sizeof a), memset(b, 0, sizeof b);
	// memset(gb, 0, sizeof gb), memset(ga, 0, sizeof ga);
	// memset(rem_a, 0, sizeof rem_a); memset(rem_b, 0, sizeof rem_b);
	for (int i = 0; i <= n + 1; i++) {
		for (int j = 0; j <= 20; j++) {
			f[i][j] = ga[i][j] = gb[i][j] = rem_a[i][j] = rem_b[i][j] = 0;
		}
	}
	for (int i = 1; i <= n; i++) std::cin >> a[i];
	for (int i = 1; i <= n; i++) std::cin >> b[i];
	for (int i = 1; i <= n; i++) {
		f[i][0] = i - 1;  // 右闭左开
		ga[i][0] = a[i], gb[i][0] = b[i];
		for (int j = 1; j <= 20; j++) {
			f[i][j] = f[f[i][j - 1]][j - 1];
			ga[i][j] = gcd(ga[i][j - 1], ga[f[i][j - 1]][j - 1]);
			gb[i][j] = gcd(gb[i][j - 1], gb[f[i][j - 1]][j - 1]);
		}

	}
	for (int i = 1; i <= n; i++) {
		// std::cout << i << std::endl;
		rem_a[i][0] = fd_a(i, a[i]), rem_b[i][0] = fd_b(i, b[i]);  // 从i位置开始gcd值有j次变化的最远位置
		for (int j = 1; j <= 20; j++) {
			// std::cout << j << " \n"[j == 20];
			rem_a[i][j] = fd_a(rem_a[i][j - 1] - 1, query_a(rem_a[i][j - 1] - 1, i));
			rem_b[i][j] = fd_b(rem_b[i][j - 1] - 1, query_b(rem_b[i][j - 1] - 1, i));
		}
	}

	// for (int i = 1; i <= n; i++) {
	//  std::cout << i << std::endl;
	//  for (int j = 0; j <= 1; j++) {
	//      std::cout << rem_a[i][j] << " ";
	//  }
	//  std::cout << std::endl;
	// }

	int ans = 0, cnt = 0;
	cnt = 1;
	ans = gcd(b[1], query_a(2, n)) + gcd(a[1], query_b(2, n));
	// std::cout << ans << std::endl;
	for (int i = 2; i <= n; i++) {

		std::vector<int> q;
		for (int j = 0; j <= 20; j++) {
			q.push_back(rem_a[i][j]);
			q.push_back(rem_b[i][j]);
		}
		std::sort(q.begin(), q.end());
		q.erase(unique(q.begin(), q.end()), q.end());
		q.push_back(i + 1); // 插入一个边界值
		std::cout << i << "!" << q.size() << ": ";
		for (int j = 0; j < (int)q.size(); j++) std::cout << q[j] << " \n"[j == q.size() - 1];
		for (int j = 0; j < (int)q.size() - 1; j++) {
			int pre = q[j] - 1, suf = i + 1;
			int prea = query_a(1, pre), sufa = query_a(suf, n), aa = query_a(q[j], i);
			int preb = query_b(1, pre), sufb = query_b(suf, n), bb = query_b(q[j], i);
			int nowa = gcd(prea, sufa); nowa = gcd(nowa, bb);
			int nowb = gcd(preb, sufb); nowb = gcd(nowb, aa);
			if (nowa + nowb >= ans) {  // 否则不用考虑
				// std::cout << nowa << " " << nowb << std::endl;
				int st = q[j], ed = q[j + 1] - 1; // 保证最后一个点是倒数第二个
				std::cout << st << "< - >" << ed << "  >> " << i << " " << pre << std::endl;
				int now = 1;
				if (pre) now = std::max(cal_a(st, ed, query_a(1, pre), bb), cal_b(st, ed, query_b(1, pre), aa));
				now = std::max(now, st);
				std::cout << nowa + nowb << " " << now << " " << ed << " " << i << " " << (ed - now + 1) << std::endl;
				if (nowa + nowb > ans) {
					ans = nowa + nowb;
					if (ed >= now) cnt = ed - now + 1;
				}
				else {
					if (ed >= now) cnt += ed - now + 1;
				}
			}
		}
		// std::cout << i << std::endl;
	}
	std::cout << ans << " " << cnt << std::endl;
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