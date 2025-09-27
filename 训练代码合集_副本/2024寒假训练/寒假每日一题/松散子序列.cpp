#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>

const int N = 1e6;
char mapp[N + 2];
long long n, dp[N + 2][2];

int main()
{
	scanf("%s", mapp + 1);
	n = strlen(mapp + 1);
	for (int i = 1; i <= n; i++) {
		dp[i][0] = std::max(dp[i - 1][1], dp[i - 1][0]);
		dp[i][1] = dp[i - 1][0] + mapp[i] - 'a' + 1;
	}
	std::cout << std::max(dp[n][0], dp[n][1]) << std::endl;
	return 0;
}