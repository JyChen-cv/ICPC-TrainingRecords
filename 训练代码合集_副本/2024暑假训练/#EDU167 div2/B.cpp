#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <vector>

const int N = 100;
int v[N + 2];
void solve() {
    std::string a, b;
    std::cin >> a >> b;
    memset(v, 0, sizeof v);
    int ans = 500;
    for (int i = 0; i < (int)b.size(); i++) {
        int tail = i - 1;
        for (int j = 0; j < (int)a.size(); j++) {
            if (tail + 1 >= (int)b.size()) break;
            if (b[tail + 1] == a[j]) tail++;
        }
        ans = std::min(ans, (int)b.size() - tail + i - 1);
    }
    std::cout << ans + (int)a.size() << std::endl;
}

int main() {
    int t;
    std::cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}