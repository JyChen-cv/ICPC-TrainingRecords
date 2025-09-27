#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>

const int N = 2e5;
int mapp[N + 2], f[N + 2];
int main() {
    int t;
    std::cin >> t;
    while (t--) {
        int n;
        std::cin >> n;
        for (int i = 1; i <= n; i++) {
            scanf("%d", mapp + i);
        }
        f[1] = mapp[1];
        int ans = f[1];
        for (int i = 2; i <= n; i++) {
            if ((mapp[i] + mapp[i - 1]) % 2) {
                f[i] = std::max(mapp[i], f[i - 1] + mapp[i]);
            } else
                f[i] = mapp[i];
            // std::cout << f[i] << " ";
            ans = std::max(ans, f[i]);
        }
        // std::cout << std::endl;
        std::cout << ans << std::endl;
    }
    return 0;
}