#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <queue>
#include <vector>

int main() {
    int t;
    std::cin >> t;
    while (t--) {
        int l;
        std::cin >> l;
        std::string a, b, c;
        std::cin >> a >> b >> c;
        int n = (int)a.size() - 1;
        bool ans = false;
        for (int i = 0; i <= n; i++) {
            if (a[i] != c[i] && b[i] != c[i]) ans = true;
        }
        std::cout << (ans ? "YES" : "NO") << std::endl;
    }
    return 0;
}