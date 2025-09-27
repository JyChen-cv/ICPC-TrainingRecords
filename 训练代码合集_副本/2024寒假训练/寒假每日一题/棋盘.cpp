#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>

const int N = 2000;
int mapp[N + 2][N + 2];
int main() {
    int n, m;
    std::cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int x1, y1, x2, y2;
        std::cin >> x1 >> y1 >> x2 >> y2;
        mapp[x1][y1] += 1;
        mapp[x1][y2 + 1] -= 1;
        mapp[x2 + 1][y1] -= 1;
        mapp[x2 + 1][y2 + 1] += 1;
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            // std::cout << mapp[i][j];
            mapp[i][j] += mapp[i - 1][j] + mapp[i][j - 1] - mapp[i - 1][j - 1];
            std::cout << mapp[i][j] % 2;
        }
        std::cout << std::endl;
    }
    return 0;
}