#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <vector>

typedef long long LL;
const int N = 1e5;
LL mapp[N + 2], s[N + 2], f[N + 2];

int main() {
    int n;
    std::cin >> n;
    for (int i = 1; i <= n; i++) {
        std::cin >> mapp[i];
    }
    for (int i = n; i >= 1; i--) {
        f[i] = std::max(f[i - 1] + mapp[i], f[i - 1] + deal(i, mapp[i]));
        s[i] = s[i + 1] + f[i];
    }
    return 0;
}