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

typedef long long ll;
typedef double db;
typedef std::pair<int, int> PII;
const int N = 2e5;
struct node {
	int l1, r1, l2, r2;
	int ans;
} q[N + 2];
int a[N + 2], b[N + 2];
int rem[502][N + 2], rem2[502][N + 2];
int r[N + 2];
std::vector<int> ra[N + 2], rb[N + 2];
void solve() {
	std::vector<int> v1, v2;
	int n, m, k;
	std::cin >> n >> m;
	k = 500;
	for (int i = 1; i <= n; i++) std::cin >> a[i];
	for (int i = 1; i <= n; i++) std::cin >> b[i];
	for (int i = 1; i <= m; i++) std::cin >> q[i].l1 >> q[i].r1 >> q[i].l2 >> q[i].r2;
	for (int i = 1; i <= m; i++) {
		if (q[i].l1 + q[i].r2 != q[i].l2 + q[i].r1) q[i].ans = 0;
		else {
			if (q[i].r1 - q[i].l1 > k) v1.push_back(i);
			else v2.push_back(i);
		}
	}
	for (int i = 0; i < (int)v2.size(); i++) {
		for (int j = q[v2[i]].l1; j <= q[v2[i]].r1; j++) {
			r[a[j]]++;
		}
		for (int j = q[v2[i]].l2; j <= q[v2[i]].r2; j++) {
			r[b[j]]--;
		}
		q[v2[i]].ans = 1;
		for (int j = q[v2[i]].l1; j <= q[v2[i]].r1; j++) {
			if (r[a[j]]) q[v2[i]].ans = 0;
			r[a[j]] = 0;
		}
		for (int j = q[v2[i]].l2; j <= q[v2[i]].r2; j++) {
			r[b[j]] = 0;
		}
	}
	for (int i = 0; i < (int)v1.size(); i++) {
		ra[q[v1[i]].l1 - 1].push_back(i);
		ra[q[v1[i]].r1].push_back(i);
		rb[q[v1[i]].l2 - 1].push_back(i);
		rb[q[v1[i]].r2].push_back(i);
	}
	memset(r, 0, sizeof r);
	for (int i = 1; i <= n; i++) {
		r[a[i]]++;
		for (int j = 0; j < (int)ra[i].size(); j++) {
			for (int ll = 1; ll <= n; ll++) {
				rem[ra[i][j]][ll] = r[ll] - rem[ra[i][j]][ll];
			}
		}
	}
	memset(r, 0, sizeof r);
	for (int i = 1; i <= n; i++) {
		r[b[i]]++;
		for (int j = 0; j < (int)rb[i].size(); j++) {
			for (int ll = 1; ll <= n; ll++) {
				rem2[rb[i][j]][ll] = r[ll] - rem2[rb[i][j]][ll];
			}
		}
	}
	for (int i = 0; i < (int)v1.size(); i++) {
		q[v1[i]].ans = 1;
		for (int j = 1; j <= n; j++) {
			if (rem[i][j] != rem2[i][j]) q[v1[i]].ans = 0;
		}
	}
	for (int i = 1; i <= m; i++) {
		std::cout << (q[i].ans ? "Yes" : "No") << std::endl;
	}
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