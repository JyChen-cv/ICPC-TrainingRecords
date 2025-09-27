#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <queue>
#include <vector>

#define int long long

const int N = 2e5;
int mapp[N + 2], v[N + 2];
int n, k, m, c, d;

bool check(int x) {
    memset(v, 0, sizeof(v));
    int num = 0;
    std::vector<int> q;
    for (int i = 1; i <= n; i++) {
        if (mapp[i] >= x) {
            num++;
            continue;
        } else if (mapp[i] + (c + d * (m - 1)) < x)
            continue;
        int st = i - m + 1, res = (x - mapp[i]), ed;
        if (res <= c)
            ed = i;
        else {
            res = (res - c) / d + ((res - c) % d != 0);
            ed = i - res;
        }
        st = std::max(st, 1LL);
        ed = std::min(ed, n - m + 1);
        // std::cout << i << ": " << st << " " << ed << std::endl;
        if (st <= ed) v[st]++, v[ed + 1]--;
    }
    int mx = 0, sum = 0;
    // std::cout << num << std::endl;
    for (int i = 0; i <= n; i++) {
        // std::cout << v[i] << " \n"[i == n];
        sum += v[i];
        mx = std::max(mx, sum);
    }
    return mx + num >= k;
}

signed main() {
    std::cin >> n >> k >> m >> c >> d;
    for (int i = 1; i <= n; i++) {
        std::cin >> mapp[i];
    }

    int l = 0, r = 1e16;
    // std::cout << check(5) << std::endl;
    while (l < r) {
        int mid = (l + r + 1) >> 1;
        if (check(mid))  // >=k个
            l = mid;
        else
            r = mid - 1;
    }
    std::cout << l << std::endl;
    return 0;
}