#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <map>
#include <set>
#include <vector>

#define int long long

void solve() {
    int n;
    std::cin >> n;
    std::string a, b;
    std::cin >> a >> b;
    int tag = 1;
    for (int i = 0; i < n; i++) {
        if (a[i] == '1') {
            break;
        } else if (a[i] != b[i]) {
            tag = 0;
            break;
        }
    }
    std::cout << (tag ? "YES" : "NO") << std::endl;
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