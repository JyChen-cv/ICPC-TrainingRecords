#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>

const int N = 2e5;
int mapp[N + 2], f1[N + 2], f2[N + 2];
int main() {

    int t;
    std::cin >> t;
    while (t--) {
        int n;
        std::cin >> n;
        for (int i = 1; i <= n; i++) {
            std::cin >> mapp[i];
            f1[i]=f2[i]=0;
        }
        for (int i = 2; i <= n; i++) {
            if (mapp[i] >= mapp[i - 1])
                f1[i] = f1[i - 1] + 1;
            else
                f1[i] = f1[i - 1];
        }
        for (int i = n - 1; i >= 1; i--) {
            if (mapp[i] >= mapp[i + 1])
                f2[i] = f2[i + 1] + 1;
            else
                f2[i] = f2[i + 1];
        }
        int ans = 1e9;
        // for (int i = 1; i <= n; i++) std::cout << f1[i] << " ";
        // std::cout << std::endl;
        // for (int i = 1; i <= n; i++) std::cout << f2[i] << " ";
        // std::cout << std::endl;
        for (int i = 1; i < n; i++) {
            ans = std::min(ans, f1[i] + f2[i + 1] + 1);
        }
        ans = std::min(ans, std::min(f1[n] + 1, f2[1]));
        std::cout << ans << std::endl;
    }
    return 0;
}