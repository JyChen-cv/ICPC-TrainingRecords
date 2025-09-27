#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>

int main() {
    int t;
    std::cin >> t;
    while (t--) {
        int n, m, k;
        std::cin >> n >> m >> k;
        int a, b;
        std::cin >> a >> b;
        int aa, bb, tag = 0;
        for (int i = 1; i <= k; i++) {
            std::cin >> aa >> bb;
            int ls = std::abs(a - aa) + std::abs(b - bb);
            if (ls % 2 == 0) tag = 1;
        }
        if (tag)
            std::cout << "NO" << std::endl;
        else
            std::cout << "YES" << std::endl;
    }
    return 0;
}