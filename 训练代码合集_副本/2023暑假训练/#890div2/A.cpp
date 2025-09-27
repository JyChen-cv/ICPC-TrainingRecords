#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <vector>

const int N = 100;
int mapp[N + 2];

int main() {
    int t;
    std::cin >> t;
    while (t--) {
        int n;
        std::cin >> n;
        for (int i = 1; i <= n; i++) {
            std::cin >> mapp[i];
        }
        int ans = 0;
        for (int i = 2; i <= n; i++) {
            if (mapp[i] < mapp[i - 1]) ans = std::max(ans, mapp[i - 1]);
        }
        std::cout << ans << std::endl;
    }
    return 0;
}