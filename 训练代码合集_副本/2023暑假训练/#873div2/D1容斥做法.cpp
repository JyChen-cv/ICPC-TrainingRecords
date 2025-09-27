#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <vector>
#define int long long
const int N = 5e3;
int mapp[N + 2], dp[N + 2][N + 2];

signed main() {
    int t;
    std::cin >> t;
    while (t--) {
        int n;
        std::cin >> n;
        for (int i = 1; i <= n; i++) {
            scanf("%d", mapp + i);
            dp[i][i] = 0;
        }
        int ans = 0;
        for (int len = 2; len <= n; len++) {
            for (int l = 1; l + len - 1 <= n; l++) {
                int r = l + len - 1;
                if (mapp[l] > mapp[r])
                    dp[l][r] = r - l;
                else
                    dp[l][r] = dp[l + 1][r] + dp[l][r - 1] - dp[l + 1][r - 1];
                ans += dp[l][r];
            }
        }
        printf("%lld\n", ans);
    }
    return 0;
}