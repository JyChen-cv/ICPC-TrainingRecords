#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>

typedef long long ll;
const int N = 2e5;
ll mapp[N + 2], sum[N + 2], sum_2[N + 2], xh[N + 2];
struct group {
    int s, d, k, num;
    bool operator<(const group &t) const {
        return d < t.d;
    }
    ll ans;
} que[N + 2];

bool cmp(group x, group y) {
    return x.num < y.num;
}

int main() {
    int t;
    std::cin >> t;
    while (t--) {
        int n, m;
        std::cin >> n >> m;
        for (int i = 1; i <= n; i++) {
            scanf("%lld", mapp + i);
        }
        for (int i = 1; i <= m; i++) {
            int a, b, c;
            scanf("%d%d%d", &a, &b, &c);
            que[i] = (group){a, b, c, i, 0};
        }
        std::sort(que + 1, que + m + 1);
        for (int i = 1; i <= m; i++) {
            int d = que[i].d, s = que[i].s, k = que[i].k;
            int e = s + (k - 1) * d;

            if ((ll)d * d > n) {
                for (int j = s, ti = 0; j <= e; j += d) {
                    que[i].ans += (++ti) * mapp[j];
                }
            } else {
                if (que[i].d == que[i - 1].d) {
                    que[i].ans = sum_2[s] - sum_2[std::min(e + d, n + 1)] - (xh[s] - xh[e] + 1) * (sum[std::min(e + d, n + 1)]);
                } else {
                    sum[n + 1] = sum_2[n + 1] = xh[n + 1] = 0;
                    for (int i = n; i >= 1; i--) {
                        sum[i] = sum[std::min(n + 1, i + d)] + mapp[i];
                        xh[i] = xh[std::min(n + 1, i + d)] + 1;
                    }
                    for (int i = n; i >= 1; i--) {
                        sum_2[i] = sum_2[std::min(n + 1, i + d)] + sum[i];
                    }
                    que[i].ans = sum_2[s] - sum_2[std::min(e + d, n + 1)] - (xh[s] - xh[e] + 1) * (sum[std::min(e + d, n + 1)]);
                }
            }
        }
        std::sort(que + 1, que + m + 1, cmp);
        for (int i = 1; i <= m; i++) {
            printf("%lld ", que[i].ans);
        }
        puts("");
    }
    return 0;
}