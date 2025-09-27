#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <queue>
#include <vector>

const int N = 1e5;
std::vector<int> mapp[N + 2];
int main() {
    int n, d, t;
    std::cin >> n >> d >> t;
    for (int i = 1; i <= n; i++) {
        int a, b;
        std::cin >> a >> b;
        mapp[b].push_back(a);
    }
    for (int i = 1; i <= 1e5; i++) {
        std::sort(mapp[i].begin(), mapp[i].end());
        int res = 0;
        for (int j = 0, k = 0; j < (int)mapp[i].size(); j++) {
            while (mapp[i][j] - mapp[i][k] >= d) k++;
            res = std::max(res, j - k + 1);
            // std::cout << j << " " << k << " " << i << " " << res << std::endl;
            if (res >= t) {
                std::cout << i << std::endl;
                break;
            }
        }
    }
    return 0;
}