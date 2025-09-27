#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <vector>

int n, l;
const int N = 1e5;
double mapp[N + 2], m[N + 2], s[N + 2];

bool check(double x) {
    for (int i = 1; i <= n; i++) {
        m[i] = mapp[i] - x;
        s[i] = s[i - 1] + m[i];
    }
    double mi = 1e10, ans = -1e10;
    for (int j = l; j <= n; j++) {
        mi = std::min(mi, s[j - l]);
        ans = std::max(ans, s[j] - mi);
    }
    if (ans >= 0)
        return 1;
    else
        return 0;
}

int main() {
    std::cin >> n >> l;
    for (int i = 1; i <= n; i++) {
        std::cin >> mapp[i];
    }

    double esp = 1e-6;
    double l = -1e6, r = 1e6;
    while (r - l > esp) {
        double mid = (l + r) / 2;
        if (check(mid))
            l = mid;
        else
            r = mid;
    }
    std::cout << int(r * 1000) << std::endl;  // l不对。。。不知道why，按理说只是精度问题呀
    return 0;
}