#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>

#define int long long
void solve() {
    int n, m, k;
    std::cin >> n >> m >> k;
    for (int i = n; i >= 1; i--) {
        if (i <= m)
            std::cout << m + 1 - i << " \n"[i == 1];
        else
            std::cout << i << " \n"[i == 1];
    }
}

signed main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);
    std::cout.tie(0);
    int t;
    std::cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}