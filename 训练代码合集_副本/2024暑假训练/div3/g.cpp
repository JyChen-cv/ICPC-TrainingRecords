#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <vector>

#define int long long
const int N = 5e3;
const int mod = 1e9 + 7;
int d[N * 2 + 100];
int CC[N + 2][N + 2];

void solve() {
    int n;
    std::cin >> n;
    int ans = 0;
    for (int i = 0; i <= n; i++) {                  // 选n个数字
        for (int j = i + 1; j <= i * 2 + 1; j++) {  // 最终的贡献
            int picked = j - (i + 1);
            // std::cout << i << " " << j << " " << picked << std::endl;
            int ls = CC[std::min(j - 1, n)][picked] * j % mod;
            if (i - picked == 0) {
            } else if (n - j >= i - picked)
                ls = (ls * CC[n - j][i - picked]) % mod;
            else {
                ls = 0;
                // break;
            }
            ans += ls;
            ans %= mod;
            // std::cout << ans << std::endl;
        }
    }
    std::cout << ans << std::endl;
}

signed main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);
    std::cout.tie(0);
    d[0] = d[1] = 1;
    for (int i = 2; i <= 5000 * 2 + 5; i++) {
        d[i] = (d[i - 1] * i) % mod;
    }
    CC[0][0] = 1;
    for (int i = 1; i <= 5000; i++) {
        CC[i][0] = 1;
        for (int j = 1; j <= i; j++) {
            CC[i][j] = (CC[i - 1][j] + CC[i - 1][j - 1]) % mod;
        }
    }
    int t;
    std::cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}