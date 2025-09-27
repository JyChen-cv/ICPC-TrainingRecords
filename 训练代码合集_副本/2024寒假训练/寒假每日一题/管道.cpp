#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <vector>

#define int long long
#define x first
#define y second
const int N = 1e5;
int n, len;
std::pair<int, int> a[N + 2];
// 转换成给定时刻
// 我有好多区间，把这些区间全部合并，看看是否能够覆盖掉全集

bool check(int x) {
    std::vector<std::pair<int, int>> ls;
    for (int i = 1; i <= n; i++) {
        if (x < a[i].y) {
            continue;
        }
        ls.push_back(std::make_pair(a[i].x - (x - a[i].y), a[i].x + (x - a[i].y)));
    }
    std::sort(ls.begin(), ls.end());
    int l = 0;
    for (int i = 0; i < (int)ls.size(); i++) {
        if (ls[i].x > l + 1)
            return 0;
        else
            l = std::max(l, ls[i].y);
    }
    if (l >= len)
        return 1;
    else
        return 0;
}

signed main() {
    std::cin >> n >> len;
    for (int i = 1; i <= n; i++) {
        std::cin >> a[i].x >> a[i].y;
    }

    int l = 0, r = 2e9;
    while (l < r) {
        // std::cout << l << " " << r << std::endl;
        int mid = (l + r) >> 1;
        if (check(mid)) {
            r = mid;
        } else
            l = mid + 1;
    }
    printf("%d\n", l);
    return 0;
}