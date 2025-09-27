#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>

const int N = 5000 * 2;
int a[N + 2], b[N + 2], n, k;

int deal(int x) {
    return x;
    // return x % n;
}

void solve() {
    // int n, k;
    std::cin >> n >> k;
    for (int i = 1; i <= k; i++) {
        std::cin >> a[i];
        a[i + k] = a[i];
    }
    for (int i = 1; i <= k; i++) {
        std::cin >> b[i];
        b[i + k] = b[i];
    }
    std::sort(a + 1, a + k + 1);
    std::sort(a + k + 2, a + k * 2 + 1);
    std::sort(b + 1, b + k + 1);
    std::sort(b + k + 2, b + k * 2 + 1);
    // std::sort(b + 1, b + k * 2 + 1);
    int ans = 1e9;
    for (int i = 0; i < k; i++) {
        int ls;
        int mmax = 0, mmin = 0;
        // std::cout << std::endl
        //           << i << "???" << std::endl;
        for (int j = 1; j <= k - i; j++) {
            a[j] += n;
        }
        // a[i] += n;
        for (int j = 1; j <= k; j++) {
            // std::cout << a[j] << " " << b[j + i] << std::endl;
            mmax = std::max(mmax, deal(a[j] - b[j + i]));
            mmin = std::min(mmin, deal(a[j] - b[j + i]));
        }
        for (int j = 1; j <= k - i; j++) {
            a[j] -= n;
        }
        ls = std::min(mmax, -mmin) * 2 + std::max(mmax, -mmin);
        // std::cout << mmax << " " << mmin << " " << ls << std::endl;
        ans = std::min(ans, ls);
    }
    std::swap(a, b);
    for (int i = 0; i < k; i++) {
        int ls;
        int mmax = 0, mmin = 0;
        // std::cout << std::endl
        //           << i << "???" << std::endl;
        for (int j = 1; j <= k - i; j++) {
            a[j] += n;
        }
        // a[i] += n;
        for (int j = 1; j <= k; j++) {
            // std::cout << a[j] << " " << b[j + i] << std::endl;
            mmax = std::max(mmax, deal(a[j] - b[j + i]));
            mmin = std::min(mmin, deal(a[j] - b[j + i]));
        }
        for (int j = 1; j <= k - i; j++) {
            a[j] -= n;
        }
        ls = std::min(mmax, -mmin) * 2 + std::max(mmax, -mmin);
        // std::cout << mmax << " " << mmin << " " << ls << std::endl;
        ans = std::min(ans, ls);
    }

    std::cout << ans << std::endl;
}

int main() {
    int t;
    std::cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}

/*
3
14 3
1 2 3
4 13 12
4 2
0 3
1 2
14 5
0 12 13 8 9
9 2 6 13 5

1
14 3
1 2 3
4 13 12

1
20 4
0 19 11 12
1 3 13 14

1
20 4
1 3 13 14
0 19 11 12


1
6 5
0 1 2 3 4
5 6 0 1 2

1
100 6
0 1 2 48 49 50
4 5 46 47 55 96

*/