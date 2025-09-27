#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>

const int N = 150000;
const long long inf = 1e15;
long long mapp[N + 2], s[N + 2];
int main() {
    int t;
    std::cin >> t;
    while (t--) {
        int n;
        std::cin >> n;
        s[0] = 0;
        for (int i = 1; i <= n; i++) {
            scanf("%lld", mapp + i);
            s[i] = s[i - 1] + mapp[i];
        }
        long long ans = 0;
        for (int i = 1; i * i <= n; i++) {
            if (n % i) continue;
            int len = i;
            int k = n / i;
            long long mx = 0, mi = inf;
            for (int j = 1; j <= k; j++) {
                long long res = s[j * len] - s[(j - 1) * len];
                mx = std::max(mx, res);
                mi = std::min(res, mi);
            }
            // std::cout << len << " " << mx << " " << mi << std::endl;
            ans = std::max(ans, mx - mi);

            len = n / i;
            k = i;
            if (k == 1) continue;
            mx = 0, mi = inf;
            for (int j = 1; j <= k; j++) {
                long long res = s[j * len] - s[(j - 1) * len];
                mx = std::max(mx, res);
                mi = std::min(res, mi);
            }
            ans = std::max(ans, mx - mi);
        }
        std::cout << ans << std::endl;
    }
    return 0;
}