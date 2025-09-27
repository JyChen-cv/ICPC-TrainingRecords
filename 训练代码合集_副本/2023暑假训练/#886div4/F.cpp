#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <queue>
#include <vector>

const int N = 2e5;
int cnt[N + 2], num[N + 2];

int main() {
    int t;
    std::cin >> t;
    while (t--) {
        int n;
        std::cin >> n;
        for (int i = 1; i <= n; i++) cnt[i] = 0, num[i] = 0;
        for (int i = 1; i <= n; i++) {
            int a;
            std::cin >> a;
            if (a > n) continue;
            num[a]++;
        }
        for (int i = 1; i <= n; i++) {
            if (!num[i]) continue;
            for (int j = 1; j * i <= n; j++) {
                cnt[i * j] += num[i];
            }
        }
        int ans = 0;
        for (int i = 1; i <= n; i++) {
            ans = std::max(ans, cnt[i]);
        }
        std::cout << ans << std::endl;
    }
    return 0;
}