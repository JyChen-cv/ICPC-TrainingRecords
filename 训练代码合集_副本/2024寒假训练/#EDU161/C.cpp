#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>

typedef long long ll;
const int N = 2e5;
ll mapp[N + 2], l[N + 2], r[N + 2];

int main() {
    int t;
    std::cin >> t;
    while (t--) {
        int n;
        std::cin >> n;
        for (int i = 1; i <= n; i++) {
            std::cin >> mapp[i];
        }
        for (int i = 1; i <= n; i++) {
            int ll = mapp[i] - mapp[i - 1];
            int rl = mapp[i + 1] - mapp[i];
            if (ll < rl && i != 1 || i == n)
                l[i] = 1, r[i] = rl;
            else
                r[i] = 1, l[i] = ll;
            l[i] += l[i - 1];
            r[i] += r[i - 1];
        }

        int m;
        std::cin >> m;
        for (int i = 1; i <= m; i++) {
            int a, b;
            std::cin >> a >> b;
            // 由于涉及到端点和区间的转换，所以想清楚+-1的东西
            std::cout << (a < b ? r[b - 1] - r[a - 1] : l[a] - l[b]) << std::endl;
        }
    }
    return 0;
}