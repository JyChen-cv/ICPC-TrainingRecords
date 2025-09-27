#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <vector>

const int N = 2e5;
int mapp[N + 2];

inline int gcd(int x, int y) {
    return y ? gcd(y, x % y) : x;
}

int main() {
    int t;
    std::cin >> t;
    while (t--) {
        int n, ans = 0;
        std::cin >> n;
        for (int i = 1; i <= n; i++) {
            std::cin >> mapp[i];
        }
        for (int i = 1; i <= n; i++) {
            if (n % i) continue;
            int len = n / i, res = 0;
            for (int j = 1; j <= len; j++) {
                std::vector<int> ca;
                for (int k = 1; k <= i; k++) {
                    int l = (k - 1) * len + j;
                    ca.push_back(mapp[l]);
                }
                // std::cout << ca.size() << std::endl;
                for (int k = 1; k <= (int)ca.size() - 1; k++) {
                    int ls = std::abs(ca[k] - ca[k - 1]);
                    res = gcd(res, ls);
                }
                // std::cout << i << " " << res << std::endl;
            }
            if (res != 1) ans++;
        }
        std::cout << ans << std::endl;
    }
    return 0;
}