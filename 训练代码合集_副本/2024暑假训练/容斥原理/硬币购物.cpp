#include <algorithm>
#include <cstdio>
#include <iostream>

#define int long long
const int N = 1e5;
int times, c[4], dp[N + 2];
int cat[40];

inline int lowbit(int x) {
    return x & (-x);
}

signed main() {
    for (int i = 0; i <= 3; i++) std::cin >> c[i];
    dp[0] = 1;
    for (int i = 0; i <= 3; i++) {
        for (int j = 1; j <= 1e5; j++) {
            if (j >= c[i]) dp[j] += dp[j - c[i]];
        }
    }
    for (int i = 0; i <= 3; i++) cat[1 << i] = i;

    std::cin >> times;
    while (times--) {
        int d[4], s;
        for (int i = 0; i <= 3; i++) std::cin >> d[i];
        std::cin >> s;
        int ans = 0;
        for (int i = 0; i <= 15; i++) {
            int deal = i, cnt = 0, sum = 0;
            while (deal) {
                int res = lowbit(deal);
                cnt++;
                sum += c[cat[res]] * (d[cat[res]] + 1);
                deal -= res;
            }
            if (s < sum) continue;
            ans += dp[s - sum] * (cnt % 2 ? -1 : 1);
        }
        std::cout << ans << std::endl;
    }
    return 0;
}