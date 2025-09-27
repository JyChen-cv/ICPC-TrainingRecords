#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <vector>

#define int long long
const int N = 2e5;
int mapp[N + 2];
void solve() {
    int n, l, r;
    std::cin >> n >> l >> r;
    for (int i = 1; i <= n; i++) {
        std::cin >> mapp[i];
    }
    int sum = 0, ans = 0;
    for (int tail = 1, head = 1; head <= n; head++) {
        sum += mapp[head];
        while (sum > r && tail <= head) {
            sum -= mapp[tail];
            tail++;
        }
        if (sum >= l) {
            sum = 0;
            ans++;
            tail = head + 1;
        }
    }
    std::cout << ans << std::endl;
}

signed main() {
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