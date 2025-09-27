#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>

#define int long long
const int N = 2e5;
int mapp[N + 2];
signed main() {
    int t;
    std::cin >> t;
    while (t--) {
        int n, f, a, b, s = 0;
        std::cin >> n >> f >> a >> b;
        for (int i = 1; i <= n; i++) {
            std::cin >> mapp[i];
        }
        for (int i = 1; i <= n; i++) {
            s += std::min((mapp[i] - mapp[i - 1]) * a, b);
        }
        if (s < f)
            std::cout << "YES" << std::endl;
        else
            std::cout << "NO" << std::endl;
    }
    return 0;
}