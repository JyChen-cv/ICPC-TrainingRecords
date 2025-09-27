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
        int n;
        std::cin >> n;
        int mi = 0, mx = 1e9 + 1;
        std::vector<int> mapp;
        for (int i = 1; i <= n; i++) {
            int a, b;
            std::cin >> a >> b;
            if (a == 1)
                mi = std::max(mi, b);
            else if (a == 2)
                mx = std::min(mx, b);
            else {
                mapp.push_back(b);
            }
        }
        std::sort(mapp.begin(), mapp.end());
        int ans = 0;
        for (int i = 0; i < (int)mapp.size(); i++) {
            if (mapp[i] <= mx && mapp[i] >= mi) ans--;
        }
        ans += (mx - mi) + 1;
        std::cout << ans << std::endl;
    }
    return 0;
}