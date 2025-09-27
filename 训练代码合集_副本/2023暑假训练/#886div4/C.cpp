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
        char c;
        for (int i = 1; i <= 8; i++) {
            for (int j = 1; j <= 8; j++) {
                std::cin >> c;
                if (c != '.') std::cout << c;
            }
        }
        std::cout << std::endl;
    }
    return 0;
}