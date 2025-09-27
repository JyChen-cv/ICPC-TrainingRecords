#include <cstdio>
#include <iostream>

#define int long long
const int mod = 1e9 + 7;
const int N = 1e6;
int p[N + 2], inp[N + 2], g[N + 2];

inline int q_pow(int x, int y) {
    if (y == 0) return 1;
    int mid = q_pow(x, y / 2);
    if (y % 2)
        return mid * mid % mod * x % mod;
    else
        return mid * mid % mod;
}
inline int inv(int x) {
    return q_pow(x, mod - 2);
}
inline int C(int x, int y) {
    return p[x] / p[y] / p[x - y];
}

signed main() {
    p[0] = 1;
    for (int i = 1; i <= 20; i++) {
        p[i] = p[i - 1] * i;
    }

    int n;
    std::cin >> n;
    for (int i = 0; i <= n; i++) g[i] = C(n, i) * p[n - i];
    int ans = 0;
    for (int i = 0; i <= n; i++) {
        if ((i - 0) % 2 == 0) {
            ans += C(i, 0) * g[i];
        } else {
            ans -= C(i, 0) * g[i];
        }
    }
    std::cout << ans << std::endl;
    return 0;
}