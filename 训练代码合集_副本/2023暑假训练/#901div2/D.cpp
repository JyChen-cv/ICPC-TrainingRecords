#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <vector>

const int N = 5e3;
int mapp[N + 2], f[N + 2], cnt[N + 2];
int main() {
    int t;
    std::cin >> t;
    while (t--) {
        memset(cnt, 0, sizeof(cnt));
        int n;
        std::cin >> n;
        for (int i = 1; i <= n; i++) {
            std::cin >> mapp[i];
            if (mapp[i] <= 5000) cnt[mapp[i]]++;
        }
        std::sort(mapp + 1, mapp + n + 1);
        std::unique(mapp + 1, mapp + n + 1);
        int m = 0, tag = 1;
        while (mapp[tag] == m) {
            m++;
            tag++;
        }
        // std::cout << m << std::endl;
        memset(f, 0x3f, sizeof(f));
        f[m] = 0;
        for (int i = m; i >= 0; i--) {
            for (int j = i + 1; j <= m; j++) {
                f[i] = std::min(f[i], f[j] + (cnt[i] - 1) * j + i);
            }
        }
        std::cout << f[0] << std::endl;
    }
    return 0;
}