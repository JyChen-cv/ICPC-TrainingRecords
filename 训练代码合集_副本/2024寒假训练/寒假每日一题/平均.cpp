#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <vector>

const int N = 20;
std::vector<int> mapp[N + 2];

int main() {
    int n;
    std::cin >> n;
    for (int i = 1; i <= n; i++) {
        int a, b;
        std::cin >> a >> b;
        mapp[a].push_back(b);
    }
    long long sum = 0;
    for (int i = 0; i <= 9; i++) {
        std::sort(mapp[i].begin(), mapp[i].end());
        for (int j = mapp[i].size() - 1 - (n / 10); j >= 0; j--) {
            sum += mapp[i][j];
        }
    }
    printf("%lld\n", sum);
    return 0;
}