// poj太傻逼了
// http://poj.org/problem?id=1597

#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iostream>

typedef long long ll;
typedef double db;
typedef std::pair<int, int> PII;

inline ll gcd(ll x, ll y) {
    return y ? gcd(y, x % y) : x;
}
inline ll lcm(ll x, ll y) {
    ll res = gcd(x, y);
    return x * y / res;
}

int main() {
    // std::ios::sync_with_stdio(0);
    // std::cin.tie(0), std::cout.tie(0);
    int times = 3;
    // std::cin >> times;
    while (times) {
        ll a, b;
        if (scanf("%lld%lld", &a, &b) == EOF) break;
        ll g = gcd(a, b);
        if (g == 1) {
            printf("%10lld%10lld%s\n", a, b, "    Good Choice");
        } else
            printf("%10lld%10lld%s\n", a, b, "    Bad Choice");
    }
    puts("");
    return 0;
}