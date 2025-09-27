#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>

int main() {
    int t;
    std::cin >> t;
    while (t--) {
        int n;
        std::cin >> n;
        int a, b = 0, ans = 1e9;
        for (int i = 1; i <= n; i++) {
            std::cin >> a;
            if (i != 1) {
                ans = std::min(ans, a - b);
            }
            b = a;
        }
        if (ans < 0)
            std::cout << 0 << std::endl;
        else
            std::cout << ((ans) / 2 + 1) << std::endl;
    }
    return 0;
}