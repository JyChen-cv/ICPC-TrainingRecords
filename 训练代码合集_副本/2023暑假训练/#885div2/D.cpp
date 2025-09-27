// *** //
// 原函数不满足凸性，不能直接三分，需要把原函数转变成关于循环s的函数，再利用三分解决

#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <vector>

typedef long long LL;

LL check(LL x, LL y, LL z) {
    return (x + y * 20) * (z - y * 4);
}

int main() {
    int t;
    std::cin >> t;
    while (t--) {
        LL n, k, ans = 0;
        std::cin >> n >> k;
        ans = std::max(ans, n * k);
        if (k == 0) {
            std::cout << ans << std::endl;
            continue;
        } else
            ans = std::max(ans, (n + n % 10) * (k - 1));
        k--;
        n += n % 10;
        if (n % 10 == 0 || !k) {
            std::cout << ans << std::endl;
            continue;
        }
        for (int i = 0; i <= 4; i++) {
            if (!k) break;
            if (i) {
                n += n % 10;
                k--;
            }
            LL l = 0, r = k / 4;
            while (l < r) {
                LL mid1 = l + (r - l) / 3;
                LL mid2 = r - (r - l) / 3;
                if (check(n, mid1, k) > check(n, mid2, k)) {
                    r = mid2 - 1;
                } else
                    l = mid1 + 1;
            }
            ans = std::max(ans, check(n, l, k));
        }
        std::cout << ans << std::endl;
    }
    return 0;
}
