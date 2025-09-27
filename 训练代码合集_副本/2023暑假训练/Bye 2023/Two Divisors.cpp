#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>

typedef long long ll;
ll gcd(ll x, ll y) {
    return y ? gcd(y, x % y) : x;
}

int main() {
    int t;
    std::cin >> t;
    while (t--) {
        ll x, y;
        std::cin >> x >> y;
        if (x > y) std::swap(x, y);
        ll ans = gcd(x, y);
        if (y % x)
            std::cout << x * y / ans << std::endl;
        else
            std::cout << y * y / x << std::endl;
    }
    return 0;
}