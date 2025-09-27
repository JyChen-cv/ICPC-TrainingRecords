#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>

long long ans = 0;

long long q_pow(long long x, long long y) {
    if (y == 0) return 1;
    long long mid = y / 2;
    long long q = q_pow(x, mid);
    if (y % 2 == 1)
        return q * q * x;
    else
        return q * q;
}
int main() {
    int n;
    std::cin >> n;
    for (int i = 1; i <= n; i++) {
        long long a;
        scanf("%lld", &a);
        long long lst = a % 10;
        a /= 10;
        ans += q_pow(a, lst);
    }
    std::cout << ans << std::endl;
    return 0;
}