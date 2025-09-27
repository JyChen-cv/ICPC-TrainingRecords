#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <map>
#include <queue>
#include <vector>

int main() {
    int t;
    std::cin >> t;
    while (t--) {
        int n;
        std::cin >> n;
        if (n == 1)
            std::cout << 1 << std::endl;
        else if (n == 2)
            std::cout << "2 1" << std::endl;
        else if (n == 3)
            std::cout << "2 1 3" << std::endl;
        else {
            int ls = (n - 3) / 2;
            int num = 3;
            std::cout << 2 << " ";
            for (int i = 1; i <= ls; i++) std::cout << (++num) << " ";
            std::cout << 1 << " ";
            for (int i = 1; i <= ls; i++) std::cout << (++num) << " ";
            if ((n % 2) == 0) std::cout << (++num) << " ";
            std::cout << 3 << std::endl;
        }
    }
    return 0;
}
