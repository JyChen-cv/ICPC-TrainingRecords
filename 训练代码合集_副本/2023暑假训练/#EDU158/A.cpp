#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>

const int N = 10000;
int mapp[N + 2];

int main() {
    int t;
    std::cin >> t;
    while (t--) {
        int n, x;
        std::cin >> n >> x;
        int m = 0;
        for (int i = 1; i <= n; i++) {
            std::cin >> mapp[i];
            m = std::max(m, mapp[i] - mapp[i - 1]);
        }
        m = std::max(m, 2 * x - 2 * mapp[n]);
        std::cout << m << std::endl;
    }
    return 0;
}