#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <vector>

typedef long long ll;
const ll mod = 100003;

ll q_pow(ll x, ll y) {
    if (y == 0) return 1;
    ll mid = y / 2;
    ll ls = q_pow(x, mid);
    if (y % 2)
        return ls * ls % mod * x % mod;
    else
        return ls * ls % mod;
}

int main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);
    ll x, y;
    std::cin >> x >> y;
    ll res = x * q_pow(x - 1, y - 1) % mod;
    ll ans = q_pow(x, y);
    ans -= res;
    ans %= mod;
    ans += mod;
    ans %= mod;
    std::cout << ans << std::endl;
    return 0;
}