#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <vector>

int main() {
    int t;
    std::cin >> t;
    while (t--) {
        int n, ans = -10000000, tag = 0;
        std::cin >> n;
        for (int i = 1; i <= n; i++) {
            int a, b;
            std::cin >> a >> b;
            if (a > 10)
                continue;
            else if (b > ans) {
                ans = b;
                tag = i;
            }
        }
        std::cout << tag << std::endl;
    }
    return 0;
}