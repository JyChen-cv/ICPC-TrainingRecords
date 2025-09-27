#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>

typedef long long ll;
const ll mod = 998244353;

// ll exgcd(ll a, ll b, ll &x, ll &y) {
//     if (b == 0) {
//         x = 1, y = 0;
//         return a;
//     }
//     int d = exgcd(b, a % b, x, y);
//     int z = x;
//     x = y, y = z - y * (a / b);
//     return d;
// }

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

int main() {
    ll a, b;
    std::cin >> a >> b;
    // a %= mod, b %= mod;

    if (a == 1) {
        std::cout << 0 << std::endl;
        return 0;
    } else if (a == 998244353 && b == 1) {
        std::cout << a - 1 << std::endl;  // q_pow(a,b-1)*(a-1)%a== 0 或者 a-1; 取决于b是否等于1
        return 0;
    }

    ll ans = q_pow(a, b);
    for (int i = 2; i <= std::sqrt(a); i++) {
        if (a % i == 0) {
            ans *= ((i - 1) * inv(i)) % mod;
            ans %= mod;
        }
        while (a % i == 0) a /= i;
    }
    if (a > 1) ans = ans * (a - 1) % mod * inv(a) % mod;
    std::cout << ans << std::endl;
    return 0;
}