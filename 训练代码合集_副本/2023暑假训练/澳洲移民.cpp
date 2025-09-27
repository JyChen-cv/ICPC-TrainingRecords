#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <vector>

const int N = 30000;
int mapp[N + 2], tag[N + 2];
int main() {
    int m, n;
    std::cin >> m >> n;
    for (int i = 1; i <= n; i++) {
        std::cin >> mapp[i];
    }
    std::sort(mapp + 1, mapp + n + 1);
    int ans = 0;
    int nn = n;
    for (int i = 1; i <= nn; i++) {
        for (int j = nn; j >= 1; j--) {
            if (mapp[i] + mapp[j] <= m && (!tag[i]) && (!tag[j])) {
                tag[i] = 1;
                tag[j] = 1;
                ans++;
                nn = j - 1;
                break;
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        if (!tag[i]) ans++;
    }
    std::cout << ans << std::endl;
    return 0;
}