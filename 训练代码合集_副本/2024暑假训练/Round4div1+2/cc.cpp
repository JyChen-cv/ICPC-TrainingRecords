#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <map>
#include <queue>
#include <vector>

#define int long long
const int N = 2e5;
int mapp[N + 2];
void solve() {
    int n;
    std::cin >> n;
    for (int i = 1; i <= n; i++) {
        std::cin >> mapp[i];
    }
    int tag = 1;
    std::vector<int> ans;
    for (int i = 1; i <= 41; i++) {
        int mi = 1e9 + 7, mx = 0;
        for (int j = 1; j <= n; j++) {
            mi = std::min(mi, mapp[j]);
            mx = std::max(mx, mapp[j]);
        }
        if (mi == 0 && mx == 0) break;
        if ((mi + mx) % 2) {
            tag = 0;
            break;
        } else {
            int ls = (mi + mx) / 2;
            // std::cout << mi << " " << mx << std::endl;
            ans.push_back(ls);
            for (int j = 1; j <= n; j++) {
                mapp[j] = std::abs(mapp[j] - ls);
            }
        }
    }
    if (ans.size() > 40) tag = 0;
    if (!tag)
        std::cout << -1 << std::endl;
    else {
        std::cout << ans.size() << std::endl;
        for (auto i : ans) {
            std::cout << i << " ";
        }
        std::cout << std::endl;
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