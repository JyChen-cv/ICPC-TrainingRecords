#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <map>

#define int long long
void solve() {
    int n, m;
    std::cin >> n >> m;
    std::map<int, int> q;
    for (int i = 1; i <= n; i++) {
        int a, b;
        std::cin >> a >> b;
        q[a] += b;
    }
    int tag = 1, sum = 0;
    for (auto i : q) {
        sum += i.second;
        if (i.first * m < sum) tag = 0;
    }
    if (tag)
        std::cout << "Yes" << std::endl;
    else
        std::cout << "No" << std::endl;
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