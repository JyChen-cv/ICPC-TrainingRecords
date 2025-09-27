#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>

int main() {
    int t;
    std::cin >> t;
    while (t--) {
        int n, m;
        std::cin >> n >> m;
        for (int i = 1; i < n; i++) {
            printf("%d %d\n", i, i + 1);
        }
        int ls = n - 1;
        for (int i = 1; i <= m; i++) {
            int a;
            std::cin >> a;
            if (a == ls)
                printf("-1 -1 -1\n");
            else {
                printf("%d %d %d\n", n, ls, a);
            }
            ls = a;
        }
    }
    return 0;
}