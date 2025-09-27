#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <vector>

const int N = 100;
int mapp[N + 2][N + 2], aaa[N + 2][N + 2];
int main() {
    int n, m;
    std::cin >> n >> m;
    n++, m++;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            int s, x, z, y, ans = 0;
            s = i - 1, x = n - i;
            z = j - 1, y = m - j;
            ans += std::min(s, y);
            ans += std::min(y, x);
            ans += std::min(x, z);
            ans += std::min(s, z);

            for (int k = 2; k <= 100; k++) {
                int ls1 = 1 + k - i;
                int ls2 = n - i;
                ls1 = std::max(1, ls1);
                ls2 = std::min(k - 1, ls2);
                int ls = ls2 - ls1 + 1;
                // if (i == 3 && j == 1) std::cout << ls << " " << k << " " << ls1 << " " << ls2 << std::endl;
                if (ls < 0) break;
                if (y >= k) ans += ls;
                if (z >= k) ans += ls;
            }
            for (int k = 2; k <= 100; k++) {
                int ls1 = 1 + k - j;
                int ls2 = m - j;
                ls1 = std::max(1, ls1);
                ls2 = std::min(k - 1, ls2);
                int ls = ls2 - ls1 + 1;
                // if (i == 3 && j == 1) std::cout << ls << " " << k << " " << ls1 << " " << ls2 << std::endl;
                if (ls < 0) break;
                if (s >= k) ans += ls;
                if (x >= k) ans += ls;
            }
            std::cout << ans << " ";
        }
        std::cout << std::endl;
    }
    return 0;
}