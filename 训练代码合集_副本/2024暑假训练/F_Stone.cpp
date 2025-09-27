#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>

const int N = 1e6;
int lowbit(int x) {
    return x & (-x);
}
int main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);
    std::cout.tie(0);
    int n;
    std::cin >> n;
    int mn = 1e9, rem = 0;
    for (int i = 1; i <= n; i++) {
        int a;
        std::cin >> a;
        if (lowbit(a) < mn) {
            mn = lowbit(a);
            rem = a;
        } else if (lowbit(a) == mn)
            rem = std::min(rem, a);
    }
    // std::cout << rem << std::endl;
    std::cout << (rem / lowbit(rem) + 1) / 2 << std::endl;
    return 0;
}