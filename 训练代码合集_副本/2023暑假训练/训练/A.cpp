#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>

const int N = 1e5;
long long mapp[N + 2], m, sum;
int n;

long long gcd(long long x, long long y) {
    return y ? gcd(y, x % y) : x;
}
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

void deal(long long &x, long long y) {
    x = (x % y + y) % y;
}
void deal(long long &x, long long y, long long z) {
    long long c = gcd(y, z);
    c = z / c;
    deal(x, c);
}

int main() {
    std::cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        std::cin >> mapp[i];
        sum += mapp[i];
        sum %= m;
    }
    long long a1 = n % m;
    long long a2 = (n * (n + 1) / 2) % m;
    long long x = 0, y = 0, d = exgcd(a1, a2, x, y);
    x = (x % m + m) % m, y = (y % m + m) % m;
    // std::cout << x << " " << y << std::endl;
    // deal(x, a1, m), deal(y, a2, m);
    long long x2 = 0, y2 = 0, d2 = exgcd(d, m, x2, y2);
    long long ans = sum % d2, k = (sum - ans) / d2;
    k = ((-k) % m + m) % m;
    // std::cout << x2 << " " << y2 << " " << k << std::endl;
    x2 = (x2 % m + m) % m;
    // deal(x2, m / d2);  // 只要保证x2为正就行
    std::cout << ans << std::endl;
    std::cout << k * x % m << " " << k * y % m << std::endl;
    return 0;
}