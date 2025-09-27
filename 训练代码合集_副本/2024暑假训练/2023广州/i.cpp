#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <map>
#include <set>

#define x first
#define y second
const int N = 1e6;
std::pair<int, int> q[N + 2];

void solve() {
    int n, m;
    std::cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            int a;
            std::cin >> a;
            q[a] = std::make_pair(i, j);
        }
    }
    std::set<std::pair<int, int> > d;
    d.insert({0, 1}), d.insert({n + 1, m});
    int ans = 0;
    for (int i = 0; i < n * m; i++) {
        d.insert(q[i]);
        auto ls = d.find(q[i]);
        std::pair<int, int> x1, x2;
        ls--;
        x1 = *ls;
        ls++, ls++;
        x2 = *ls;
        if (q[i].x <= x2.x && q[i].x >= x1.x && q[i].y <= x2.y && q[i].y >= x1.y) {
            ans = i;
        } else {
            break;
        }
    }
    std::cout << ans + 1 << std::endl;
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