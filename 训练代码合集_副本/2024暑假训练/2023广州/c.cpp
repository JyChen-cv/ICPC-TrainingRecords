#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>

#define int long long
const int N = 1e6;
std::pair<int, int> mapp[N + 2];
void solve() {
    int n;
    std::cin >> n;
    for (int i = 1; i <= n; i++) {
        int a, b;
        std::cin >> a >> b;
        mapp[i] = {a, b};
    }
    std::sort(mapp + 1, mapp + n + 1);
    int ans = 0;
    for (int i = 1, j = n; i < j;) {
        int mn = std::min(mapp[i].second, mapp[j].second);
        ans += (mapp[j].first - mapp[i].first) * mn;
        mapp[i].second -= mn;
        mapp[j].second -= mn;
        if (!mapp[i].second) i++;
        if (!mapp[j].second) j--;
    }
    std::cout << ans << std::endl;
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