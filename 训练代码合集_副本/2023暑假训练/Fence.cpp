#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <vector>

const int N = 100, M = 15000;
struct rec {
    int l, p, s;
    bool operator<(const rec t) const {
        return s < t.s;
    }
} a[N + 2];
int n, m, f[N + 2][M + 2], q[M + 2];

int calc(int i, int k) {
    return f[i - 1][k] - a[i].p * k;
}

int main() {
    std::cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        scanf("%d%d%d", &a[i].l, &a[i].p, &a[i].s);
    }
    std::sort(a + 1, a + m + 1);
    for (int i = 1; i <= m; i++) {
        int l = 1, r = 0;
        for (int k = std::max(0, a[i].s - a[i].l); k <= a[i].s - 1; k++) {
            while (l <= r && calc(i, q[r]) <= calc(i, k)) r--;  // 对于一个新元素，把它添加到单调队列中的同时维护单调队列的性质
            q[++r] = k;
        }
        for (int j = 1; j <= n; j++) {
            f[i][j] = std::max(f[i - 1][j], f[i][j - 1]);
            if (j >= a[i].s) {
                while (l <= r && q[l] < j - a[i].l) l++;  // 排除长度不满足条件的情况
                if (l <= r) f[i][j] = std::max(f[i][j], calc(i, q[l]) + a[i].p * j);
            }
        }
        std::cout << f[m][n] << std::endl;
    }
    return 0;
}