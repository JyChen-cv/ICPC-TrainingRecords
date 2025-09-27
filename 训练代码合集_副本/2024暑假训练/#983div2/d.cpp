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
void solve() {
	int n;
	std::cin >> n;
	int a, root = 1;
	std::vector<int> rt, p(n + 2);
	while (1) {
		root++;
		std::cout << "? 1 " << root << std::endl;
		std::cout.flush();
		std::cin >> a;
		if (a == 0 || root == n) {
			for (int i = 2; i < root; i++) {
				rt.push_back(i);
				p[i] = 0;
			}
			rt.push_back(root);
			p[root] = 1;
			break;
		}
	}
	int now = root + 1;
	for (int point = 0; point < (int)rt.size() && now < n; point++) {
		// std::cout << rt.size() << std::endl;
		if (point == rt.size() - 1) {
			for (int j = now; j < n; j++) {
				p[j] = rt[rt.size() - 1];
				rt.push_back(j);
			}
			break;
		}
		std::cout << "? " << rt[point] << " " << now << std::endl;
		std::cout.flush();
		int a;
		std::cin >> a;
		if (a == 0) {
			p[now] = rt[point];
			rt.push_back(now);
			now++;
		}
	}
	std::cout << "! ";
	for (int i = 1; i < n; i++) {
		std::cout << p[i] << " \n"[i == n];
	}
	std::cout.flush();
}

signed main() {
	// std::ios::sync_with_stdio(0);
	// std::cin.tie(0), std::cout.tie(0);
	int times = 1;
	std::cin >> times;
	while (times--) {
		solve();
	}
	return 0;
}