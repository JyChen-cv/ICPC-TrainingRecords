#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <map>
#include <set>
#include <vector>

#define int long long
const int N = 1e6;
std::vector<int> q[N + 2], v[N + 2];
int num[N + 2];

void deal(int x, int y) {
    std::vector<std::pair<int, int>> sz(q[y].size() + 1);
    sz[0] = {1, 1};
    for (int i = 0; i < (int)q[y].size(); i++) {
        //     if (v[y][i]) continue;
        //     int fa = q[y][i] - 1;
        //     sz[i - 1] = {sz[fa].first + 1, i};
    }
    std::sort(sz.begin(), sz.end());
    int ls = lower_bound(sz.begin(), sz.end(), {(1 << x), 0}) - sz.begin();
    v[y][sz[ls].second] = 1;
    num[y] -= sz[ls].first;
}

void solve() {
    int n;
    std::cin >> n;
    int mx = 0, mnum = 0;
    for (int i = 1; i <= n; i++) {
        q[i].clear(), v[i].clear();
    }
    for (int i = 1; i <= n; i++) {
        int m;
        std::cin >> m;
        num[i] = m;
        if (m > mx) {
            mnum = i;
            mx = m;
        }
        for (int j = 1; j <= m; j++) {
            int a;
            std::cin >> a;
            q[i].push_back(a);
            v[i].push_back(0);
        }
    }
    for (int i = 22; i >= 0; i--) {
        if ((mx >> i) & 1)
            continue;
        else {
            for (int j = 1; j <= n; j++) {
                if (j == mnum) continue;
                if (num[j] >= (1 << i)) {
                    deal(i, j);
                    mx |= (1 << i);
                    break;
                }
            }
        }
    }
    std::cout << mx << std::endl;
}

signed main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);
    std::cout.tie(0);
    int tim;
    std::cin >> tim;
    while (tim--) {
        solve();
    }
    return 0;
}