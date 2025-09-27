#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>

#define int long long
const int mod = 1e9 + 7;

inline int qpow(int x, int y) {
    if (!y) return 1;
    int mid = qpow(x, y / 2);
    if (y % 2)
        return mid * mid % mod * x % mod;
    else
        return mid * mid % mod;
}
inline int inv(int x) {
    x %= mod;
    return qpow(x, mod - 2);
}

void solve() {
    int n, m;
    std::cin >> n >> m;
    int sum1 = 0, sum2 = 0;
    for (int i = 1; i <= n; i++) {
        int a;
        std::cin >> a;
        if (i <= m)
            sum1 = (sum1 + a) % mod;
        else
            sum2 = (sum2 + a) % mod;
    }
    int ans1 = 0, ans2 = 0;
    int f1, f2;
    if ((n - m) % 2)
        f1 = (n - m + 1) / 2, f2 = (n - m - 1) / 2;
    else
        f1 = f2 = (n - m) / 2;
    // std::cout << f1 << " " << f2 << std::endl;
    ans1 += sum2 * f1 % mod * inv(f1 + f2) % mod;
    ans2 += sum2 * f2 % mod * inv(f1 + f2) % mod;
    if ((n - m + 1) % 2)
        f1 = (n - m) / 2 + 1, f2 = (n - m) / 2;
    else
        f1 = f2 = (n - m + 1) / 2;
    ans1 += sum1 * f1 % mod * inv(f1 + f2) % mod;
    ans2 += sum1 * f2 % mod * inv(f1 + f2) % mod;
    // std::cout << f1 << " " << f2 << std::endl;
    ans1 %= mod, ans2 %= mod;
    std::cout << ans1 << " " << ans2 << std::endl;
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