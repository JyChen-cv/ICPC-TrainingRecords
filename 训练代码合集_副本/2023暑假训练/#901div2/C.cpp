#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>

#define double long double
typedef long long ll;
const int N = 100;
ll p2[N + 2], t[N + 2];
double c[N + 2];

ll gcd(ll x, ll y) { return y ? gcd(y, x % y) : x; }

int main() {
    t[0] = 0;
    p2[0] = 1;
    c[0] = 1;
    for (int i = 1; i <= 40; i++) {
        c[i] = c[i - 1] / 2;
        p2[i] = p2[i - 1] * 2;
        t[i] = t[i - 1] + p2[i - 1];
    }

    int tt;
    std::cin >> tt;
    while (tt--) {
        ll a, b;
        scanf("%lld%lld", &a, &b);
        ll times = gcd(a, b);
        // std::cout << times << std::endl;
        a /= times;
        b /= times;
        if (a % b == 0) {
            std::cout << 0 << std::endl;
            continue;
        }
        int tag = 0;
        for (int i = 0; i <= 40; i++) {
            if (p2[i] == b) {
                tag = 1;
                break;
            }
        }
        if (!tag) {
            std::cout << -1 << std::endl;
            continue;
        }
        ll need = 0;
        ll ss = a / b;
        double s = (double)a / b - ss;
        // std::cout << s << std::endl;
        for (int i = 0; i <= 40; i++) {
            // std::cout << s << " " << c[i] << std::endl;
            while (s >= c[i]) {
                s -= c[i];
                need += t[i] * b / p2[i];
            }
        }
        std::cout << (need)*times << std::endl;
    }
    return 0;
}