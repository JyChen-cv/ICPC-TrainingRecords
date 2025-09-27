#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <vector>

const int N = 3e5;
const double eps = 1e-10;
double mapp[N + 2], sum[N + 2];
int n, tag;

bool check(double x) {
    for (int i = 1; i <= n; i++) {
        sum[i] = sum[i - 1] + mapp[i] - x;
    }
    double mn = 0;
    for (int i = 1; i < tag - 1; i++) mn = std::min(sum[i], mn);
    // std::cout << x << " " << mn << std::endl;
    for (int j = tag + 1; j <= n; j++) {
        if (sum[j] - mn > 0) return 1;
    }
    return 0;
}

void solve() {
    std::cin >> n;
    for (int i = 1; i <= n; i++) {
        scanf("%lf", mapp + i);
    }
    double sz = mapp[1] - mapp[0];
    for (int i = 2; i <= n; i++) {
        if ((mapp[i] - mapp[i - 1]) * sz < 0) tag = i;
    }
    // std::cout << tag << std::endl;
    double l = 0, r = 1e9;
    while (r - l > eps) {
        double mid = (l + r) / 2;
        if (check(mid))
            l = mid;
        else
            r = mid;
    }
    printf("%.10lf\n", l);
}

int main() {
    // std::ios::sync_with_stdio(0);
    // std::cin.tie(0);
    int t;
    std::cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}

/*
2
4
8 2 7 10
6
9 6 5 3 4 8

*/