#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>

#define int long long
const int N = 500;
int mapp[N + 2][N + 2];

int area(int h1, int h2, int s1, int s2) {
    return mapp[h2][s2] - mapp[h1 - 1][s2] - mapp[h2][s1 - 1] + mapp[h1 - 1][s1 - 1];
}

signed main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);
    int n, m, k;
    std::cin >> n >> m >> k;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            std::cin >> mapp[i][j];
            mapp[i][j] += mapp[i - 1][j] + mapp[i][j - 1] - mapp[i - 1][j - 1];
            // std::cout << mapp[i][j] << " ";
        }
        // std::cout << std::endl;
    }

    int ans = 0;
    for (int i = 1; i <= m; i++) {
        for (int j = i; j <= m; j++) {
            for (int s = 1, t = 1; t <= n; t++) {
                while (s <= t && mapp[t][j] - mapp[s - 1][j] - mapp[t][i - 1] + mapp[s - 1][i - 1] > k) s++;
                if (s <= t) ans += t - s + 1;
            }
        }
    }
    std::cout << ans << std::endl;
    return 0;
}