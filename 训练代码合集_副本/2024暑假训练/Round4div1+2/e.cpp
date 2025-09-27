#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <queue>
#include <vector>

#define int long long
const int N = 1e4;
int head[N + 2], nxt[N * 2 + 2], ver[N * 2 + 2], tot;
int v[N + 2], dep[N + 2], deal;

void add(int x, int y) {
    tot++;
    ver[tot] = y;
    nxt[tot] = head[x];
    head[x] = tot;
}

void dfss(int x, int fa) {
    for (int i = head[x]; i; i = nxt[i]) {
        int y = ver[i];
        if (y == fa) continue;
        if (!dep[y]) {
            dep[y] = dep[x] + 1;
            dfss(y, x);
        } else {
            if (std::abs(dep[x] - dep[y]) % 2 == 0) {
                deal = 0;
            }
        }
    }
}

void solve() {
    int n, m;
    std::cin >> n >> m;
    tot = 0;
    for (int i = 1; i <= n; i++) head[i] = 0, dep[i] = 0;
    for (int i = 1; i <= n; i++) {
        v[i] = 0;
    }
    for (int i = 1; i <= m; i++) {
        int a, b;
        std::cin >> a >> b;
        add(a, b), add(b, a);
    }

    dep[1] = 1;
    deal = 1;
    dfss(1, 0);

    if (deal) {
        std::cout << "Bob" << std::endl;
        std::cout.flush();
        std::vector<int> q1, q2;
        for (int i = 1; i <= n; i++) {
            if (dep[i] % 2)
                q1.push_back(i);
            else
                q2.push_back(i);
        }
        int tag1 = -1, tag2 = -1, num = 0;
        while (tag1 + 1 < (int)q1.size() && tag2 + 1 < (int)q2.size()) {
            num++;
            int a, b;
            std::cin >> a >> b;
            tag1++;
            if (tag1 == 0) {
                std::cout << q1[tag1] << " " << a << std::endl;
            } else if (a == v[q1[tag1 - 1]]) {
                std::cout << q1[tag1] << " " << a << std::endl;
            } else if (b == v[q1[tag1 - 1]]) {
                std::cout << q1[tag1] << " " << b << std::endl;
            } else {
                tag1--;
                tag2++;
                if (tag2 == 0) {
                    std::cout << q2[tag2] << " " << a << std::endl;
                } else if (a == v[q2[tag2 - 1]]) {
                    std::cout << q2[tag2] << " " << a << std::endl;
                } else if (b == v[q1[tag1 - 1]]) {
                    std::cout << q1[tag1] << " " << b << std::endl;
                }
            }
        }
    } else {
        std::cout << "Alice" << std::endl;
        std::cout.flush();
        int tag = 1;
        while (1) {
            std::cout << "1 2\n";
            std::cout.flush();
            int a, b;
            std::cin >> a >> b;
            v[a] = b;
            for (int i = head[a]; i; i = nxt[i]) {
                int y = ver[i];
                if (v[y] == b) tag = 0;
            }
            if (!tag) break;
        }
    }
}

signed main() {
    int times = 1;
    std::cin >> times;
    while (times--) {
        solve();
    }
    return 0;
}