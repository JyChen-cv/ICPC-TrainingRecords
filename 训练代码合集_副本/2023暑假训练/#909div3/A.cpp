#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>

int main() {
    int n;
    std::cin >> n;
    for (int i = 1; i <= n; i++) {
        int a;
        std::cin >> a;
        if (a % 3)
            std::cout << "First" << std::endl;
        else
            std::cout << "Second" << std::endl;
    }
    return 0;
}