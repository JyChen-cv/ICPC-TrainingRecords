#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <map>
#include <vector>

#define int long long
const int N = 5000;
int tag[N + 2], d[N + 2];
void solve() {
    int n;
    std::cin >> n;
    for (int i = 0; i <= n; i++) {
        tag[i] = 1;
        d[i] = 0;
    }
    std::map<int, int> q;
    for (int i = 1; i <= n; i++) {
        int a;
        std::cin >> a;
        q[a]++;
    }
    std::vector<std::pair<int, int>> res;
    for (auto i : q) {
        res.push_back(i);
    }
    int ans = 0;
    for (int i = 0; i < (int)res.size(); i++) {
        if (!tag[i]) continue;
        int dis = -1;
        std::vector<std::pair<int, int>> rem;
        for (int j = i; j < (int)res.size(); j++) {
            if (tag[j]) {
                d[j] = ++dis;
                if (dis >= res[j].second) {
                    rem.push_back(std::make_pair(res[j].second, j));
                }
            }
        }
        if (rem.size()) {
            std::sort(rem.begin(), rem.end());
            tag[rem[0].second] = 0;
            for (int j = i; j < (int)res.size(); j++) {
                if (d[j] <= rem[0].first - 1) {
                    ans++;
                    tag[j] = 0;
                }
            }
        } else
            ans++;
    }
    std::cout << ans << std::endl;
}

signed main() {
    int t;
    std::cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}