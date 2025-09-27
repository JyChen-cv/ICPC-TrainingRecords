#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <vector>

#define int long long
const int N = 1e5;
int mapp[N + 2];

bool cmp(int x, int y) { return x > y; }
void solve() {
    int n;
    std::cin >> n;
    for (int i = 1; i <= n; i++) std::cin >> mapp[i];
    int tag = 0, ans = 0;
    std::vector<int> q;
    q.push_back(0);
    for (int i = 1; i <= n; i++) {
        if (mapp[i] >= tag) {
            tag = mapp[i];
            continue;
        }
        q.push_back(tag - mapp[i]);
    }
    std::sort(q.begin(), q.end(), cmp);
    int len = 1;
    for (int i = 0; i + 1 < (int)q.size(); i++) {
        if (q[i] == q[i + 1]) {
        } else {
            ans += (q[i] - q[i + 1]) * (len + 1);
            // len = 1;
        }
        len++;
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