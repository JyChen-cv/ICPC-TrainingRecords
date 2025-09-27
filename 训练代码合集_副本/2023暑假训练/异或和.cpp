#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <map>
#include <vector>

typedef long long ll;
const int M = 1e6, N = 1e5;
ll s[N + 2], bit[2][M + 2], n, now, b[N + 2], ans;

inline ll deal(ll x) {
    return x & (-x);
}

void update(ll x, int y) {
    for (; x <= 1000001; x += deal(x)) {
        bit[y][x]++;
    }
}
ll query(long long x, long long y) {
    ll res = 0;
    while (x) {
        res += bit[y][x];
        x -= deal(x);
    }
    return res;
}

int main() {
    std::cin >> n;
    for (int i = 1; i <= n; i++) {
        std::cin >> s[i];
        s[i] += s[i - 1];
    }
    for (int i = 0; i <= 20; i++) {
        memset(bit, 0, sizeof(bit));
        now = 0;
        update(1, 0);  // 前缀和一定要注意s[0]的键入
        for (int j = 1; j <= n; j++) {
            ll tmp = s[j] & (1 << i);
            if (tmp) {
                now += query(b[j] + 1, 0);
                now += query(1000001, 1) - query(b[j] + 1, 1);
            } else {
                now += query(1000001, 0) - query(b[j] + 1, 0);
                now += query(b[j] + 1, 1);
            }
            update(b[j] + 1, (tmp > 0));
            b[j] += tmp;
        }
        if (now % 2) ans += (1 << i);
    }
    std::cout << ans << std::endl;
    return 0;
}
