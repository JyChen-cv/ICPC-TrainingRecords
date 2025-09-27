#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>

int main() {
    int t;
    std::cin >> t;
    while (t--) {
        int n, k, all = 2023, tag = 0;
        std::cin >> n >> k;
        for (int i = 1; i <= n; i++) {
            int a;
            std::cin >> a;
            if (all % a) tag = 1;
            all /= a;
        }
        if (tag) {
            std::cout << "NO" << std::endl;
            continue;
        }
        std::cout << "Yes" << std::endl;
        std::cout << all << " ";
        for (int i = 2; i <= k; i++) {
            std::cout << 1 << " ";
        }
        std::cout << std::endl;
    }
    return 0;
}