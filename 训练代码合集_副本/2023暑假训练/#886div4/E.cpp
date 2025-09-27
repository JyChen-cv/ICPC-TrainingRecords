#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <queue>
#include <vector>

const int N = 2e5;
long long mapp[N + 2];

int main() {
    int t;
    std::cin >> t;
    while (t--) {
        // 仔细观察这道题目的数据量，可以发现不是让你直接算出来的
        long long m;
        int n;
        std::cin >> n >> m;
        for (int i = 1; i <= n; i++) {
            std::cin >> mapp[i];
        }
        long long l = 0, r = 1e9;
        while (l < r) {
            long long mid = (l + r) >> 1, ls = m;
            int tag = 1;
            for (int i = 1; i <= n; i++) {
                long long l = (mid * 2 + mapp[i]) * (mid * 2 + mapp[i]);
                if (ls < l) {
                    tag = 0;
                    break;
                } else
                    ls -= l;
            }
            if (!tag)
                r = mid - 1;
            else if (!ls) {
                l = mid;
                break;
            } else
                l = mid + 1;
            // std::cout << l << " " << r << std::endl;
        }
        std::cout << l << std::endl;
    }
    return 0;
}