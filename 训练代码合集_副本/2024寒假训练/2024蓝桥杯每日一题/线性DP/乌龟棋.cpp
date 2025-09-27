#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <queue>

const int N = 40;
int f[N + 2][N + 2][N + 2][N + 2], mapp[352], cnt[5];
int main() {
    int n, m;
    std::cin >> n >> m;
    for (int i = 0; i < n; i++) {
        std::cin >> mapp[i];
    }
    for (int i = 1; i <= m; i++) {
        int a;
        std::cin >> a;
        cnt[a]++;
    }
    for (int i = 0; i <= cnt[1]; i++) {
        for (int j = 0; j <= cnt[2]; j++) {
            for (int k = 0; k <= cnt[3]; k++) {
                for (int l = 0; l <= cnt[4]; l++) {
                    if (i) f[i][j][k][l] = std::max(f[i][j][k][l], f[i - 1][j][k][l]);
                    if (j) f[i][j][k][l] = std::max(f[i][j][k][l], f[i][j - 1][k][l]);
                    if (k) f[i][j][k][l] = std::max(f[i][j][k][l], f[i][j][k - 1][l]);
                    if (l) f[i][j][k][l] = std::max(f[i][j][k][l], f[i][j][k][l - 1]);
                    f[i][j][k][l] += mapp[i + j * 2 + k * 3 + l * 4];
                    // std::cout << i << " " << j << " " << k << " " << l << " " << f[i][j][k][l] << std::endl;
                }
            }
        }
    }
    std::cout << f[cnt[1]][cnt[2]][cnt[3]][cnt[4]] << std::endl;
    return 0;
}