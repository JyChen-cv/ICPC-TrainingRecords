#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>

const int N = 1e5;
long long mapp[N + 2];

int main() {
    mapp[3] = 1;
    for (int i = 4; i <= 1e5; i++) mapp[i] = mapp[i - 1] + mapp[i - 2];

    int t;
    std::cin >> t;
    while (t--) {
        long long n, k;
        std::cin >> n >> k;
        if (k == 1) {
            std::cout << 1 << std::endl;
            continue;
        } else if (k == 2) {
            std::cout << (n + 1) << std::endl;
            continue;
        }
        if (k > 1e5) {
            std::cout << 0 << std::endl;
            continue;
        }

        int ans = 0;
        for (long long i = 0; i * mapp[k] <= n; i++) {
            if ((n - i * mapp[k]) % mapp[k + 1] != 0)
                continue;
            else {
                long long y = (n - i * mapp[k]) / (mapp[k + 1]);
                // std::cout << i << " " << y << std::endl;
                if (y >= i)
                    ans++;
                else
                    break;
            }
        }
        std::cout << ans << std::endl;
    }
    return 0;
}