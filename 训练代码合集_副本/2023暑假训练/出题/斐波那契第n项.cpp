#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>

int main() {
    // freopen("/Users/chenjiayou/Downloads/未命名文件夹/Fibonacci/11.in", "r", stdin);
    // freopen("/Users/chenjiayou/Downloads/未命名文件夹/Fibonacci/11.out", "w", stdout);
    // long long n;
    // std::cin >> n;
    // int a = 0, b = 1;
    // std::cout << a << " " << b << " ";
    // for (long long i = 3; i <= n; i++) {
    //     std::cout << ((a + b) % 3) << " ";
    //     int c = b;
    //     b = (a + b) % 3;
    //     a = c;
    // }
    // if (n == 1)
    //     std::cout << "YE5" << std::endl;
    // else
    //     b % 3 == 0 ? std::cout << "YE5" << std::endl : std::cout << "N0" << std::endl;
    long long n;
    std::cin >> n;
    (n - 1) % 4 == 0 ? std::cout << "YE5" << std::endl : std::cout << "N0" << std::endl;
    return 0;
}