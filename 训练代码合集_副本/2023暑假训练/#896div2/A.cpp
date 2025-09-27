#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <vector>

const int N = 1000;
int mapp[N + 2];
int main() {
    int t;
    std::cin >> t;
    while (t--) {
        int n;
        std::cin >> n;
        for (int i = 1; i <= n; i++) {
            std::cin >> mapp[i];
        }
        if (n == 1)
            std::cout << 0 << std::endl;
        else {
            if (n == 2)
                std::cout << 2 << std::endl;
            else
                std::cout << 4 << std::endl;
            std::cout << 1 << " " << 2 << std::endl;
            std::cout << 1 << " " << 2 << std::endl;
            if (n == 2) continue;
            if (!(n % 2)) {
                std::cout << 3 << " " << n << std::endl;
                std::cout << 3 << " " << n << std::endl;
            } else {
                std::cout << 2 << " " << n << std::endl;
                std::cout << 2 << " " << n << std::endl;
            }
        }
    }
    return 0;
}