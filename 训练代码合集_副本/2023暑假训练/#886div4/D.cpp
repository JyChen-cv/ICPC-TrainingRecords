#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <vector>

int main() {
    int t;
    std::cin >> t;
    while (t--) {
        int n, m;
        std::cin >> n >> m;
        std::vector<int> mapp(n + 1);
        for (int i = 1; i <= n; i++) std::cin >> mapp[i];
        std::sort(mapp.begin() + 1, mapp.end());
        int ls = 1, ans = 1;
        for (int i = 2; i <= n; i++) {
            if (mapp[i] - mapp[i - 1] <= m)
                ls++;
            else {
                ans = std::max(ans, ls);
                ls = 1;
            }
        }
        ans = std::max(ans, ls);
        std::cout << n - ans << std::endl;
    }
    return 0;
}