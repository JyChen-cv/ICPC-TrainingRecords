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
        m += k;
        std::cout << std::min(2 * n - 1, 2 * m + 1) << std::endl;
    }
    return 0;
}