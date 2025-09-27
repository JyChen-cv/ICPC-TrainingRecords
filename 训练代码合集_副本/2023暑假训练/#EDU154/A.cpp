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
        int tag = 0;
        for (int i = 1; i <= 9; i++) {
            std::cin >> c;
            if (c == '1')
                tag = 1;
            else if (c == '7') {
                if (tag)
                    std::cout << 17 << std::endl;
                else
                    std::cout << 71 << std::endl;
            }
        }
    }
    return 0;
}