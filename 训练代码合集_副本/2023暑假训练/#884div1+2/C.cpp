#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <map>
#include <queue>
#include <vector>

typedef long long LL;
const int N = 2e5;
LL mapp[N + 2], s[N + 2];

int main() {
    int t;
    std::cin >> t;
    while (t--) {
        int n, tag = 0;
        LL ans = -1000000000000;
        std::cin >> n;
        for (int i = 1; i <= n; i++) {
            std::cin >> mapp[i];
            if (mapp[i] >= 0) tag = 1;
            ans = std::max(ans, mapp[i]);
        }
        if (!tag) {
            std::cout << ans << std::endl;
        } else {
            LL ans1 = 0, ans2 = 0;
            for (int i = 1; i <= n; i++) {
                if (i % 2)
                    ans1 += std::max(mapp[i], (LL)0);
                else
                    ans2 += std::max(mapp[i], (LL)0);
            }
            std::cout << std::max(ans1, ans2) << std::endl;
        }
    }
    return 0;
}

// 不是最大子段和，对于中间的复数，也可以直接去掉