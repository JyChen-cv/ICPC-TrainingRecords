#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <vector>

void solve() {
    int x, y, k;
    std::cin >> x >> y >> k;
    while (1) {
        int ls = x / y;
        int res = ls * y + y;
        // std::cout << res - x << std::endl;
        if (k >= res - x) {
            k -= (res - x);
            while (res % y == 0) res /= y;
            x = res;
        } else {
            break;
        }
        if (x == 1) break;
    }
    // std::cout << x << " " << k << std::endl;
    int ans;
    if (x == 1)
        ans = (x + k % (y - 1));
    else {
        ans = x + k;
        while (ans % y == 0) ans /= y;
    }
    // if (ans == y) ans = 1;
    std::cout << ans << std::endl;
}

int main() {
    int t;
    std::cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}

/*
2
1
1
2
1
1338
1
16936
1
21180097
6486
1
*/