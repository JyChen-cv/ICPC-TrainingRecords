#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>

const int N = 1e5;
int mapp[N + 2];

int deal(int l, int r) {
    if (mapp[l] < 0) mapp[l] *= -1;
    int res = mapp[l];
    for (int i = l + 1; i <= r; i++) {
        if (mapp[i] < 0) mapp[i] *= -1;
        if (mapp[i] > mapp[i - 1]) res += mapp[i] - mapp[i - 1];
    }
    return res;
}

int main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);
    std::cout.tie(0);

    int n;
    std::cin >> n;
    for (int i = 1; i <= n; i++) {
        std::cin >> mapp[i];
    }
    for (int i = 1; i <= n; i++) {
        int a;
        std::cin >> a;
        mapp[i] -= a;
        // std::cout << mapp[i] << " ";
    }
    // std::cout << std::endl;
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        int j = i;
        while (j + 1 <= n && mapp[j] * mapp[j + 1] >= 0) j++;
        ans += deal(i, j);
        // std::cout << i << " " << j << " " << deal(i, j) << std::endl;
        i = j;
    }
    std::cout << ans << std::endl;
    return 0;
}