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
        int a, b;
        std::cin >> a >> b;
        if (a > b) std::swap(a, b);
        if (a != 1)
            std::cout << 1 << std::endl;
        else if (b != 2)
            std::cout << 2 << std::endl;
        else
            std::cout << 3 << std::endl;
    }
    return 0;
}