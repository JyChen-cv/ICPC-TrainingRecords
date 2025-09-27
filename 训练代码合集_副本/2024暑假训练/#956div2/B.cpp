#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>

const int N = 500;
int a[N + 2][N + 2], b[N + 2][N + 2];
void solve() {
    int n, m;
    std::cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        std::string aa;
        std::cin >> aa;
        // std::cout << aa << std::endl;
        for (int j = 0; j < m; j++) {
            a[i][j + 1] = aa[j] - '0';
            // std::cout << a[i][j + 1] << " \n"[j == m - 1];
        }
    }
    for (int i = 1; i <= n; i++) {
        std::string aa;
        std::cin >> aa;
        for (int j = 0; j < m; j++) {
            b[i][j + 1] = aa[j] - '0';
        }
    }

    int tag = 1;
    for (int i = 1; i <= n; i++) {
        int sum1 = 0, sum2 = 0;
        for (int j = 1; j <= m; j++) {
            sum1 += a[i][j];
            sum2 += b[i][j];
        }
        int sum = std::abs(sum1 - sum2);
        if (sum % 3) {
            tag = 0;
            break;
        }
    }
    // std::cout << tag << std::endl;
    for (int j = 1; j <= m; j++) {
        int sum1 = 0, sum2 = 0;
        for (int i = 1; i <= n; i++) {
            sum1 += a[i][j];
            sum2 += b[i][j];
        }
        int sum = std::abs(sum1 - sum2);
        if (sum % 3) {
            // std::cout << j << " " << sum1 << " " << sum2 << std::endl;
            tag = 0;
            break;
        }
    }
    // std::cout << tag << std::endl;

    if (tag == 1)
        std::cout << "YES" << std::endl;
    else
        std::cout << "NO" << std::endl;
}

int main() {
    int t;
    std::cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}