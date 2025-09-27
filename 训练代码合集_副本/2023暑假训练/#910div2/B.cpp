#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>

const int N = 2e5;
int mapp[N + 2];
int main() {
    int t;
    std::cin >> t;
    while (t--) {
        int n;
        scanf("%d", &n);
        for (int i = 1; i <= n; i++) {
            scanf("%d", mapp + i);
        }
        int tag = mapp[n], ans = 0, q = 1;

        for (int i = n - 1; i >= 1; i--) {
            int ls = mapp[i] % 2;
            if (mapp[i] <= tag) {
                tag = mapp[i];
                continue;
            }
            while (mapp[i] > tag) {
                ans += q;
                q *= 2;
                mapp[i] /= 2;
            }
            if (ls && mapp[i] == tag) {
                tag = (mapp[i] + 1) / 2;
                ans++;
            } else
                tag = mapp[i];
            q = 1;
            // std::cout << mapp[i] << " " << ans << std::endl;
        }
        std::cout << ans << std::endl;
    }
    return 0;
}