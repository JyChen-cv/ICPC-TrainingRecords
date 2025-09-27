#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iostream>

void solve() {
    int n;
    std::cin >> n;
    std::string a, b;
    std::cin >> a >> b;
    int ans = 0;
    for (int i = 1; i < n - 1; i++) {
        if (a[i - 1] == a[i + 1] && a[i - 1] == 'x' && b[i] == '.' && b[i - 1] == b[i + 1] && b[i - 1] == '.' && a[i] == '.') ans++;
        if (b[i - 1] == b[i + 1] && b[i - 1] == 'x' && a[i] == '.' && a[i - 1] == a[i + 1] && a[i - 1] == '.' && b[i] == '.') ans++;
    }
    std::cout << ans << std::endl;
}

int main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0), std::cout.tie(0);
    int times = 1;
    std::cin >> times;
    while (times--) {
        solve();
    }
    return 0;
}