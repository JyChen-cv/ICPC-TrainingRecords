#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <queue>

#define int long long
const int N = 30;
int mapp[N + 2][N + 2];
int d[(1 << 20) + 1][22];

signed main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);

    int n;
    std::cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            std::cin >> mapp[i][j];
        }
    }

    memset(d, 0x3f, sizeof(d));
    d[1][0] = 0;
    for (int i = 1; i <= ((1 << n) - 1); i++) {
        if ((i & 1) == 0) continue;
        for (int j = 0; j <= (n - 1); j++) {
            if ((i & (1 << j)) == 0) continue;
            for (int k = 0; k <= (n - 1); k++) {
                if ((i & (1 << k)) == 0 || j == k) continue;
                d[i][j] = std::min(d[i][j], d[i ^ (1 << j)][k] + mapp[k][j]);
            }
            // std::cout << i << " " << j << " " << d[i][j] << std::endl;
        }
    }

    int ans = d[(1 << n) - 1][n - 1];
    std::cout << ans << std::endl;
    return 0;
}

// 对于这道题目而言，状态压缩并没有节省时间复杂度，仅仅是方便状态设计以及状态之间的运算罢了