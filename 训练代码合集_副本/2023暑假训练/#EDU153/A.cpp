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
        std::string s;
        std::cin >> s;
        int n = s.size();
        int tag = 0;
        for (int i = 1; i < n; i++) {
            if (s[i] != s[i - 1]) tag++;
        }
        if (n == 2) {
            if (s == "()")
                std::cout << "NO" << std::endl;
            else if (s == ")(")
                std::cout << "YES" << std::endl
                          << "(())" << std::endl;
            else if (s == "((") {
                std::cout << "YES" << std::endl
                          << "()()" << std::endl;
            } else {
                std::cout << "YES" << std::endl
                          << "()()" << std::endl;
            }
            continue;
        }
        if (n == 1) {
            std::cout << "NO" << std::endl;
            continue;
        }
        std::cout << "YES" << std::endl;
        if (tag <= 1) {
            for (int i = 1; i <= n * 2; i++) {
                if (i % 2 == 1)
                    std::cout << "(";
                else
                    std::cout << ")";
            }
        } else {
            for (int i = 1; i <= n; i++) {
                std::cout << "(";
            }
            for (int i = 1; i <= n; i++) {
                std::cout << ")";
            }
        }
        std::cout << std::endl;
    }
    return 0;
}