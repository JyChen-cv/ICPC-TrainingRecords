#include <cstdio>
#include <iostream>

int main() {
    double a = 140;
    for (int i = 1; i <= 100; i++) {
        std::cout << a << std::endl;
        a = (1 * a - 5) / 4;
    }
    std::cout << a << std::endl;
    return 0;
}