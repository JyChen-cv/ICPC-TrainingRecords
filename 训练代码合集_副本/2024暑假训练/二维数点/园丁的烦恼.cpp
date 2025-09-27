#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <map>
#include <vector>
#pragma pack(1)  // ???

const int N = 5e5;
std::pair<int, int> p[N + 5];
std::vector<std::pair<int, int>> q;
std::map<std::pair<int, int>, int> ans;
int tr[(int)1e7 + 5];
int n, m;
struct group {
    int x1, y1, x2, y2;
} rem[N + 2];

int lowbit(int x) {
    return x & (-x);
}
void add(int p, int x) {
    while (p <= n) {
        tr[p] += x;
        p += lowbit(p);
    }
}
int query(int p) {
    int res = 0;
    while (p) {
        res += tr[p];
        p -= lowbit(p);
    }
    return res;
}

int main() {
    std::cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        int a, b;
        std::cin >> a >> b;
        a++, b++;
        p[i] = {a, b};
    }
    std::sort(p + 1, p + n + 1);
    for (int i = 1; i <= m; i++) {
        std::cin >> rem[i].x1 >> rem[i].y1 >> rem[i].x2 >> rem[i].y2;
        rem[i].x1++, rem[i].y1++, rem[i].x2++, rem[i].y2++;
        q.push_back({rem[i].x1 - 1, rem[i].y1 - 1});
        q.push_back({rem[i].x2, rem[i].y1 - 1});
        q.push_back({rem[i].x1 - 1, rem[i].y2});
        q.push_back({rem[i].x2, rem[i].y2});
    }
    std::sort(q.begin(), q.end());
    int tag = 0;
    for (int i = 1; i <= n; i++) {
        while (tag < (int)q.size() && q[tag] < p[i]) {
            ans[q[tag]] = query(q[tag].second);
            tag++;
        }
        add(p[i].second, 1);
    }
    while (tag < (int)q.size()) {
        ans[q[tag]] = query(q[tag].second);
        tag++;
    }
    for (int i = 1; i <= m; i++) {
        int res = 0;
        res += ans[{rem[i].x2, rem[i].y2}];
        res -= ans[{rem[i].x1 - 1, rem[i].y2}];
        res -= ans[{rem[i].x2, rem[i].y1 - 1}];
        res += ans[{rem[i].x1 - 1, rem[i].y1 - 1}];
        // std::cout << rem[i].x1 - 1 << " " << rem[i].y1 - 1 << ": " << ans[{rem[i].x1 - 1, rem[i].y1 - 1}] << std::endl;
        // std::cout << rem[i].x1 - 1 << " " << rem[i].y2 << ": " << ans[{rem[i].x1 - 1, rem[i].y2}] << std::endl;
        // std::cout << rem[i].x2 << " " << rem[i].y1 - 1 << ": " << ans[{rem[i].x2, rem[i].y1 - 1}] << std::endl;
        // std::cout << rem[i].x2 << " " << rem[i].y2 << ": " << ans[{rem[i].x2, rem[i].y2}] << std::endl;
        std::cout << res << std::endl;
    }

    return 0;
}