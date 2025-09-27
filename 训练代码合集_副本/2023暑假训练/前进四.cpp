#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <vector>

const int N = 50000;
int mapp[N + 2], n, len, m;

bool check(int x) {
    int res = 0;
    std::vector<int> q;
    q.push_back(0);
    for (int i = 1; i < n; i++) {
        if (mapp[i] - q[q.size() - 1] < x) {
            res++;
            if (res > m) return 0;
        } else
            q.push_back(mapp[i]);
        // std::cout << x << " " << res << std::endl;
    }
    return 1;
}
int main() {
    std::cin >> len >> n >> m;
    for (int i = 1; i <= n; i++) {
        std::cin >> mapp[i];
    }
    mapp[++n] = len;
    std::sort(mapp + 1, mapp + n + 1);
    int l = 0, r = len;
    while (l < r) {
        // std::cout << l << " " << r << std::endl;
        int mid = ((long long)l + r + 1) >> 1;
        if (check(mid))
            l = mid;
        else
            r = mid - 1;
    }
    std::cout << l << std::endl;
    return 0;
}