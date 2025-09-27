#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <vector>

const int N = 2e5;
int mapp[N + 2];
int main() {
    int t;
    std::cin >> t;
    while (t--) {
        int n;
        std::cin >> n;
        for (int i = 1; i <= n; i++) {
            scanf("%d", mapp + i);
        }
        int mi = 2e9, num = 0;
        for (int i = 1; i <= n; i++) {
            if (mapp[i] < mi) {
                mi = mapp[i];
                num = i;
            }
        }
        int tag = 0;
        for (int i = num + 1; i <= n; i++) {
            if (mapp[i] < mapp[i - 1]) tag = 1;
        }
        if (tag)
            std::cout << -1 << std::endl;
        else {
            std::cout << num - 1 << std::endl;
        }
    }
    return 0;
}