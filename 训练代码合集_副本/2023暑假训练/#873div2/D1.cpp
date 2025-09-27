#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <vector>

const int N = 5e3;
const int inf = 1e9;
int mapp[N + 2], mx[N + 2][N + 2], mn[N + 2][N + 2];

int main() {
    int t;
    std::cin >> t;
    while (t--) {
        int n;
        scanf("%d", &n);
        for (int i = 1; i <= n; i++) {
            scanf("%d", mapp + i);
            mx[i][i] = mapp[i];
            mn[i][i] = mapp[i];
        }
        for (int len = 2; len <= n; len++) {
            for (int l = 1; l + len - 1 <= n; l++) {
                int r = l + len - 1;
                mx[l][r] = 0;
                mx[l][r] = std::max(mx[l][r - 1], mapp[r]);
            }
        }
        for (int len = 2; len <= n; len++) {
            for (int l = 1; l + len - 1 <= n; l++) {
                int r = l + len - 1;
                mn[l][r] = inf;
                mn[l][r] = std::min(mn[l][r - 1], mapp[r]);
                // std::cout << mn[l][r] << " ";
            }
            // std::cout << std::endl;
        }

        long long ans = 0;
        for (int len = 1; len <= n; len++) ans += (len - 1) * (n - len + 1);
        for (int i = 1; i < n; i++) {
            int l = 1, r = i + 1;
            while (l <= i && r <= n) {
                if (mn[i + 1][r] > mx[l][i]) {
                    r++;
                    ans -= (i - l + 1);
                } else
                    l++;
            }
        }
        std::cout << ans << std::endl;
    }
    return 0;
}