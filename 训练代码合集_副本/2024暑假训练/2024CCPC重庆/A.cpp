#include <algorithm>
#include <bitset>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <unordered_map>
#include <vector>

#define int long long
typedef long long ll;
typedef double db;
typedef std::pair<int, int> PII;

const int N = 2e4, mod = 998244353;
int v[N + 2], mp[N + 2], pre[(1 << 16) + 2], inv[30];
std::vector<int> pri;
struct group {
    int mx, d;
    bool operator<(const group &t) const {
        return mx < t.mx;
    }
} deal[N + 2];
int dp[(1 << 16) + 2], ans[(1 << 16) + 2], f[(1 << 16) + 2], p[(1 << 16) + 2], res[(1 << 16) + 2];
inline int q_pow(int x, int y) {
    if (y == 0) return 1;
    int mid = q_pow(x, y / 2);
    if (y % 2)
        return mid * mid % mod * x % mod;
    else
        return mid * mid % mod;
}
inline int dinv(int x) { return q_pow(x, mod - 2); }

void dl(int s, int e, int v) {
    int val = (v - 1) * dinv(v) % mod;
    for (int i = 0; i < (1 << 16); i++) {
        f[i] = dp[i];   // 仅仅计数
        p[i] = ans[i];  // 带权值计算
    }
    for (int i = s; i <= e; i++) {
        memset(res, 0, sizeof(res));
        for (int j = 0; j < (1 << 16); j++) {
            (res[j | deal[i].d] += f[j]) %= mod;
        }
        for (int j = 0; j < (1 << 16); j++) {
            (f[j] += res[j]) %= mod;
            (p[i] += res[j] * val % mod) %= mod;
        }
    }
}

void solve() {
    int n;
    std::cin >> n;
    for (int i = 1; i <= n; i++) {
        std::cin >> mp[i];
        for (int j = 0; j < (int)pri.size(); j++) {
            while (mp[i] % pri[j] == 0) {
                deal[i].d |= (1 << j);
                mp[i] /= pri[j];
            }
        }
        if (mp[i] != 1) deal[i].mx = mp[i];
    }
    std::sort(deal + 1, deal + n + 1);
    int frt = 1, tal = 1;
    dp[0] = ans[0] = 1;
    while (tal <= n) {
        while (deal[frt].mx == deal[tal + 1].mx && tal <= n) tal++;
        if (deal[tal].mx == 0) {
            for (int i = frt; i <= tal; i++) {
                memset(res, 0, sizeof(res));
                int val = (pri[i] - 1) * inv[i] % mod;
                for (int j = 0; j < (1 << 16); j++) {
                    res[j | deal[i].d] += dp[j];
                }
                for (int j = 0; j < (1 << 16); j++) {
                    dp[j] += res[j];
                    (ans[j] += res[j] * val % mod) %= mod;
                }
            }
        } else {
            dl(frt, tal, deal[tal].mx);
            for (int j = 0; j < (1 << 16); j++) {
                dp[j] = f[j];  // 这里应该是直接赋值
                ans[j] += p[j] %= mod;
            }
        }
        tal++, frt = tal;
    }

    int as = 0;
    for (int i = 0; i < (1 << 16); i++) {
        pre[i] = 1;
        for (int j = 0; j < 16; j++) {
            if (i & (1 << j)) {
                pre[i] *= (pri[j] - 1) * inv[j] % mod;
                pre[i] %= mod;
            }
        }
    }
    for (int i = 0; i < (1 << 16); i++) {
        as += ans[i] * pre[i] % mod;
        as %= mod;
    }
    std::cout << as << std::endl;
}

signed main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0), std::cout.tie(0);
    for (int i = 2; i <= 55; i++) {
        if (v[i] == 0) pri.push_back(i);
        for (int j = 2; j * i <= 55; j++) {
            v[j * i] = 1;
        }
    }
    for (int i = 0; i < (int)pri.size(); i++) inv[i] = dinv(pri[i]);
    // std::cout << pri.size() << std::endl;
    int times = 1;
    // std::cin >> times;
    while (times--) {
        solve();
    }
    return 0;
}