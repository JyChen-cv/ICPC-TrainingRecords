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
    ll z = x;
    x = y;
    y = z - y * (a / b);
    return d;
}

ll a, b, c, d, xx0, yy0;

double check(double k) {
    return std::fabs((double)c / d * xx0 + k * b / d) + std::fabs((double)c / d * yy0 - k * a / d);
}

int main() {
    int t;
    std::cin >> t;
    while (t--) {
        std::cin >> a >> b >> c;
        d = exgcd(a, b, xx0, yy0);
        if (c % d) {
            std::cout << -1 << std::endl;
            continue;
        }

        double l = -1000000000, r = 1000000000;
        while (l < r - 1) {
            double mid1 = (r + 2 * l) / 3;
            double mid2 = (r * 2 + l) / 3;
            // std::cout << mid1 << " " << mid2 << std::endl;
            if (check(mid1) > check(mid2))
                l = mid1;
            else
                r = mid2;
        }
        ll ans1 = 2 * check((ll)l);
        ll xx1 = c / d * xx0 + (ll)l * b / d;
        ll yy1 = c / d * yy0 - (ll)l * a / d;
        if (xx1 < 0 || yy1 < 0) ans1 -= 1;
        ll ans2 = 2 * check(((ll)l + 1));
        ll xx2 = c / d * xx0 + ((ll)l + 1) * b / d;
        ll yy2 = c / d * yy0 - ((ll)l + 1) * a / d;
        if (xx2 < 0 || yy2 < 0) ans2 -= 1;
        std::cout << std::min(ans1, ans2) << std::endl;
        // std::cout << xx0 << " " << yy0 << " " << l << std::endl;
        // std::cout << 2 * std::min(check((ll)l), check((ll)l + 1)) << std::endl;
    }
    return 0;
}