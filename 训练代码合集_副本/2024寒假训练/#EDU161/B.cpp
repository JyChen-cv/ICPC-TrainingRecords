#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <queue>
#include <vector>

typedef long long ll;
const int N = 3e5;
ll mapp[N + 2], s[N + 2];

ll C(int x, int y) {
    if (x < y) return 0;
    ll res = 1;
    for (int i = x; i > (x - y); i--) {
        res *= i;
    }
    for (int i = y; i >= 1; i--) {
        res /= i;
    }
    return res;
}

int main() {
    int t;
    std::cin >> t;
    while (t--) {
        int n;
        std::cin >> n;
        for (int i = 0; i <= n; i++) mapp[i] = 0;
        for (int i = 1; i <= n; i++) {
            ll a;
            std::cin >> a;
            mapp[a]++;
        }
        s[0] = mapp[0];
        for (int i = 1; i <= n; i++) {
            s[i] = mapp[i] + s[i - 1];
        }
        ll ans = 0;
        for (int i = 0; i <= n; i++) {
            ans += C(mapp[i], 3) + C(mapp[i], 2) * s[i - 1];
            // std::cout << ans << std::endl;
        }
        std::cout << ans << std::endl;
    }
    return 0;
}