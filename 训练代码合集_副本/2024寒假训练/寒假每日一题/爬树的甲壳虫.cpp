#include <iostream>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <cstdio>

typedef long long ll;
const ll mod = 998244353;

ll q_pow(ll x, ll y) {
    if (y == 0) return 1;
    ll mid = q_pow(x, y / 2);
    if (y % 2)
        return mid * mid % mod * x % mod;
    else
        return mid * mid % mod;
}

ll inv(ll a) {
    return q_pow(a, mod - 2);
}

int main()
{
    ll n, ans = 0;
    std::cin >> n;
    for (int i = 1; i <= n; i++) {
        ll a, b;
        std::cin >> a >> b;
        ans = (ans + 1) % mod;
        ans = ans * b % mod * inv(b - a) % mod;
    }
    std::cout << ans << std::endl;
    return 0;
}