#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <queue>
#include <vector>

#define int long long
const int N = 5e5;
int mapp[N + 2], f[N + 2], g[N + 2], fd[N + 2];
std::pair<int, int> q[N + 2];

void solve() {
    int n, k;
    std::cin >> n >> k;
    for (int i = 0; i <= n + 1; i++) mapp[i] = 0;
    for (int i = 1; i <= n; i++) {
        std::cin >> mapp[i];
    }
    for (int i = 0; i <= n + 1; i++) f[i] = g[i] = q[i].first = q[i].second = 0;
    std::string pln;
    std::cin >> pln;
    q[0] = {0, 0};  // 第一维度是序号，第二维度是代价
    int hd = 0, tl = 0;
    for (int i = 1; i <= n + 1; i++) {
        while (hd <= tl)
            if (i - q[hd].first > k)
                hd++;
            else
                break;
        f[i] = q[hd].second + mapp[i];
        if (pln[i - 1] == '1') {
            hd = tl + 1;
        } else {
            while (hd <= tl) {
                if (q[tl].second >= f[i])
                    tl--;
                else
                    break;
            }
        }
        q[++tl] = {i, f[i]};
    }
    hd = n + 1, tl = n + 1;
    q[hd] = {n + 1, 0};
    for (int i = n; i >= 0; i--) {
        while (hd <= tl)
            if (q[tl].first - i > k)
                tl--;
            else
                break;
        g[i] = q[tl].second + mapp[i];
        if (pln[i - 1] == '1') {
            tl = hd - 1;
            q[--hd] = {i, g[i]};
        } else {
            while (hd <= tl) {
                if (q[hd].second >= g[i])
                    hd++;
                else
                    break;
            }
            q[--hd] = {i, g[i]};
        }
    }
    for (int i = 0; i <= n + 1; i++) {
        g[i] -= mapp[i];
    }
    int m;
    std::cin >> m;
    for (int i = 1; i <= m; i++) {
        int a, b;
        std::cin >> a >> b;
        int c = mapp[a];
        mapp[a] = b;
        int st = std::max(a - k, 1LL * 0);
        int ed = std::min(n + 1, a + k);
        for (int j = st; j <= ed; j++) {
            fd[j] = f[j];
        }
        hd = tl = 0;
        q[0] = {st, fd[st]};
        int res = 1e18;
        for (int j = st + 1; j < a; j++) {
            if (pln[j - 1] == '1') {
                hd = tl + 1;
            } else {
                while (hd <= tl)
                    if (q[tl].second >= fd[j])
                        tl--;
                    else
                        break;
            }
            q[++tl] = {j, fd[j]};
        }
        for (int j = a; j <= ed; j++) {
            while (hd <= tl)
                if (j - q[hd].first > k)
                    hd++;
                else
                    break;
            fd[j] = q[hd].second + mapp[j];
            if (pln[j - 1] == '1') {
                hd = tl + 1;
            } else {
                while (hd <= tl) {
                    if (q[tl].second >= fd[j])
                        tl--;
                    else
                        break;
                }
            }
            q[++tl] = {j, fd[j]};
            res = std::min(res, g[j] + fd[j]);
        }
        std::cout << res << std::endl;
        mapp[a] = c;
    }
}

signed main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);
    std::cout.tie(0);
    int times;
    std::cin >> times;
    while (times--) {
        solve();
    }
    return 0;
}