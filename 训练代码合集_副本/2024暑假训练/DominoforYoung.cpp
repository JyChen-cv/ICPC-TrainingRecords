#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>

const int N = 3e5;
int mapp[N + 2];

int main() {
    int n;
    std::cin >> n;
    for (int i = 1; i <= n; i++) {
        std::cin >> mapp[i];
    }
    int ans[2] = {0, 0}, yu = 0;
    for (int i = 1; i <= n; i++) {
        if (mapp[i] % 2) {
            ans[yu] += (mapp[i] + 1) / 2;
            ans[yu ^ 1] += (mapp[i] - 1) / 2;
        } else
            ans[0] += mapp[i] / 2, ans[1] += mapp[i] / 2;
        yu ^= 1;
    }
    std::cout << std::min(ans[0], ans[1]) << std::endl;
    return 0;
}