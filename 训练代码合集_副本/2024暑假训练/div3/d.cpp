#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <vector>

#define int long long
void solve() {
    int n, m, k;
    std::cin >> n >> m >> k;
    std::string c;
    std::cin >> c;
    c = 'L' + c + 'L';
    std::vector<int> an;
    for (int i = 0; i < (int)c.size(); i++) {
        if (c[i] == 'L') an.push_back(i);
    }
    int kill = 0;
    for (int i = 1; i < (int)an.size(); i++) {
        if (an[i] - an[i - 1] <= m) continue;
        for (int j = an[i - 1] + m; j <= an[i]; j++) {
            if (c[j] == 'C') kill = 1;
        }
        if (k < (an[i] - an[i - 1] - m))
            kill = 1;
        else
            k -= (an[i] - an[i - 1] - m);
    }
    std::cout << (kill == 0 ? "YES" : "NO") << std::endl;
}

signed main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);
    std::cout.tie(0);
    int t;
    std::cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}