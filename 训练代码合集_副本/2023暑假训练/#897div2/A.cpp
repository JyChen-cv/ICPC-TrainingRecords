#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <vector>

const int N = 4e4;
std::pair<int, int> mapp[N + 2], ans[N + 2];
int main() {
    int t;
    std::cin >> t;
    while (t--) {
        int n, a;
        std::cin >> n;
        for (int i = 1; i <= n; i++) {
            std::cin >> a;
            mapp[i] = std::make_pair(a, i);
        }
        std::sort(mapp + 1, mapp + n + 1);
        for (int i = 1; i <= n; i++) {
            ans[i] = std::make_pair(mapp[i].second, n + 1 - i);
        }
        std::sort(ans + 1, ans + n + 1);
        for (int i = 1; i <= n; i++) {
            std::cout << ans[i].second << " ";
        }
        std::cout << std::endl;
    }
    return 0;
}