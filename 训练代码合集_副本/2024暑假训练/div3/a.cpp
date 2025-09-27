#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>

#define int long long
void solve() {
    int a[5];
    for (int i = 1; i <= 3; i++) {
        std::cin >> a[i];
    }
    for (int i = 1; i <= 5; i++) {
        std::sort(a + 1, a + 4);
        a[1]++;
    }
    std::cout << a[1] * a[2] * a[3] << std::endl;
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