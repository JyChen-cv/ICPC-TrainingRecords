#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <map>
#include <set>
#include <vector>

#define int long long
const int N = 2e3;
std::vector<int> q[N + 2];
int fa[N + 2], mapp[N + 2];

inline int find(int x) {
    if (fa[x] == x)
        return x;
    else
        return fa[x] = find(fa[x]);
}

void solve() {
    int n;
    std::cin >> n;
    for (int i = 1; i <= n; i++) {
        fa[i] = i;
    }
    for (int i = 1; i <= n; i++) std::cin >> mapp[i];
    if (n == 1) {
        std::cout << "YES" << std::endl;
        return;
    }
    std::vector<std::pair<int, int> > ans;
    for (int i = n - 1; i >= 1; i--) {
        int tag = 0;
        for (int j = 0; j < i; j++) q[j].clear();
        for (int j = 1; j <= n; j++) {
            q[mapp[j] % i].push_back(j);
        }
        for (int j = i - 1; j >= 0; j--) {
            if (tag) break;
            if (q[j].size() < 2) continue;
            for (int k = 1; k < (int)q[j].size(); k++) {
                if (find(q[j][k - 1]) != find(q[j][k])) {
                    ans.push_back({q[j][k - 1], q[j][k]});
                    fa[find(q[j][k - 1])] = find(q[j][k]);
                    tag = 1;
                    break;
                }
            }
        }
        if (!tag) {
            ans.clear();
            break;
        }
    }
    if (ans.size()) {
        std::cout << "YES" << std::endl;
        for (int i = ans.size() - 1; i >= 0; i--) {
            std::cout << ans[i].first << " " << ans[i].second << "\n";
        }
    } else
        std::cout << "NO" << std::endl;
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