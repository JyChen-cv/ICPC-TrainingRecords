#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <vector>

void solve() {
    int a, b, c, d;
    std::cin >> a >> b >> c >> d;
    if ((a > b && c > d) || (a < b && c < d))
        std::cout << "YES" << std::endl;
    else
        std::cout << "NO" << std::endl;
}

int main() {
    int t;
    std::cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}