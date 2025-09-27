#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <vector>

typedef long long ll;
ll mapp[1002];
int main() {
    int t;
    std::cin >> t;
    while (t--) {
        ll a, b;
        int n;
        std::cin >> a >> b >> n;
        for (int i = 1; i <= n; i++) {
            std::cin >> mapp[i];
        }
        std::sort(mapp + 1, mapp + n + 1);
        ll ans = b;
        for (int i = 1; i <= n; i++) {
            if (mapp[i] + 1 > a)
                ans += (a - 1);
            else
                ans += mapp[i];
        }
        std::cout << ans << std::endl;
    }
    return 0;
}