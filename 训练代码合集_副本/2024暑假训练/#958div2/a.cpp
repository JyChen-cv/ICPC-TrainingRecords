#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>

void solve() {
    int n, k;
    std::cin >> n >> k;
    int deal = 0;
    while (n != 1) {
        deal++;
        if (n > k) {
            n -= k - 1;
        } else {
            n = 1;
        }
    }
    std::cout << deal << std::endl;
}

int main() {
    int times;
    std::cin >> times;
    while (times--) {
        solve();
    }
    return 0;
}