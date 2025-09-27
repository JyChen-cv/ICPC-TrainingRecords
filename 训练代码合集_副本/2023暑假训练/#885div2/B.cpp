#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>

const int N = 2e5;
int ans, m1[N + 2], m2[N + 2], point[N + 2];

inline int deal(int x) {
    return x % 2 ? (x - 1) / 2 : x / 2;
}

int main() {
    int t;
    std::cin >> t;
    while (t--) {
        int n, k;
        std::cin >> n >> k;
        ans = n;
        for (int i = 1; i <= n; i++) {
            m1[i] = m2[i] = 0;
            point[i] = 0;
        }
        for (int i = 1; i <= n; i++) {
            int a;
            std::cin >> a;
            int ls = i - point[a] - 1;
            point[a] = i;
            if (ls >= m1[a]) {
                m2[a] = m1[a];
                m1[a] = ls;
            } else if (ls > m2[a])
                m2[a] = ls;
        }
        for (int i = 1; i <= k; i++) {
            int ls = n - point[i];
            if (ls >= m1[i]) {
                m2[i] = m1[i];
                m1[i] = ls;
            } else if (ls > m2[i])
                m2[i] = ls;
            // std::cout << m1[i] << " " << m2[i] << std::endl;
            ans = std::min(ans, std::max(deal(m1[i]), m2[i]));
        }
        std::cout << ans << std::endl;
    }
    return 0;
}