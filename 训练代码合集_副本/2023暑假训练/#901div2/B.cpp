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
        int a, b, k;
        std::cin >> a >> b >> k;
        long long sum = 0, a1 = 0, a2 = 1e12, b1 = 0, b2 = 1e12;
        for (int i = 1; i <= a; i++) {
            int x;
            std::cin >> x;
            sum += x;
            a1 = std::max(a1, (long long)x);
            a2 = std::min(a2, (long long)x);
        }
        for (int i = 1; i <= b; i++) {
            int x;
            std::cin >> x;
            b1 = std::max(b1, (long long)x);
            b2 = std::min(b2, (long long)x);
        }
        if (!k) {
            std::cout << sum << std::endl;
            continue;
        }
        if (a2 < b1) {
            sum += (b1 - a2);
            a1 = std::max(a1, b1);
            b2 = std::min(a2, b2);
        }
        if (k % 2) {
            std::cout << sum << std::endl;
            continue;
        }
        sum -= (a1 - b2);
        std::cout << sum << std::endl;
    }
    return 0;
}