#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>

typedef long long ll;
const int N = 2e5;
int mapp[N + 2];
int main() {
    int n, ans = 0;
    std::cin >> n;
    for (int i = 1; i <= n; i++) {
        std::cin >> mapp[i];
    }
    std::sort(mapp + 1, mapp + n + 1);
    if (n > 0) ans = std::max(ans, mapp[n]);
    if (n > 1) ans = std::max(ans, mapp[n] + mapp[n - 1]);
    std::cout << ans << std::endl;
    return 0;
}