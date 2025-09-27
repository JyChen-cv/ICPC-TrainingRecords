#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>

const int N = 1e5;
typedef long long LL;
LL mapp[N + 2], s[N + 2];
int main() {
    int t;
    std::cin >> t;
    while (t--) {
        int n, m, d;
        std::cin >> n >> m >> d;
        for (int i = 1; i <= m; i++) {
            std::cin >> mapp[i];
            s[i] = 0;
        }
        mapp[0] = 1;
        mapp[++m] = n;
        s[m] = 0;
        LL ans = 0;
        for (int i = 1; i <= m; i++) {
            LL dis = mapp[i] - mapp[i - 1] - 1;
            s[i] = dis / d;
            std::cout << s[i] << " ";
            // if (i == 1 && mapp[i] != 1) s[i]++;
            ans += s[i];
        }
        std::cout << std::endl;
        ans += m - 1;
        if (mapp[1] != 1)
            ans++;
        else {
            std::cout << ans << " " << 1 << std::endl;
            continue;
        }
        LL mm = 1e9;
        int tag = 0;
        for (int i = 1; i < m; i++) {
            LL dis = mapp[i + 1] - mapp[i - 1] - 1;
            LL l = dis / d;
            l -= s[i + 1] - s[i];
            if (l < mm) {
                mm = l;
                tag = i;
            }
        }
        std::cout << ans + mm - 1 << " " << tag << std::endl;
    }
    return 0;
}