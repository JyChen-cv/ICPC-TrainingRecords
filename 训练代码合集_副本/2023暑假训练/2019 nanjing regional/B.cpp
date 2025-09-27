#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>

int main() {
    int a, b, c;
    std::cin >> a >> b >> c;
    if (a == 1 && b == 0 && c == 0)
        std::cout << "YES" << std::endl
                  << 0 << std::endl;
    else if (a <= (b + c))
        std::cout << "NO" << std::endl;
    else
        std::cout << "YES" << std::endl
                  << 2 * (b + c) + 1 << std::endl;
    return 0;
}