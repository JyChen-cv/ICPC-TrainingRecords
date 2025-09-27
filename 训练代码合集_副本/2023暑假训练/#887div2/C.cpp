#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>

const int N = 2e5;
long long mapp[N + 2];
int n, k;

long long check(long long x) {
    for (int i = 1; i <= k; i++) {
        int tag = std::lower_bound(mapp + 1, mapp + n + 1, x) - mapp;
        if (mapp[tag] > x || tag > n) tag--;
        x -= tag;
        // std::cout << tag << std::endl;
        if (x <= 0) return -1;
    }
    return x;
}

int main() {
    int t;
    std::cin >> t;
    while (t--) {
        std::cin >> n >> k;
        for (int i = 1; i <= n; i++) {
            std::cin >> mapp[i];
        }
        // // std::cout << std::lower_bound(mapp + 1, mapp + n + 1, k) - mapp - 1 << std::endl;
        // std::sort(mapp + 1, mapp + n + 1);
        long long l = 1, r = 1e18;
        while (l < r) {
            long long mid = (l + r) >> 1;
            long long ls = check(mid);
            // std::cout << ls << std::endl;
            if (ls >= 1)
                r = mid;
            else
                l = mid + 1;
        }
        std::cout << l << std::endl;
    }
    return 0;
}