#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <vector>

typedef long long ll;
const int N = 1e5;
ll mapp[N + 2], sum[N + 2];

ll dfs(int x, int y) {
	if (x >= y) return 0;
	if (y - x == 1) return mapp[y] * mapp[x];
	else {
		int ls = std::lower_bound(sum + x, sum + y + 1, (sum[y] + sum[x]) / 2) - sum;
		return dfs(x, ls - 1) + dfs(ls, y) + (sum[ls - 1] - sum[x - 1]) * (sum[y] - sum[ls - 1]);
	}
}

int main()
{
	int n;
	std::cin >> n;
	for (int i = 1; i <= n; i++) {
		std::cin >> mapp[i];
		sum[i] = sum[i - 1] + mapp[i];
	}

	std::cout << dfs(1, n) << std::endl;
	return 0;
}