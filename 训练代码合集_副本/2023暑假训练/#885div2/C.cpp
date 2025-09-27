// 找规律题目。。。楽
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>

const int N = 2e5;
int a[N + 2], b[N + 2], c[N + 2];

inline int gcd(int x, int y) {
    return y ? gcd(y, x % y) : x;
}

int deal(int x, int y) {
    // 这里思路很巧妙，利用辗转相除是其一，其二是利用三个一循环的性质，避免了大规模的v计算（那样算会稍微麻烦一点）。。。
    int v = 0;
    while (x) {
        if (x >= 2 * y && y)
            x %= (2 * y);
        else if (y >= 2 * x)
            y %= (2 * x);
        int z = std::abs(x - y);
        x = y;
        y = z;
        v++;
    }
    return v + 2;
}

int main() {
    int t;
    std::cin >> t;
    while (t--) {
        int n;
        std::cin >> n;
        for (int i = 1; i <= n; i++) {
            std::cin >> a[i];
        }
        for (int i = 1; i <= n; i++) {
            std::cin >> b[i];
        }

        for (int i = 1; i <= n; i++) {
            if (a[i] == 0) {
                if (b[i] == 0)
                    c[i] = -1;
                else
                    c[i] = 2;
            } else if (b[i] == 0) {
                c[i] = 0;
            } else {
                int ls = gcd(a[i], b[i]);
                c[i] = deal(a[i] / ls, b[i] / ls) % 3;
                // std::cout << i << " " << c[i] << std::endl;
            }
        }
        int tag = 0, ls = -1;
        for (int i = 1; i <= n; i++) {
            if (c[i] == -1)
                continue;
            else if (c[i] != ls && ls != -1) {
                tag = 1;
                break;
            }
            ls = c[i];
        }
        if (tag == 0)
            std::cout << "YES" << std::endl;
        else
            std::cout << "NO" << std::endl;
    }
    return 0;
}

// 1 2 3 4 5 6 7
// 7 6 5 4 3 2 1
// 6 4 2 0 2 4 6
// 1 2 3 4 1 2 5
// 5 2 1 4 1 2 1
// 4 0 2 0 0 0 4
// 1 2 1 4 1 2 3
// 3 2 1 4 1 2 1
// 2 0 0 0 0 0 2
// 1 2 1 4 1 2 1
// 1 2 1 4 1 2 1
// 0 0 0 0 0 0 0
