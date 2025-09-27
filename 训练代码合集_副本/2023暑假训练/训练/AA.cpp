#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>

const int N = 1e5;
long long m, sum, n;

long long exgcd(long long a, long long b, long long &x, long long &y) {
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }
    long long d = exgcd(b, a % b, x, y);
    long long z = x;
    x = y;
    y = z - y * (a / b);
    return d;
}

int main() {
    std::cin >> n >> m;
    for (long long i = 1; i <= n; i++) {
        long long a;
        std::cin >> a;
        a = (a % m + m) % m;
        sum += a;
        sum %= m;
    }
    long long a1 = n;
    long long a2 = (n * (n + 1) / 2);
    long long x = 0, y = 0, d = exgcd(a1, a2, x, y);
    x = (x % m + m) % m, y = (y % m + m) % m;
    long long x2 = 0, y2 = 0, d2 = exgcd(d, m, x2, y2);
    x2 = (x2 % m + m) % m;
    long long ans = sum % d2, k = (sum - ans) / d2;
    k = ((-k) % m + m) % m;
    std::cout << ans << std::endl;
    std::cout << k * x2 % m * x % m << " " << k * x2 % m * y % m << std::endl;
    return 0;
}