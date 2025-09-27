#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <vector>

#define int long long
const int N = 2e5;
int mapp[N + 2];
signed main() {
    int t;
    std::cin >> t;
    while (t--) {
        int n;
        scanf("%d", &n);
        for (int i = 1; i <= n; i++) {
            scanf("%d", mapp + i);
        }
        std::sort(mapp + 1, mapp + n + 1);
        int num = 1, num1 = 0, num2 = 0;
        int ans = 0;
        for (int i = 1; i <= n; i++) {
            if (mapp[i] != mapp[i - 1]) {
                if (mapp[i - 1] == 1)
                    num1 = num;
                else if (mapp[i - 1] == 2)
                    num2 = num;
                ans += num * (num - 1) / 2;
                num = 1;
            } else
                num++;
        }
        if (mapp[n] == 2) num2 = num;
        ans += num * (num - 1) / 2;
        ans += num1 * num2;
        std::cout << ans << std::endl;
    }
    return 0;
}