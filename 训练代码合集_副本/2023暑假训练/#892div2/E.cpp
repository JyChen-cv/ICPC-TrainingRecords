#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <vector>

const int N = 3000;
typedef long long LL;
LL a[N + 2], b[N + 2], f[N + 2][N + 2];

LL deal(int l, int r) {
    return std::abs(a[l] - b[r]) + std::abs(a[r] - b[l]);
}

int main() {
    int t;
    std::cin >> t;
    while (t--) {
        int n, k;
        std::cin >> n >> k;
        for (int i = 1; i <= n; i++) std::cin >> a[i];
        for (int i = 1; i <= n; i++) std::cin >> b[i];
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) f[i][j] = 0;
        }
        LL ans = 0;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= std::min(k, i); j++) {
                f[i][j]=f[i-1][j];
                for (int l = 1; l <= std::min(k, i); l++) {
                    f[i][j] = std::max(f[i][j], f[i - l][j - l] + deal(i - l + 1, i));
                }
            }
            ans = std::max(ans, f[i][k]);
        }
        std::cout << ans << std::endl;
    }
    return 0;
}