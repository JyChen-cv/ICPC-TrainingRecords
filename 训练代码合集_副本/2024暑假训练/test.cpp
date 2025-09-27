#include <iostream>

#define int long long
int cal(int x) {
    int res = 0;
    while (x) {
        res += x % 10;
        x /= 10;
    }
    return res;
}
signed main() {
    int n, ans = 1e9;
    std::cin >> n;
    for (int i = 1; i <= 100000000; i++) {
        ans = std::min(ans, cal(i * n));
        // std::cout << i << " " << cal(i * n) << std::endl;
    }
    std::cout << ans << std::endl;
    return 0;
}