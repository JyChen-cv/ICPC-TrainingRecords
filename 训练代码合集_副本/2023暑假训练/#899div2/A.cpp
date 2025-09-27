#include <cstdio>
#include <cstring>
#include <iostream>

int main() {
    int t;
    std::cin >> t;
    while (t--) {
        int n, yi = 0;
        std::cin >> n;
        for (int i = 1; i <= n; i++) {
            int a;
            std::cin >> a;
            if (a == i + yi) yi++;
        }
        std::cout << n + yi << std::endl;
    }
    return 0;
}