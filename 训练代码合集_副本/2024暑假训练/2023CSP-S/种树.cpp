#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <map>
#include <queue>
#include <vector>

#define int long long
typedef std::pair<int, int> pii;
const int N = 1e5;
int a[N + 2], b[N + 2], c[N + 2];
int head[N + 2], nxt[N * 2 + 2], ver[N * 2 + 2], tot, f[N + 2];
int v[N + 2];
int n;

void add(int x, int y) {
    tot++;
    ver[tot] = y;
    nxt[tot] = head[x];
    head[x] = tot;
}

void dfs(int x, int fa) {
    f[x] = fa;
    for (int i = head[x]; i; i = nxt[i]) {
        int y = ver[i];
        if (y == fa) continue;
        dfs(y, x);
    }
}
inline bool find(int x, __int128 l, __int128 r) {
    __int128 val = 0;
    if (c[x] >= 0) {
        val += (r - l + 1) * b[x] + (r + l) * (r - l + 1) / 2 * c[x];
    } else {
        __int128 day = -(b[x] - 1) / c[x];
        if ((b[x] - 1) % (-c[x])) day++;
        if (l >= day)
            val = (r - l + 1);
        else {
            day = std::min(day, r + 1);
            val = std::max(__int128(0), (r - day + 1)) + (day - l) * b[x] + (l + day - 1) * (day - l) / 2 * c[x];
        }
    }
    return val >= a[x];
}
inline int deal(int x) {
    if (v[x])
        return 0;
    else {
        v[x] = 1;
        return deal(f[x]) + 1;
    }
}
bool check(int x) {
    std::vector<pii> q;
    for (int i = 1; i <= n; i++) {
        if (!find(i, 1, x)) return 0;  // 这句话减小很多常数
        int l = 1, r = std::min(x, n);
        while (l < r) {
            int mid = (l + r + 1) >> 1;
            if (find(i, mid, x))
                l = mid;
            else
                r = mid - 1;
        }
        q.push_back(std::make_pair(l, i));
    }
    std::sort(q.begin(), q.end());

    memset(v, 0, sizeof(v));
    v[0] = 1;
    int tot = 0;
    for (auto i : q) {
        if (v[i.second]) continue;
        tot += deal(i.second);
        if (tot > i.first) return 0;
    }
    return 1;
}

signed main() {
    // freopen("/Users/chenjiayou/Downloads/tree/tree4.in", "r", stdin);
    std::ios::sync_with_stdio(0);
    std::cin.tie(0), std::cout.tie(0);
    std::cin >> n;
    for (int i = 1; i <= n; i++) {
        std::cin >> a[i] >> b[i] >> c[i];
    }
    for (int i = 1; i < n; i++) {
        int a, b;
        std::cin >> a >> b;
        add(a, b), add(b, a);
    }
    dfs(1, 0);

    int l = 0, r = 1e9;
    while (l < r) {
        int mid = (l + r) >> 1;
        // std::cout << mid << std::endl;
        if (check(mid))
            r = mid;
        else
            l = mid + 1;
    }
    std::cout << l << std::endl;
    return 0;
}