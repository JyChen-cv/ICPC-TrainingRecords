#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <vector>
typedef long long LL;

int main() {
    int t;
    std::cin >> t;
    while (t--) {
        int n;
        std::cin >> n;
        LL ans = 0, sum = 0;
        for (int i = 1; i <= n; i++) {
            int a;
            std::cin >> a;
            sum += a;
            if (a == 1) ans++;
        }
        if (sum < (n + ans) || n == 1)
            std::cout << "No" << std::endl;
        else
            std::cout << "Yes" << std::endl;
    }
    return 0;
}