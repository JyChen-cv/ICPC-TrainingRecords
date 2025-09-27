#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>

#define int long long
const int mod = 1e9 + 7;

int qpow(int x, int y) {
    if (!y) return 1;
    int mid = qpow(x, y / 2);
    if (y % 2)
        return mid * mid % mod * x % mod;
    else
        return mid * mid % mod;
}

signed main() {
    int a = 7, res = 1;
    for (int i = 1; i <= a; i++) {
        res *= i;
    }
    std::cout << 280 * qpow(res, mod - 2) % mod << std::endl;
    return 0;
}