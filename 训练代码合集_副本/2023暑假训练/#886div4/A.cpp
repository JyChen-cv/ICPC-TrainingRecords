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
        int a, b, c;
        std::cin >> a >> b >> c;
        int tag = 0;
        if (a + b >= 10)
            tag = 1;
        else if (a + c >= 10)
            tag = 1;
        else if (b + c >= 10)
            tag = 1;
        if (tag)
            std::cout << "YES" << std::endl;
        else
            std::cout << "NO" << std::endl;
    }
    return 0;
}