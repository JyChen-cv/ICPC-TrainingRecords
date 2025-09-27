#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <vector>

const int N = 100;
int tag[N + 2];
int main() {
    int t;
    std::cin >> t;
    while (t--) {
        memset(tag, 0, sizeof(tag));
        int n, m;
        std::cin >> n >> m;
        for (int i = 1; i <= n; i++) {
            int a;
            std::cin >> a;
            if (m + 1 - a < a) a = m + 1 - a;
            if (!tag[a])
                tag[a] = 1;
            else
                tag[m + 1 - a] = 1;
        }
        for (int i = 1; i <= m; i++) {
            if (tag[i])
                std::cout << "A";
            else
                std::cout << "B";
        }
        std::cout << std::endl;
    }
    return 0;
}