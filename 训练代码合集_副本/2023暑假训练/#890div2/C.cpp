#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <vector>

std::vector<long long> mapp;
int n;
long long m;
bool check(long long x) {
    for (int i = 1; i <= n; i++) {
        bool tag = 1;
        long long res = m;
        long long tar = x;
        for (int j = i; j <= n; j++) {
            if (tar > mapp[j] && j == n) {
                tag = 0;
                break;
            }
            if (tar > mapp[j]) {
                res -= (tar - mapp[j]);
                if (res < 0) {
                    tag = 0;
                    break;
                }
            } else
                break;
            tar--;
        }
        if (tag)
            return 1;
    }
    return 0;
}

int main() {
    int t;
    std::cin >> t;
    while (t--) {
        mapp.clear();
        std::cin >> n >> m;
        for (int i = 0; i <= n; i++) mapp.push_back(0);
        for (int i = 1; i <= n; i++) {
            std::cin >> mapp[i];
        }

        long long l = 0, r = 1e9;
        while (l < r) {
            //            std::cout << l << " " << r << std::endl;
            long long mid = (l + r + 1) >> 1;
            if (check(mid)) {
                l = mid;
            } else
                r = mid - 1;
        }
        std::cout << l << std::endl;
    }
    return 0;
}
