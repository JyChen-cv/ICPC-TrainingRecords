#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>

#define int long long
const int mod = 1e9 + 7;
int dp[35][2][2], a[35], b[35], len1, len2;

void decompose(int x, int *xl, int &len) {
    len = 0;
    while (x) {
        xl[++len] = x % 2;
        x >>= 1;
    }
}

int dfs(int x, int f1, int f2) {
    if (x == 0) return 1;
    if (~dp[x][f1][f2]) return dp[x][f1][f2];
    int u1 = (f1 == 1 ? a[x] : 1);
    int u2 = (f2 == 1 ? b[x] : 1);

    int res = 0;
    for (int i = 0; i <= u1; i++) {
        for (int j = 0; j <= u2; j++) {
            if ((i & j) == 0) res += dfs(x - 1, (f1 && (i == a[x])), (f2 && (j == b[x])));
            res %= mod;
        }
    }  // 这道题最精妙的点在于计数dp，就填写数字大小其实与数量无关，只与是否碰到边界有关
    // 能够明锐的发现问题与什么有关很重要，更重要的是能够发现问题与什么无关

    return dp[x][f1][f2] = res;
}

signed main() {
    int t;
    std::cin >> t;
    while (t--) {
        int n, m;
        std::cin >> n >> m;
        memset(a, 0, sizeof(a));
        memset(b, 0, sizeof(b));
        memset(dp, -1, sizeof(dp));
        if (n < m) std::swap(n, m);
        decompose(n, a, len1), decompose(m, b, len2);
        // for (int i = 1; i <= len1; i++) {
        //     std::cout << a[i] << " ";
        // }
        // std::cout << " " << len1 << std::endl;
        int cnt = 0, ans = 0;
        for (int i = len1; i >= 1; i--, cnt = 0) {       // 最高的1位于那个地方
            cnt += dfs(i - 1, (i == len1), (i > len2));  // 最高位确定，所以从下一位开始搜索
            if (i <= len2) cnt += dfs(i - 1, 0, (i == len2));
            cnt %= mod;
            ans += (cnt * i) % mod;
            ans %= mod;
            // std::cout << cnt << std::endl;
        }
        std::cout << ans << std::endl;
    }
    return 0;
}