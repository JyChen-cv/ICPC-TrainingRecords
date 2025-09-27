#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>

int gcd(int x, int y) {
    return y ? gcd(y, x % y) : x;
}
void solve() {
    int n;
    std::cin >> n;
    int fz = 1, fm = 1, zeros = 0, tag = 1;
    for (int i = 1; i <= n; i++) {
        int a;
        std::cin >> a;
        if (a == 0) zeros++;
        if (a == 1) {
            fz++;
            fm++;
        } else if (fm > 1) {
            fm--;
        } else {
            if (zeros) {
                zeros--;
                fz++, fm++;
            } else
                tag = 0;
        }
    }
    if (tag) {
        int ls = gcd(fz, fm);
        fz /= ls;
        fm /= ls;
        std::cout << fz << " " << fm << std::endl;
    } else
        std::cout << -1 << std::endl;
}
int main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);
    std::cout.tie(0);
    int t;
    std::cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}