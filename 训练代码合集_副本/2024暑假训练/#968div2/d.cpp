#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <unordered_map>
#include <vector>

#define int long long
typedef long long ll;
typedef double db;
typedef std::pair<int, int> PII;
const int N = 2e5;
int v[N + 2], a[N + 2];
void solve() {
    int n, m, res = 0;
    std::cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        int k;
        std::cin >> k;
        for (int j = 1; j <= k; j++) {
            std::cin >> a[j];
            if (a[j] <= k) v[a[j]] = 1;
        }
        // for (int j = 0; j <= 5; j++) std::cout << v[j] << " \n"[j == 5];
        int point = -1;
        while (v[point + 1]) {
            point++;
        }
        point++;
        std::cout << point << std::endl;
        while (v[point + 1]) {
            point++;
        }
        point++;
        std::cout << point << std::endl;
        res = std::max(res, point);
        for (int j = 1; j <= k; j++) {
            if (a[j] <= k) v[a[j]] = 0;
        }
    }
    int ans = 0;
    if (m > res) {
        ans = (m - res) * (m + res + 1) / 2;
        ans += (res + 1) * res;
    } else
        ans = (m + 1) * res;
    std::cout << ans << std::endl;
}

signed main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0), std::cout.tie(0);
    int times = 1;
    std::cin >> times;
    while (times--) {
        solve();
    }
    return 0;
}