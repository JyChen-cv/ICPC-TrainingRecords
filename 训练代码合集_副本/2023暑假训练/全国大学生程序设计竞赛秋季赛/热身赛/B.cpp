#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <vector>

int main() {
    int n;
    long long ans = 0;
    double d;
    std::cin >> n >> d;
    d = std::min(d, 360 - d);
    if (d == 0) {
        std::cout << -1 << std::endl;
    }
    double st1, st2;
    std::cin >> st1 >> st2;
    for (int i = 1; i <= n; i++) {
        double a, b;
        std::cin >> a >> b;
        double x = std::fabs(std::acos(cos(std::fabs(st1 - a)) * cos(std::fabs(st2 - b))));
        x = std::min(x, 360 - x);
        while (x - d * 2 >= 0) {
            x -= d;
            ans++;
        }
        ans += 2;
        st1 = a;
        st2 = b;
    }
    std::cout << ans << std::endl;
    return 0;
}