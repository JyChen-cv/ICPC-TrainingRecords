#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>

typedef long long ll;
int main() {
    int n;
    ll k1, k2, ans = 0;
    std::cin >> n >> k1 >> k2;
    for (int i = 1; i <= n; i++) {
        std::string v;
        std::cin >> v;
        ll ls = std::min(k1 * 3, k2 * 3);
        std::sort(v.begin(), v.end());
        if (v[0] == v[1] || v[1] == v[2]) {
            ls = std::min(ls, std::min(k1, k2) + k2);
        }
        ans += ls;
    }
    std::cout << ans << std::endl;
    return 0;
}