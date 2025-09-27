#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <vector>

const int N = 2e5;
int head[N + 2], nxt[N + 2], ver[N + 2], tot, dep[N + 2], tag[N + 2];
int n, k, du[N + 2], s[N + 2];

void add(int x, int y) {
    tot++;
    ver[tot] = y;
    nxt[tot] = head[x];
    head[x] = tot;
}

int dfs(int x) {
    // std::cout << x << " " << fa << std::endl;
    for (int i = head[x]; i; i = nxt[i]) {
        int y = ver[i];
        if (s[y]) return tag[y];
        if (dep[y]) {
            if (dep[x] + 1 - dep[y] == k)
                tag[y] = 1;
            else
                tag[y] = 0;
            s[y] = 1;
            return tag[y];
        } else {
            dep[y] = dep[x] + 1;
            tag[x] = dfs(y);
            s[x] = 1;
            return tag[x];
        }
    }
    return 0;
}
int main() {
    int t;
    std::cin >> t;
    while (t--) {
        int tt = 0;
        for (int i = 1; i <= tot; i++) {
            nxt[i] = ver[i] = 0;
        }
        tot = 0;

        std::cin >> n >> k;
        if (k == 1) {
            for (int i = 1; i <= n; i++) {
                int a;
                std::cin >> a;
                if (i != a) tt = 1;
            }
            if (tt)
                std::cout << "NO" << std::endl;
            else
                std::cout << "YES" << std::endl;
            continue;
        }
        for (int i = 1; i <= n; i++) head[i] = dep[i] = du[i] = s[i] = 0;
        for (int i = 1; i <= n; i++) {
            int a;
            std::cin >> a;
            add(i, a);
            du[a]++;
        }
        for (int i = 1; i <= n; i++) {
            if (!du[i]) {
                // std::cout << i << " ";
                dep[i] = 1;
                if (!dfs(i)) {
                    tt = 1;
                    break;
                }
            }
        }
        for (int i = 1; i <= n; i++) {
            if (!dep[i]) {
                // std::cout << i << " ";
                dep[i] = 1;
                if (!dfs(i)) {
                    tt = 1;
                    break;
                }
            }
        }
        // std::cout << std::endl;
        if (tt)
            std::cout << "NO" << std::endl;
        else
            std::cout << "YES" << std::endl;
    }
    return 0;
}