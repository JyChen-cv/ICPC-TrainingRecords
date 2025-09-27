#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <vector>

#define int long long
signed main() {
    int t;
    std::cin >> t;
    while (t--) {
        int m, k, num1, num2;
        std::cin >> m >> k >> num1 >> num2;
        int yu2 = num2 - m / k;
        int yu1 = num1 - (m % k);
        // std::cout << yu1 << " " << yu2 << std::endl;
        if (yu1 >= 0 && yu2 >= 0) {
            std::cout << 0 << std::endl;
        } else if (yu1 >= 0 && yu2 < 0) {
            yu2 += yu1 / k;
            yu1 %= k;
            if (yu2 >= 0)
                std::cout << 0 << std::endl;
            else
                std::cout << -yu2 << std::endl;
        } else {
            yu2 -= (-yu1 / k);
            yu1 %= k;
            if (yu2 >= 0)
                std::cout << -yu1 << std::endl;
            else
                std::cout << -yu2 - yu1 << std::endl;
        }
    }
    return 0;
}