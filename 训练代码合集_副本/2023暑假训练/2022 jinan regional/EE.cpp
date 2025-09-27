#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <vector>

typedef long long ll;

ll exgcd(ll a, ll b, ll &x, ll &y) {
    if (b == 0) {
        x = 1, y = 0;
        return a;
    }
    ll d = exgcd(b, a % b, x, y);
    int z = x;
    x = y;
    y = z - y * (a / b);
    return d;
}
int main() {
    int t;
    std::cin >> t;
    while (t--) {
        ll n, m;
        std::cin >> n >> m;
        ll ls = n % m;  // 有这么多个lss+1
        ll lss = n / m;
        ll lsss = m - n % m;  // 有这么多个lss
        ll x = 0, y = 0;
        ll d = exgcd(lss, lss + 1, x, y);
        n /= 2;
        x *= 2;
        y *= 2;
        ll zxgb = lss * (lss + 1) / d;
        if (x < 0) {
            ll xx = (x % (zxgb / (lss + 1)) + (zxgb / (lss + 1)));
            ll cnt = (xx - x) / (zxgb / (lss + 1)) * (zxgb / (lss));
            if (y >= cnt && (y - cnt) <= ls && (xx <= lsss))
                std::cout << "Yes" << std::endl;
            else
                std::cout << "No" << std::endl;
        } else {
            ll yy = (y % (zxgb / (lss)) + (zxgb / (lss)));
            ll cnt = (yy - y) / (zxgb / (lss)) * (zxgb / (lss + 1));
            if (x >= cnt && (x - cnt) <= lsss && yy <= ls)
                std::cout << "Yes" << std::endl;
            else
                std::cout << "No" << std::endl;
        }
    }
    return 0;
}