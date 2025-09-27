#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <queue>

const int N = 250, M = 2e5;
int mapp[N + 2], f[M + 2];

int main() {
    int n, all = 0;
    std::cin >> n;
    for (int i = 1; i <= n; i++) {
        std::cin >> mapp[i];
        mapp[i + n] = mapp[i];
        all += mapp[i];
    }
    f[0] = 1;
    for (int i = 1; i <= n * 2; i++) {
        for (int j = all * 2; j >= mapp[i]; j--) {
            f[j] |= f[j - mapp[i]];
        }
    }
    int cnt = 0;
    for (int i = all + 1; i <= all * 2; i++) {
        if (f[i]) cnt++;
    }
    std::cout << cnt << std::endl;
    return 0;
}