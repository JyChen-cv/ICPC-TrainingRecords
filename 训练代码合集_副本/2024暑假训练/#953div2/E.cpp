#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>

const int N = 2e5;
int taga[N + 2], tagb[N + 2], cnt[N + 2];
int main()
{
	int t;
	std::cin >> t;
	while (t--) {
		int n;
		std::cin >> n;
		for (int i = 1; i <= n; i++) {
			taga[i] = tagb[i] = cnt[i] = 0;
		}
		std::string a, b, c, d;
		std::cin >> a >> b;
		c = a, d = b;
		// std::cout << a << " " << b << std::endl;
		for (int i = 0; i + 2 < n; i++) {
			if (a[i] == a[i + 2] && a[i] == '0') {
				if (b[i + 1] == '0') {
					b[i + 1] = '1';
					tagb[i + 1] = 1;
				}
			}
		}
		for (int i = 0; i + 2 < n; i++) {
			if (b[i] == b[i + 2] && b[i] == '1') {
				if (a[i + 1] == '0') {
					a[i + 1] = '1';
					taga[i + 1] = 1;
				}
			}
		}
		cnt[0] = (a[0] == '1' ? 1 : 0);
		for (int i = 1; i < n; i++) {
			cnt[i] = cnt[i - 1] + (a[i] == '1' ? 1 : 0);
		}
		// std::cout << cnt[n - 1] << std::endl;
		int m;
		std::cin >> m;
		for (int i = 1; i <= m; i++) {
			int l, r;
			std::cin >> l >> r;
			l--, r--;
			int ans = cnt[r];
			if (l != 0) ans -= cnt[l - 1];
			if (r - l < 6) {
				ans = 0;
				std::string ls1, ls2;
				// std::cout << c << " " << d << std::endl;
				for (int j = l; j <= r; j++) {
					ls2[j] = d[j]; // ？？ 没有初始化，不太能这么用
					ls1[j] = c[j];
				}
				for (int j = l; j + 2 <= r; j++) {
					if (ls1[j] == ls1[j + 2] && ls1[j] == '0') ls2[j + 1] = 1;
				}
				for (int j = l; j + 2 <= r; j++) {
					if (ls2[j] == ls2[j + 2] && ls2[j] == '1') ls1[j + 1] = 1;
				}
				std::cout << ls1 << " " << ls2 << std::endl;
				for (int j = l; j <= r; j++) {
					if (ls1[j] == '1') ans++;
				}
				std::cout << ans << std::endl;
				continue;
			}
			std::vector<int> deal;
			if (taga[l] == 1) {
				deal.push_back(l);
			}
			if (tagb[l] == 1 && taga[l + 1] == 1) {
				deal.push_back(l + 1);
			}
			if (taga[r] == 1) {
				deal.push_back(r);
			}
			if (tagb[r] == 1 && taga[r - 1] == 1) {
				deal.push_back(r - 1);
			}
			std::sort(deal.begin(), deal.end());
			deal.erase(unique(deal.begin(), deal.end()), deal.end());
			ans -= deal.size();
			// std::cout << "??" << deal.size() << std::endl;
			std::cout << ans << std::endl;
		}
	}
	return 0;
}