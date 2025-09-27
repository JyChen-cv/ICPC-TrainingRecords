#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <vector>

#define int long long
const int N = 1 << 12;
int d[N + 2][15], v[N + 2];
int lowbit(int x) {
    return x & (-x);
}

int deal(int x, int len) {
    int tag = -1;
    for (int i = 0; i < len; i++) {
        if ((x & (1 << i))) {
            // std::cout << x << " " << i << " " << tag << std::endl;
            if ((i - tag - 1) % 2 == 1) return 0;
            tag = i;
        }
    }
    if ((len - 1 - tag) % 2) return 0;
    return 1;
}

signed main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);

    int n, m;
    while (std::cin >> n >> m, n) {
        memset(v, 0, sizeof(v));
        for (int i = 0; i < (1 << m); i++) {
            if (deal(i, m)) v[i] = 1;
            // std::cout << i << " " << v[i] << std::endl;
        }
        d[0][0] = 1;
        for (int i = 1; i <= n; i++) {
            for (int j = 0; j < (1 << m); j++) {
                d[j][i] = 0;
                for (int k = 0; k < (1 << m); k++) {
                    if (v[j | k] && (j & k) == 0) d[j][i] += d[k][i - 1];
                }
            }
        }
        std::cout << d[0][n] << std::endl;
    }
    return 0;
}