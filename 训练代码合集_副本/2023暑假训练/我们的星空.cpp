#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <vector>

const int N = 2000;
std::pair<int, int> mapp[N + 2];
int f[N + 2];

int main() {
    int n;
    std::cin >> n;
    for (int i = 1; i <= n; i++) {
        std::cin >> mapp[i].first >> mapp[i].second;
    }
    std::sort(mapp + 1, mapp + 1 + n);
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j < i; j++) {
            if (mapp[i].first > mapp[j].second) f[i] = std::max(f[i], f[j]);
        }
        f[i] += mapp[i].second - mapp[i].first + 1;
        ans = std::max(ans, f[i]);
    }
    std::cout << ans << std::endl;
    return 0;
}