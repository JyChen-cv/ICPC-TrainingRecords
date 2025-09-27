#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <map>
#include <set>
#include <vector>

#define int long long
const int N = 20;
int mapp[N + 2][N + 2];
void solve() {
    int n, m;
    std::cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            std::cin >> mapp[i][j];
        }
    }
    if (n == 1 && m == 1)
        std::cout << -1 << std::endl;
    else {
        if (n != 1) {
            for (int i = 1; i <= n; i++) {
                for (int j = 0; j < m; j++) {
                    std::cout << mapp[i % n][j] << " ";
                }
                std::cout << std::endl;
            }
        } else {
            for (int i = 0; i < n; i++) {
                for (int j = 1; j <= m; j++) {
                    std::cout << mapp[i][j % m] << " ";
                }
                std::cout << std::endl;
            }
        }
    }
}

signed main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);
    std::cout.tie(0);
    int tim;
    std::cin >> tim;
    while (tim--) {
        solve();
    }
    return 0;
}