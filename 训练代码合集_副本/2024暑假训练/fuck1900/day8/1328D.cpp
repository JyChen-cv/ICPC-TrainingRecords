#include <algorithm>
#include <cstdio>
#include <iostream>
#include <map>
#include <vector>

const int N = 2e5;
int a[N + 2];
void solve() {
    int n, rem;
    std::cin >> n;
    rem = n;
    for (int i = 1; i <= n; i++) {
        std::cin >> a[i];
        if (a[i] == a[i - 1]) rem--;
    }
    if (a[n] == a[1] && rem != 1) rem--;
    // std::cout << rem << std::endl;

    if (rem == 1) {
        std::cout << 1 << std::endl;
        for (int i = 1; i <= n; i++) {
            std::cout << 1 << " \n"[i == n];
        }
    } else if (rem % 2 == 1) {
        std::cout << 3 << std::endl;
        std::vector<std::pair<int, int>> q;
        for (int i = 1; i <= n; i++) {
            if (!q.size() || q.back().first != a[i]) {
                q.push_back({a[i], 1});
            } else
                q.back().second++;
        }
        int tag = 0;
        for (int i = 0; i < (int)q.size() - 1; i++) {
            for (int j = 1; j <= q[i].second; j++) {
                std::cout << tag + 1 << " ";
            }
            tag ^= 1;
        }
        for (int i = 1; i <= (int)q.back().second; i++) {
            std::cout << 3 << " ";
        }
        puts("");
    } else {
        std::cout << 2 << std::endl;
        std::cout << 1 << " ";
        int tag = 0;
        for (int i = 2; i <= n; i++) {
            if (a[i] != a[i - 1])
                tag ^= 1;
            std::cout << tag + 1 << " ";
        }
        puts("");
    }
}

int main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0), std::cout.tie(0);
    int times;
    std::cin >> times;
    while (times--) {
        solve();
    }
    return 0;
}