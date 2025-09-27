#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <vector>

const int inf = 1e9;
const int N = 2e5;
int mapp[N + 2];
int main() {
    int t;
    std::cin >> t;
    while (t--) {
        int n;
        std::cin >> n;
        int mi = inf, mx = 0;
        for (int i = 1; i <= n; i++) {
            scanf("%d", &mapp[i]);
            mi = std::min(mi, mapp[i]);
            mx = std::max(mx, mapp[i]);
        }
        std::vector<int> q;
        while (mi != mx) {
            // std::cout << mi << " " << mx << std::endl;
            int a = (mx + 1) / 2 - (mi + 1) / 2;
            int b = mx / 2 - mi / 2;
            if (a > b) {
                q.push_back(0);
                mi /= 2;
                mx /= 2;
            } else {
                q.push_back(1);
                mi = (mi + 1) / 2;
                mx = (mx + 1) / 2;
            }
        }
        printf("%lu\n", q.size());
        if ((int)q.size() <= n) {
            for (int i = 0; i < (int)q.size(); i++) {
                printf("%d ", q[i]);
            }
            puts("");
        }
    }
    return 0;
}