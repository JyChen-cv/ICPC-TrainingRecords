#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>

int main() {
    int t;
    std::cin >> t;
    while (t--) {
        int n, m, xa, ya, xb, yb;
        scanf("%d%d%d%d%d%d", &n, &m, &xa, &ya, &xb, &yb);
        int dl = xb - xa;
        if (dl - 1 < 0) {
            printf("Draw\n");
            continue;
        }

        if (dl % 2 == 0) {
            // Bob -> Alice
            if (ya == yb) {
                printf("Bob\n");
                continue;
            }
            int lm = 0;
            if (yb > ya)
                lm = (yb - 1) * 2;
            else
                lm += (m - yb) * 2;
            if (lm > dl)
                printf("Draw\n");
            else
                printf("Bob\n");
        } else {
            // Alice -> Bob
            int lm = std::abs(yb - ya);
            if (lm <= 1) {
                printf("Alice\n");
                continue;
            }
            // std::cout << lm << std::endl;
            dl--;
            if (yb > ya) {
                ya++;
                lm = (m - ya) * 2;
            } else {
                ya--;
                lm = (ya - 1) * 2;
            }  // std::cout << lm << std::endl;
            if (lm > dl)
                printf("Draw\n");
            else
                printf("Alice\n");
        }
    }
    return 0;
}

// 没有考虑两边的步子一样多这个博弈的基本条件