#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>

#define int long long

void solve() {
    int n;
    std::cin >> n;
    int ans = n % 4;
    if (!ans)
        ans = n / 4;
    else
        ans = n / 4 + 1;
    std::cout << ans << std::endl;
}

signed main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);
    std::cout.tie(0);
    int times;
    std::cin >> times;
    while (times--) {
        solve();
    }
    return 0;
}