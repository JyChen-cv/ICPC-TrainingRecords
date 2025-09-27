#include <cstdio>
#include <iostream>

int main() {
    int t;
    std::cin >> t;
    while (t--) {
        int n;
        std::cin >> n;
        std::cout << (n + 1) / 2 + 1 << std::endl;
    }
    return 0;
}