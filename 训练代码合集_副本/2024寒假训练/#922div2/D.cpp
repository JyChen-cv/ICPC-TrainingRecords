#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <queue>
#include <vector>

const int N = 1e5;
int n;
long long mapp[N + 2], dp[N + 2], sum[N + 2];

bool check(long long x) {
	for (int i = 1; i <= n; i++) dp[i] = 0x3f3f3f3f3f3f3f3f;
	std::priority_queue<std::pair<long long, int>, std::vector<std::pair<long long, int>>, std::greater<std::pair<long long, int>> > q;
	dp[0] = 0;
	q.push(std::make_pair(dp[0], 0));
	for (int i = 1; i <= n; i++) {
		while (sum[i - 1] - sum[q.top().second] > x && q.size()) {
			// std::cout << sum[i] << " " << sum[q.top().second - 1] << std::endl;
			q.pop();
		}
		// std::cout << q.size() << " " << q.top().first << " " << q.top().second << std::endl;
		if (q.size()) dp[i] = q.top().first + mapp[i];
		else return 0;
		q.push(std::make_pair(dp[i], i));
	}

	long long res = 0x3f3f3f3f3f3f3f3f;
	for (int i = 1; i <= n; i++) {
		res = std::min(res, std::max(dp[i], sum[n] - sum[i]));
	}
	return res <= x;
	// std::cout << x << std::endl;
	// for (int i = 1; i <= n; i++) {
	// 	std::cout << dp[i] << " ";
	// }
	// std::cout << std::endl;
	return 1;
}

int main()
{
	int t;
	std::cin >> t;
	while (t--) {
		std::cin >> n;
		for (int i = 1; i <= n; i++) {
			scanf("%lld", mapp + i);
			sum[i] = sum[i - 1] + mapp[i];
		}

		long long l = 0, r = 1e15 + 7;
		while (l < r) {
			// std::cout << l << " " << r << std::endl;
			long long mid = (l + r) >> 1;
			if (check(mid)) r = mid;
			else l = mid + 1;
		}
		std::cout << l << std::endl;
		// std::cout << check(7) << std::endl;
		// for (int i = 1; i <= n; i++) {
		// 	std::cout << dp[i] << " ";
		// }
		// puts("");
	}
	return 0;
}