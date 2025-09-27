#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <vector>

const int N = 50;
const double der = 1e-9;
double mapp[N + 2];
__int128 C[51][51];
#define int long long
bool equ(double x, double y) {
    return std::fabs(x - y) <= der;
}
void out(__int128 x) {
    if (!x) return;
    out(x / 10);
    printf("%lld", (int)(x % 10));
}
signed main() {
    int n, low, mos;
    std::cin >> n >> low >> mos;
    C[0][0] = C[1][0] = C[1][1] = 1;
    for (int i = 0; i <= 50; ++i) {
        C[i][0] = 1;
        for (int j = 1; j <= i; ++j) C[i][j] = C[i - 1][j - 1] + C[i - 1][j];
    }
    for (int i = 1; i <= n; i++) {
        std::cin >> mapp[i];
    }
    std::sort(mapp + 1, mapp + n + 1);
    long long cnt1 = 0, cnt2 = 0;
    double l = mapp[n - low + 1];
    for (int i = 1; i <= n; i++) {
        if (equ(mapp[i], l)) cnt1++;
    }
    double ans = 0;
    for (int i = n - low + 1; i <= n; i++) {
        if (equ(mapp[i], l)) cnt2++;
        ans += mapp[i];
    }
    __int128 cnt = C[cnt1][cnt2];
    for (int i = 1; i <= (mos - low); i++) {
        int tag = 0;
        for (int j = n - 1; j >= n - low - i + 1; j--) {
            if (!equ(mapp[j], mapp[j + 1])) tag = 1;
        }
        if (!tag) {
            cnt += C[cnt1][cnt2 + i];
        }
    }
    printf("%.8lf\n", ans / low);
    out(cnt);
    puts("");
    return 0;
}