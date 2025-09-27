#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <queue>
#include <vector>

#define int long long
const int N = 2e5;
int mapp[N + 2], sum[N + 2];
signed main() {
    int t;
    std::cin >> t;
    while (t--) {
        int n, m, k;
        std::cin >> n >> m >> k;
        for (int i = 1; i <= n; i++) {
            std::cin >> mapp[i];
        }
        std::sort(mapp + 1, mapp + n + 1);
        for (int i = 1; i <= n; i++) {
            sum[i] = sum[i - 1] + mapp[i];
        }
        int ans = -1e10;
        for (int i = n + 1; i >= n - m + 1; i--) {
            int ls1 = sum[n] - sum[i - 1];
            int ls2 = sum[i - 1] - sum[std::max((long long)0, i - 1 - k)];
            // std::cout << ls1 << " " << ls2 << " " << ans << " " << std::endl;
            if (sum[n] - ls1 - ls2 * 2 > ans) ans = sum[n] - ls1 - ls2 * 2;
        }

        std::cout << ans << std::endl;
    }
    return 0;
}
