#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>

typedef long long ll;
const int N = 1e5;
ll mapp[N + 2];

inline ll deal(ll x, ll y) {
    int res = 0, tag = 0;
    if (y > x) std::swap(x, y);
    while (x) {
        int l = x % 10;
        int ll = y % 10;
        x /= 10;
        y /= 10;
        l += tag + ll;
        l /= 10;
        tag = l;
        res += l;
    }
    return res;
}
int main() {
    int t;
    std::cin >> t;
    while (t--) {
        int n;
        std::cin >> n;
        for (int i = 1; i <= n; i++) {
            std::cin >> mapp[i];
        }
        ll s = 0, ans = 0;
        for (int i = 1; i <= n; i++) {
            ans += deal(s, mapp[i]);
            s += mapp[i];
        }
        std::cout << ans << std::endl;
    }
    return 0;
}