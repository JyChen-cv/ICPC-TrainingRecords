// https://www.luogu.com.cn/problem/P2150

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

const int N = 22;
int v[N + 2];
std::vector<int> pri;
int dp[500][500];
struct group {
    int mx, d;
    bool operator<(const group &t) const {
        return mx < t.mx;
    }
} deal[500 + 2];
int res[500][500], p1[500][500], p2[500][500];
int n, mod;

void dl(int f[][500], int s, int e, int tag) {
    for (int j = 0; j < (1 << 8); j++) {
        for (int k = 0; k < (1 << 8); k++) {
            f[j][k] = dp[j][k];
        }
    }
    for (int i = s; i <= e; i++) {
        memset(res, 0, sizeof(res));
        for (int j = 0; j < (1 << 8); j++) {
            for (int k = 0; k < (1 << 8); k++) {
                if ((k & deal[i].d) == 0 && (!tag || tag == 2))
                    (res[j | deal[i].d][k] += f[j][k]) %= mod;
                if ((j & deal[i].d) == 0 && (tag || tag == 2))
                    (res[j][k | deal[i].d] += f[j][k]) %= mod;
            }
        }
        for (int j = 0; j < (1 << 8); j++) {
            for (int k = 0; k < (1 << 8); k++) {
                f[j][k] += res[j][k];
            }
        }
    }
}
void solve() {
    std::cin >> n >> mod;
    for (int i = 2; i <= n; i++) {
        int ls = i;
        for (int j = 0; j < (int)pri.size(); j++) {
            while (ls % pri[j] == 0) {
                deal[i].d |= (1 << j);
                ls /= pri[j];
            }
        }
        if (ls != 1) deal[i].mx = ls;
    }
    // std::cout << pri.size() << std::endl;
    std::sort(deal + 2, deal + n + 1);
    // for (int i = 2; i <= n; i++) {
    //     std::cout << deal[i].d << " " << deal[i].mx << std::endl;
    // }
    int frt = 2, tal = 2;
    dp[0][0] = 1;
    while (frt <= n && tal <= n) {
        while (deal[tal + 1].mx == deal[frt].mx && tal + 1 <= n) tal++;
        // std::cout << frt << " " << tal << " " << deal[tal].mx << " " << deal[tal + 1].mx << std::endl;
        // if (tal < frt) break;
        if (deal[tal].mx == 0) {
            dl(p1, frt, tal, 2);
            for (int j = 0; j < (1 << 8); j++) {
                for (int k = 0; k < (1 << 8); k++) {
                    dp[j][k] = p1[j][k];
                }
            }
        } else {
            dl(p1, frt, tal, 0), dl(p2, frt, tal, 1);
            // std::cout << frt << " " << tal << std::endl;
            for (int j = 0; j < (1 << 8); j++) {
                for (int k = 0; k < (1 << 8); k++) {
                    dp[j][k] = (p1[j][k] + p2[j][k] - dp[j][k]) % mod + mod;
                    dp[j][k] %= mod;
                }
            }
        }
        // std::cout << frt << " " << tal << " " << deal[tal].mx << std::endl;
        tal++;
        frt = tal;
    }
    int ans = 0;
    for (int i = 0; i < (1 << 8); i++) {
        for (int j = 0; j < (1 << 8); j++) {
            if (i & j) continue;
            (ans += dp[i][j]) %= mod;
        }
    }
    // for (int i = 0; i <= 5; i++) {
    // 	for (int j = 0; j <= 5; j++) {
    // 		std::cout << dp[i][j] << " \n"[j == 5];
    // 	}
    // }
    std::cout << ans << std::endl;
}

signed main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0), std::cout.tie(0);

    for (int i = 2; i <= N; i++) {
        if (!v[i]) pri.push_back(i);
        for (int j = 2; j * i <= N; j++) v[i * j] = 1;
    }
    // for (auto i : pri) std::cout << i << std::endl;
    int times = 1;
    // std::cin >> times;
    while (times--) {
        solve();
    }
    return 0;
}