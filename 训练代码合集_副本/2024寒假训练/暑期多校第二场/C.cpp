#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <vector>

typedef long long ll;
const int N = 1e6;
bool tag[N + 2];
ll mapp[N + 2], dp[N + 2][4];

int main()
{
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%lld", mapp + i);
	}
	for (int i = 1; i <= n; i++) {
		scanf("%lld", tag + i);
	}

	for (int i = 1; i <= n; i++) {
		// 0ziji,1zuomian,2youmian,3buna
		if (tag[i]) {
			dp[i][1] = std::max(dp[i - 1][1], dp[i - 1][3]);
			dp[i][0] = std::max(dp[i][1], dp[i - 1][0]);
			dp[i][2] = std::max(dp[i][0], dp[i - 1][2]);
			dp[i][1] += mapp[i - 1];
			dp[i][0] += mapp[i];
			dp[i][2] += mapp[i + 1];
		}
		else {
			if (tag[i - 1]) {
				dp[i][1] = dp[i - 1][0];
				dp[i][0] = dp[i - 1][2];
				for (int j = 0; j <= 3; j++) {
					if (j == 2) continue;
					dp[i][3] = std::max(dp[i][3], dp[i - 1][j]);
				}
			}
			else {
				for (int j = 0; j <= 3; j++) {
					dp[i][3] = std::max(dp[i][3], dp[i - 1][j]);
				}
			}
		}
	}
	ll ans = 0;
	for (int i = 0; i <= 3; i++) ans = std::max(ans, dp[n][i]);
	std::cout << ans << std::endl;

	return 0;
}