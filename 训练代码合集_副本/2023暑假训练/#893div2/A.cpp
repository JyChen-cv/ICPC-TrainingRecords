#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <vector>

int main() {
    int t;
    std::cin >> t;
    while (t--) {
        int m, n, k;
        std::cin >> n >> m >> k;
        m += k / 2;
        n += k - (k / 2);
        if (n > m)
            std::cout << "First" << std::endl;
        else
            std::cout << "Second" << std::endl;
    }
    return 0;
}