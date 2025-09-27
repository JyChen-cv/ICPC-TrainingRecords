#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <map>
#include <vector>

#define int long long
const int N = 2e5;
int a[N + 2], b[N + 2];
int tr[N + 2], n;
std::vector<int> q;
std::map<int, int> p;

inline int lowbit(int x) {
    return x & (-x);
}

void add(int x) {
    while (x <= n) {
        tr[x] += 1;
        x += lowbit(x);
    }
}

int query(int x) {
    int res = 0;
    while (x) {
        res += tr[x];
        x -= lowbit(x);
    }
    return res;
}
int sum(int l, int r) {
    return query(r) - query(l - 1);
}

int deal(int x[]) {
    std::sort(q.begin(), q.end());
    q.erase(unique(q.begin(), q.end()), q.end());
    for (int i = 1; i <= n; i++) {
        x[i] = std::lower_bound(q.begin(), q.end(), x[i]) - q.begin() + 1;
        // std::cout << x[i] << " \n"[i == n];
    }
    int res = 0;
    for (int i = n; i >= 1; i--) {
        res += sum(1, x[i] - 1);
        add(x[i]);
    }
    return res;
}

void solve() {
    p.clear();
    std::cin >> n;
    for (int i = 1; i <= n; i++) tr[i] = 0;
    int tag = 1;
    q.clear();
    for (int i = 1; i <= n; i++) {
        std::cin >> a[i];
        p[a[i]] = 1;
        q.push_back(a[i]);
    }
    int numa = deal(a);
    for (int i = 1; i <= n; i++) tr[i] = 0;
    q.clear();
    for (int i = 1; i <= n; i++) {
        std::cin >> b[i];
        if (!p[b[i]]) tag = 0;
        q.push_back(b[i]);
    }
    if (tag == 0) {
        std::cout << "NO" << std::endl;
        return;
    }
    int numb = deal(b);
    int num = std::abs(numa - numb);
    // std::cout << numa << " " << numb << std::endl;
    if (num % 2 == 0)
        std::cout << "YES" << std::endl;
    else
        std::cout << "NO" << std::endl;
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