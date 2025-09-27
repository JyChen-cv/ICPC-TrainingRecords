#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>

int main() {
    int t;
    std::cin >> t;
    while (t--) {
        std::string a, b;
        std::cin >> a >> b;
        int ans = 0, tag = 1;
        if (a[0] != b[0] || a[(int)a.size() - 1] != b[(int)b.size() - 1]) tag = 0;
        for (int i = 1; i < (int)a.size() - 1; i++) {
            if (!tag) break;
            if (a[i] != b[i]) {
                if (a[i - 1] == b[i - 1] && a[i + 1] == b[i + 1] && b[i - 1] == b[i + 1] && b[i - 1] != b[i]) {
                    ans++;
                } else
                    tag = 0;
            }
        }
        if (!tag)
            std::cout << -1 << std::endl;
        else
            std::cout << ans << std::endl;
    }
    return 0;
}