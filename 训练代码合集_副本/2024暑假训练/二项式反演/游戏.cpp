#include <algorithm>
#include <iostream>
#include <vector>

#define int long long
const int mod = 998244353;
const int N = 5000;
int p[(int)1e6 + 2], inp[(int)1e6 + 2], g[(int)1e6 + 2];
int nxt[N * 2 + 2], ver[N * 2 + 2], head[N + 2], tot;
int a[N + 2][2], sz[N + 2];
int n, m, dp[N + 2][N + 2], t[N + 2];
std::string tag;

inline int q_pow(int x, int y) {
    if (y == 0)
        return 1;
    int mid = q_pow(x, y / 2);
    if (y % 2)
        return mid * mid % mod * x % mod;
    else
        return mid * mid % mod;
}
inline int inv(int x) { return q_pow(x, mod - 2); }
inline int C(int x, int y) {
    return p[x] * inp[y] % mod * inp[x - y] % mod;
}

void add(int x, int y) {
    tot++;
    ver[tot] = y;
    nxt[tot] = head[x];
    head[x] = tot;
}

void dfs(int x, int fa) {
    std::vector<int> q(m + 5), res(m + 5);
    sz[x] = 1;
    q[0] = 1;
    for (int i = head[x]; i; i = nxt[i]) {
        int y = ver[i];
        if (y == fa) continue;
        dfs(y, x);
        a[x][0] += a[y][0];
        a[x][1] += a[y][1];
        // 仅仅缺少一个树上背包
        for (int j = 0; j <= sz[x] / 2; j++) {
            for (int k = 0; j + k <= m && k <= sz[y] / 2; k++) {
                res[j + k] += q[j] * dp[y][k] % mod;
                res[j + k] %= mod;
            }
        }
        sz[x] += sz[y];
        for (int j = 0; j <= sz[x] / 2; j++) q[j] = res[j], res[j] = 0;
    }
    // for (int i = head[x]; i; i = nxt[i]) {
    //     int y = ver[i];
    //     if (y == fa) continue;
    // }
    dp[x][0] = q[0];
    for (int i = 1; i <= sz[x] / 2; i++) {
        dp[x][i] = q[i];
        if (a[x][t[x] ^ 1] - i + 1 >= 0) dp[x][i] += q[i - 1] * ((a[x][t[x] ^ 1] - i + 1 + mod) % mod) % mod;
        dp[x][i] %= mod;
    }
    a[x][t[x]]++;
}

signed main() {
    // freopen("/Users/chenjiayou/Downloads/P6478_15.in", "r", stdin);
    p[0] = 1;
    for (long long i = 1; i <= 1e6; i++) {
        p[i] = p[i - 1] * i % mod;
    }
    inp[(long long)1e6] = inv(p[(long long)1e6]);
    for (long long i = 999999; i >= 0; i--) {
        inp[i] = inp[i + 1] * (i + 1) % mod;
    }

    std::cin >> n >> tag;
    for (int i = 1; i <= n; i++) t[i] = tag[i - 1] - '0';
    m = n / 2;
    for (int i = 1; i < n; i++) {
        int a, b;
        std::cin >> a >> b;
        add(a, b), add(b, a);
    }

    dfs(1, 0);
    // for (int i = 1; i <= n; i++) std::cout << dp[i][0] << " " << dp[i][1] << " " << dp[i][2] << std::endl;

    for (int i = 0; i <= m; i++) g[i] = dp[1][i] * p[m - i] % mod;
    // for (int i = 0; i <= m; i++) std::cout << g[i] << std::endl;
    for (int k = 0; k <= m; k++) {
        int ans = 0;
        for (int i = k; i <= m; i++) {
            if ((i - k) % 2 == 0) {
                ans += C(i, k) * g[i] % mod;
            } else {
                ans += C(i, k) * g[i] % mod * (mod - 1) % mod;
            }
            ans %= mod;
        }
        std::cout << ans << std::endl;
    }

    return 0;
}