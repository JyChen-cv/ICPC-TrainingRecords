// 考虑一个问题的子问题的时候，不要被条件局限在位置划分上，也可以考虑值域去划分子问题

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <vector>
#include <queue>
#include <map>
#include <cstring>
#include <set>

#define int long long
typedef long long ll;
typedef double db;
typedef std::pair<int, int> PII;
const int N = 2e5;
struct group {
	int v, lm, rm, sm, whe;
	bool operator < (const group &t) const {
		return v > t.v;
	}
} a[N + 2];
int s[N + 2], b[N + 2];
PII r[N + 2];
bool cmp(PII x, PII y) {
	return x.first > y.first;
}
void solve() {
	int n, m;
	std::cin >> n >> m;
	for (int i = 0; i <= n + 1; i++) {
		a[i].lm = a[i].rm = a[i].whe = 0;
	}
	for (int i = 1; i <= n; i++) {
		std::cin >> a[i].v;
		s[i] = s[i - 1] + a[i].v;
		r[i] = {a[i].v, i};
		// std::cout << a[i].whe << " ";
	}
	std::vector<int> q;
	for (int i = 1; i <= n; i++) {
		while (q.size() && a[q.back()].v <= a[i].v) q.pop_back();
		if (!q.size()) a[i].lm = 0;
		else a[i].lm = q.back();
		q.push_back(i);
	}
	q.clear();
	for (int i = n; i >= 0; i--) {
		while (q.size() && a[q.back()].v <= a[i].v) q.pop_back();
		if (!q.size()) a[i].rm = n + 1;
		else a[i].rm = q.back();
		q.push_back(i);
	}
	for (int i = 1; i <= n; i++) {
		a[i].sm = s[a[i].rm - 1] - s[a[i].lm];
		// std::cout << a[i].lm << " " << a[i].rm << " " << a[i].sm << std::endl;
	}
	std::sort(r + 1, r + n + 1, cmp);
	int ans = 0;
	for (int i = 1; i <= n; i++) {
		int now = r[i].second;
		if (a[now].lm == 0 && a[now].rm == n + 1) a[now].whe = 1;
		if (a[now].lm != 0 && a[now].sm >= a[a[now].lm].v) {
			a[now].whe |= a[a[now].lm].whe;
		}
		// std::cout << now << " " << a[now].lm << " " << a[now].rm << " " << a[now].sm << " " << a[now].whe << std::endl;
		if (a[now].rm != (n + 1) && a[now].sm >= a[a[now].rm].v) {
			a[now].whe |= a[a[now].rm].whe;
		}
		// std::cout << now << " " << a[now].lm << " " << a[now].rm << " " << a[now].sm << " " << a[now].whe << std::endl;
		ans += a[now].whe;
	}
	std::cout << ans << std::endl;
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