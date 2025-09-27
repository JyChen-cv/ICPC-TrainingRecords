#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <vector>

void solve() {
    int n, m;
    std::cin >> n >> m;
    std::cout << (n - 1) * m + 1 << std::endl;
}

int main() {
    int t;
    std::cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}