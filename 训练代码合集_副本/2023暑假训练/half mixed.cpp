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
        long long n, m;
        std::cin >> n >> m;
        if ((n * (n + 1) / 2 * (m + 1) * m / 2) % 2) {
            std::cout << "No" << std::endl;
            continue;
        }

        long long tag = 0;
        if ((m * (m + 1) / 2) % 2) {
            tag = n * (n + 1) / 4;
            std::vector<int> q;
            while (tag) {
                long long l = 1, r = n;
                while (l < r) {
                    long long mid = (l + r + 1) >> 1;
                    if (mid * (mid + 1) / 2 + (n - mid) <= tag)
                        l = mid;
                    else
                        r = mid - 1;
                }
                n -= r;
                tag -= (r * (r + 1) / 2);
                q.push_back(r);
                if (n == 0 && tag) {
                    printf("No\n");
                    break;
                }
            }
            if (tag) continue;
            printf("Yes\n");
            for (int i = 0; i < (int)q.size(); i++) {
                for (int j = 1; j <= q[i]; j++) {
                    for (int l = 1; l <= m; l++) {
                        printf("%d ", i % 2);
                    }
                    puts("");
                }
            }
        } else {
            tag = m * (m + 1) / 4;
            std::vector<int> q;
            while (tag) {
                long long l = 1, r = m;
                while (l < r) {
                    long long mid = (l + r + 1) >> 1;
                    if (mid * (mid + 1) / 2 + (m - mid) <= tag)
                        l = mid;
                    else
                        r = mid - 1;
                }
                m -= r;
                tag -= (r * (r + 1) / 2);
                q.push_back(r);
                if (m == 0 && tag) {
                    printf("No\n");
                    break;
                }
            }
            if (tag) continue;
            printf("Yes\n");
            for (int i = 1; i <= n; i++) {
                for (int j = 0; j < (int)q.size(); j++) {
                    for (int k = 1; k <= q[j]; k++) {
                        printf("%d ", j % 2);
                    }
                }
                puts("");
            }
        }
    }
    return 0;
}