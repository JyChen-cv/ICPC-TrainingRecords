#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <vector>

#define inf 1e18;
const int N = 100;
typedef long long ll;
ll f[N + 2][5202][N + 2];
struct group {
    ll v;
    int p;
} mapp[N + 2];
int main() {
    int n, m;
    std::cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        std::cin >> mapp[i].v >> mapp[i].p;
    }
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= 5200; j++) {
            for (int k = 0; k <= m; k++) {
                f[i][j][k] = -inf;
            }
        }
    }
    f[0][2600][0] = 0;

    for (int i = 1; i <= n; i++) {
        for (int j = 5200; j >= 0; j--) {
            for (int k = 0; k <= m; k++) {
                f[i][j][k] = f[i - 1][j][k];
                if (j >= mapp[i].p * 2 && k) {
                    f[i][j][k] = std::max(f[i - 1][j - mapp[i].p * 2][k - 1] + mapp[i].v, f[i][j][k]);
                }
                if (j >= mapp[i].p) {
                    f[i][j][k] = std::max(f[i - 1][j - mapp[i].p][k] + mapp[i].v, f[i][j][k]);
                }
                if (j + mapp[i].p * 2 <= 5200 && k) {
                    f[i][j][k] = std::max(f[i - 1][j + mapp[i].p * 2][k - 1] + mapp[i].v, f[i][j][k]);
                }
                if (j + mapp[i].p <= 5200) {
                    f[i][j][k] = std::max(f[i - 1][j + mapp[i].p][k] + mapp[i].v, f[i][j][k]);
                }
            }
        }
    }
    ll ans = 0;
    for (int i = 0; i <= m; i++) {
        ans = std::max(ans, f[n][2600][i]);
    }
    std::cout << ans << std::endl;
    return 0;
}