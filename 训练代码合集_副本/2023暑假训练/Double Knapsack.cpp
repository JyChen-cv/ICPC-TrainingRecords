#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <vector>

const int N = 1e6;
typedef long long ll;
ll sa[N + 2], sb[N + 2];
std::pair<int, int> b[N + 2];

void print(int x1, int x2, int y1, int y2) {
    std::cout << x2 - x1 + 1 << std::endl;
    for (int i = x1; i <= x2; i++) {
        printf("%d ", i);
    }
    std::cout << std::endl
              << y2 - y1 + 1 << std::endl;
    for (int i = y1; i <= y2; i++) {
        printf("%d ", i);
    }
    std::cout << std::endl;
}
int main() {
    int n;
    std::cin >> n;
    for (int i = 1; i <= n; i++) {
        scanf("%lld", &sa[i]);
        sa[i] += sa[i - 1];
    }
    for (int i = 1; i <= n; i++) {
        scanf("%lld", &sb[i]);
        sb[i] += sb[i - 1];
    }
    int l = 0;
    for (int i = 0; i <= n; i++) {
        while (sb[l] < sa[i] && l <= n) l++;
        ll ll = sb[l] - sa[i];
        if (ll < 0) continue;
        // std::cout << sa[i] << " " << sb[l] << std::endl;
        if (b[ll].first && b[ll].second) {
            print(b[ll].first + 1, i, b[ll].second + 1, l);
            return 0;
        }
        b[ll] = std::make_pair(i, l);
    }

    return 0;
}