#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>

typedef long long ll;
ll p[50], ans;
ll deal(ll x) {
    if (x == 0) return 1;
    if (x % 3 == 0)
        return deal(x / 3) + 1;
    else
        return deal(x - 1) + 1;
}

void dfs(ll x, ll a, ll b) {
    // std::cout << x << std::endl;
    for (int i = 36; i >= 0; i--) {
        ll ls = x + p[i];
        if (ls <= b) {
            if (ls >= a) ans = std::max(ans, deal(ls));
            dfs(ls, a, b);
            break;
        }
    }
    // if (b - x <= 3) {
    //     ans = std::max(ans, deal(b));
    //     ans = std::max(ans, deal(b - 1));
    //     ans = std::max(ans, deal(b - 2));
    // }
}

void solve() {
    ll a, b;
    std::cin >> a >> b;
    ans = 0;
    dfs(-1, a, b);
    std::cout << ans << std::endl;
}

int main() {
    p[0] = 1;
    for (int i = 1; i <= 36; i++) {
        p[i] = p[i - 1] * 3;
        // std::cout << p[i] << " ";
    }
    int times;
    std::cin >> times;
    while (times--) {
        solve();
    }
    return 0;
}