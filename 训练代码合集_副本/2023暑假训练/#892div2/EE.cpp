#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <vector>

const int N = 3000;
typedef long long LL;
LL a[N + 2], b[N + 2], f[N + 2][N + 2],q[9000002];

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
        if (!k) {
            std::cout<<ans<<std::endl;
            continue;
        }
        for (int i = 1; i <= n; i++) {
            int l=1,r=0;
            q[++r]=1;
            for (int d = 1; d <= std::min(k, i); d++) {
                f[i][q[l]] = std::max(f[i][q[l]], f[i - l][q[l] - d] + deal(i - d + 1, i));
            }
            ans = std::max(ans, f[i][k]);
        }
        std::cout << ans << std::endl;
    }
    return 0;
}
