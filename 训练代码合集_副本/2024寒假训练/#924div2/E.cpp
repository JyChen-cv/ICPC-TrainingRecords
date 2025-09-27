#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>

typedef long long ll;
std::vector<ll> ans;

int main()
{
	int t;
	std::cin >> t;
	while (t--) {
		ll n, x;
		std::cin >> n >> x;
		ll ls = n - x, tag = 0;
		for (ll i = 1; i * i <= ls; i++) {
			if (ls % i == 0) {
				if (i % 2 == 0) {
					if (i / 2 + 1  != 1) {
						if (i / 2 + 1 == x) tag = 1;
						std::cout << i / 2 + 1 << std::endl;
						ans.push_back(i / 2 + 1);
					}
				}
				ll j = ls / i;
				if (j == i) continue;
				if (j % 2 == 0) {
					if (j / 2 + 1  != 1) {
						if (j / 2 + 1  == x) tag = 1;
						std::cout << j / 2 + 1 << std::endl;
						ans.push_back(j / 2 + 1);
					}
				}
			}
			// std::cout << i << " " << ans << std::endl;
		}
		ls = n + x - 2;
		for (ll i = 1; i * i <= ls; i++) {
			if (ls % i == 0) {
				if (i % 2 == 0) {
					if (i / 2 + 1  != 1) {
						if (i / 2 + 1 == x) tag = 1;
						std::cout << i / 2 + 1 << std::endl;
						ans.push_back(i / 2 + 1);
					}
				}
				ll j = ls / i;
				if (j == i) continue;
				if (j % 2 == 0) {
					if (j / 2 + 1  != 1) {
						if (j / 2 + 1  == x) tag = 1;
						std::cout << j / 2 + 1 << std::endl;
						ans.push_back(j / 2 + 1);
					}
				}
			}
			// std::cout << i << " " << ans << std::endl;
		}
		sort(ans.begin(), ans.end());
		ans.erase(unique(ans.begin(), ans.end()), ans.end());
		std::cout << ans.size() << std::endl;
	}
	return 0;
}