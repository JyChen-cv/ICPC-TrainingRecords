#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <vector>

const int N = 2e5;
int a[N + 2], b[N + 2];
void solve() {
    int n;
    std::cin >> n;
    for (int i = 1; i <= n; i++) {
        std::cin >> a[i];
    }
    for (int i = 1; i <= n; i++) {
        std::cin >> b[i];
    }
    int sum1 = 0, sum2 = 0;
    int hao = 0, huai = 0;
    for (int i = 1; i <= n; i++) {
        if (a[i] >= 0 && b[i] >= 0) {
            if (a[i] == b[i]) {        // 11 or 00
                if (a[i] == 1) hao++;  // 11
            } else {                   // 10 or 01
                if (a[i] == 1)
                    sum1++;
                else
                    sum2++;
            }
        } else if (a[i] == -1 && b[i] == -1) {  // -1-1
            huai++;
        } else {  //
            if (a[i] >= 0)
                sum1 += a[i];
            else
                sum2 += b[i];
        }
    }
    // std::cout << hao << " " << huai << " " << sum1 << " " << sum2 << std::endl;
    int total = hao + huai;
    if (std::abs(sum1 - sum2) <= total) {
        int all = sum1 + sum2 + hao - huai;
        if (all < 0) {
            std::cout << (all - 1) / 2 << std::endl;
        } else
            std::cout << (all / 2) << std::endl;
    } else {
        int m = std::min(sum1, sum2);
        std::cout << (m + hao) << std::endl;
    }
}

int main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);
    std::cout.tie(0);

    int t;
    std::cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}

/*
1
6
0 -1 -1 0 -1 1
-1 -1 0 0 -1 1
*/