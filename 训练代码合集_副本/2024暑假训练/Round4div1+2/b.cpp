#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <queue>
#include <vector>

#define int long long
const int N = 1e5;
int mapp[N + 2], ans[N + 2];
void solve() {
    int n;
    std::cin >> n;
    for (int i = 1; i < n; i++) {
        std::cin >> mapp[i];
    }
    ans[1] = mapp[1], ans[n] = mapp[n - 1];
    for (int i = 2; i < n; i++) {
        ans[i] = mapp[i - 1] | mapp[i];
    }
    int tag = 1;
    for (int i = 1; i < n; i++) {
        if (mapp[i] != (ans[i] & ans[i + 1])) tag = 0;
    }
    if (!tag)
        std::cout << -1 << std::endl;
    else
        for (int i = 1; i <= n; i++) {
            std::cout << ans[i] << " \n"[i == n];
        }
}

signed main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0), std::cout.tie(0);
    int times = 1;
    std::cin >> times;
    while (times--) {
        solve();
    }
    return 0;
}