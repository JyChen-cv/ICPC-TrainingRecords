#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <map>

void solve() {
    int n, m;
    std::cin >> n >> m;
    std::map<int, int> q;
    for (int i = 1; i <= m; i++) {
        int a;
        std::cin >> a;
        q[a] = 1;
    }
    int k;
    std::cin >> k;
    int ans = 0;
    for (int i = n; i <= k; i++) {
        if (q[i])
            continue;
        else
            ans++;
    }
    std::cout << ans << std::endl;
}

int main() {
    int t;
    std::cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}