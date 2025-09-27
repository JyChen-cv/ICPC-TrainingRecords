#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>

const int N = 2e5;
int mapp[N + 2];
int main() {
    int t;
    std::cin >> t;
    while (t--) {
        int n;
        std::cin >> n;
        long long sum = -1;
        for (int i = 1; i <= n; i++) {
            scanf("%d", &mapp[i]);
            if (mapp[i] > mapp[i - 1]) sum += mapp[i] - mapp[i - 1];
        }
        std::cout << sum << std::endl;
    }
    return 0;
}