#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>

#define int long long
#define it __int128_t
const int mod = 1e9 + 7;
struct node {
    int l, r, res;
    inline void set() {
        l = r = 0;
        res = -1;
    }
} dp[65][65];

node dfs(int x, int y) {
    if (x == 0) return dp[x][y] = (node){1, 1, 1};
    if (y == 0) return dp[x][y] = (node){1, 0, 1};
    if (~dp[x][y].res) return dp[x][y];
    dp[x][y].res = 0;
    dp[x][y].res += (dfs(x - 1, y).res + dfs(x - 1, y - 1).res) % mod;
    dp[x][y].res %= mod;
    if (dp[x - 1][y].l == ((1LL << (x - 1))))
        dp[x][y].l = (dp[x - 1][y].l + dp[x - 1][y - 1].l) % mod;
    else
        dp[x][y].l = dp[x - 1][y].l;
    if (dp[x - 1][y - 1].r == ((1LL << (x - 1))))
        dp[x][y].r = (dp[x - 1][y].r + dp[x - 1][y - 1].r) % mod;
    else
        dp[x][y].r = dp[x - 1][y - 1].r;
    dp[x][y].res += ((it)dp[x - 1][y].r * dp[x - 1][y - 1].l) % mod;
    dp[x][y].res %= mod;
    // dp[x][y].r %= mod;
    // dp[x][y].l %= mod;
    // std::cout << x << " " << y << " " << dp[x][y].res << " " << dp[x][y].l << " " << dp[x][y].r << std::endl;
    return dp[x][y];
}

void solve() {
    for (int i = 62; i >= 0; i--) {
        for (int j = 62; j >= 0; j--) {
            dp[i][j].set();
        }
    }
    int n, k;
    std::cin >> n >> k;
    // n--;  // 这里是包含的数字的个数，不能有0也有意义的情况，所以都往后评议一个问题，所以不--
    node ans;
    ans.set();
    ans.res = 0;
    for (int i = 62; i >= 0; i--) {
        if (n >= (1LL << i)) {
            // std::cout << n << " " << (1LL << i) << std::endl;
            node ls = dfs(i, k);
            ans.res += ls.res;
            ans.res %= mod;
            ans.res += ((it)ls.l * ans.r) % mod;
            ans.res %= mod;
            if (ls.r == (1LL << i)) {
                ans.r += ls.l;
                ans.r %= mod;
            } else
                ans.r = ls.r;
            n -= (1LL << i);
            k--;
            if (k < 0) break;
        }
    }
    // for (int i = 2; i >= 0; i--) {
    //     for (int j = 2; j >= 0; j--) {
    //         std::cout << i << " " << j << " " << dp[i][j].l << " " << dp[i][j].r << " " << dp[i][j].res << std::endl;
    //     }
    // }
    std::cout << ans.res << std::endl;
}

signed main() {
    int t;
    std::cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}

/*
1
75198207456100 24
*/