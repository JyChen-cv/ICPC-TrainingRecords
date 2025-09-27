#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <queue>
#include <vector>

#define int long long
const int N = 5e5;
int cst[N + 2], dp[N + 2], n, m;
std::pair<int, int> q[N + 2], ls[N + 2];
int dl[N + 2];

bool cmp(std::pair<int, int> a, std::pair<int, int> b) {
    return a.second < b.second;
}

void solve() {
    std::cin >> n;
    for (int i = 1; i <= n + 1; i++) cst[i] = 0;  // 一定注意是n+1；
    for (int i = 1; i <= n; i++) {
        std::cin >> cst[i];
    }
    std::cin >> m;
    for (int i = 1; i <= m; i++) {
        int a, b;
        std::cin >> a >> b;
        q[i] = {a, b};
    }
    std::sort(q + 1, q + m + 1, cmp);

    int tag = 1, mx = 0;
    for (int i = 1; i <= n + 1; i++) {
        dl[i] = mx;
        while (q[tag].second <= i && tag <= m) {
            mx = std::max(mx, q[tag].first);
            tag++;
        }
    }

    int head = 0, tail = 0;
    ls[0] = ls[1] = {0, 0};
    for (int i = 1; i <= n + 1; i++) {
        while (ls[head].first < dl[i] && head <= tail) head++;

        dp[i] = ls[head].second + cst[i];
        while (head <= tail && ls[tail].second > dp[i]) tail--;
        ls[++tail] = {i, dp[i]};
        // std::cout << dp[i] << " \n"[i == n + 1];
    }
    std::cout << dp[n + 1] << std::endl;
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

/*
1
5
3 2 4 1000 100
3
1 5
2 4
4 4

*/