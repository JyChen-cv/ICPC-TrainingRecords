#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>

#define int long long
signed main() {
    int n;
    std::cin >> n;
    for (int i = 1; i <= n; i++) {
        std::pair<int, int> a[5];
        for (int j = 0; j <= 3; j++) {
            std::cin >> a[j].first >> a[j].second;
        }
        std::sort(a, a + 4);
        std::cout << (a[1].second - a[0].second) * (a[3].second - a[2].second) << std::endl;
    }
    return 0;
}