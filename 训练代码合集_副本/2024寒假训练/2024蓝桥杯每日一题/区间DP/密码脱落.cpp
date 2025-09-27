#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <vector>

const int N = 1000;
std::string mapp;
int d[N + 2][N + 2];

int main() {
    std::cin >> mapp;
    int n = mapp.size() - 1;
    memset(d, 0x3f, sizeof d);
    for (int i = 0; i <= n; i++) d[i][i] = d[i + 1][i] = 0;
    for (int len = 2; len <= n + 1; len++) {
        for (int l = 0; l + len - 1 <= n; l++) {
            int r = l + len - 1;
            d[l][r] = d[l + 1][r - 1];
            if (mapp[l] != mapp[r]) d[l][r] += 2;
            d[l][r] = std::min(d[l][r], std::min(d[l + 1][r], d[l][r - 1]) + 1);
            // std::cout << l << " " << r << " " << d[l][r] << std::endl;
        }
    }
    std::cout << d[0][n] << std::endl;
    return 0;
}