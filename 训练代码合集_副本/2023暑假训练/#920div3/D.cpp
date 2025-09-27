#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>

#define int long long
const int N = 2e5;
int mapp[N + 2], tag[N + 2];
signed main() {
    int t;
    std::cin >> t;
    while (t--) {
        int n, m;
        std::cin >> n >> m;
        for (int i = 1; i <= n; i++) {
            std::cin >> mapp[i];
        }
        for (int i = 1; i <= m; i++) {
            std::cin >> tag[i];
        }
        std::sort(mapp + 1, mapp + n + 1);
        std::sort(tag + 1, tag + m + 1);
        int l_1 = 1, r_1 = n, l_2 = 1, r_2 = m, sum = 0;
        for (int i = 1; i <= n; i++) {
            int ls1 = std::abs(mapp[l_1] - tag[r_2]);
            int ls2 = std::abs(mapp[r_1] - tag[l_2]);
            if (ls1 > ls2) {
                l_1++;
                r_2--;
                sum += ls1;
            } else {
                l_2++;
                r_1--;
                sum += ls2;
            }
            // std::cout << ls1 << " " << ls2 << std::endl;
        }
        std::cout << sum << std::endl;
    }
    return 0;
}