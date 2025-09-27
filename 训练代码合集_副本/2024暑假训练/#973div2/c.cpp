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
	std::cout << "? 0" << std::endl;
	int a;
	std::cin >> a;
	if (a == 0) {
		std::cout << "! ";
		for (int i = 1; i <= n; i++) {
			std::cout << "1";
		}
		std::cout << std::endl;
		std::cout.flush();
		return ;
	}
	std::string ans;
	ans = '0';
	for (int i = 1; i <= n; i++) {
		if (ans.size() == n) break;
		int t1 = 0, t2 = 0;
		std::cout << "? " << ans << "0" << std::endl;
		std::cout.flush();
		std::cin >> t1;
		if (t1) {
			ans += '0';
		}
		else {
			std::cout << "? " << ans << "1" << std::endl;
			std::cout.flush();
			std::cin >> t2;
			if (t2) {
				ans += '1';
			}
			else {
				break;
			}
		}
	}
	if (ans.size() == n) {
		std::cout << "! " << ans << std::endl;
		std::cout.flush();
		return ;
	}
	else {
		for (int i = 1; i <= n; i++) {
			if (ans.size() == n) break;
			int t1 = 0, t2 = 0;
			std::cout << "? " << "0" << ans << std::endl;
			std::cout.flush();
			std::cin >> t1;
			if (t1) {
				ans = '0' + ans;
			}
			else ans = '1' + ans;
		}
		std::cout << "! " << ans << std::endl;
		std::cout.flush();
		return ;
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