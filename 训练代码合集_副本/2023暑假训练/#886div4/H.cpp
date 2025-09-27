#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <vector>

typedef long long ll;
const int N = 2e5;
int fa[N + 2];
ll d[N + 2];

int find(int x) {
    if (fa[x] == x) return x;
    int f = find(fa[x]);
    d[x] += d[fa[x]];
    return fa[x] = f;
}

int main() {
    int t;
    std::cin >> t;
    while (t--) {
        int n, m;
        std::cin >> n >> m;
        for (int i = 1; i <= n; i++) {
            fa[i] = i;
            d[i] = 0;
        }
        int tag = 0;
        for (int i = 1; i <= m; i++) {
            int a, b;
            ll c;
            std::cin >> a >> b >> c;
            if (tag) continue;
            int f_a = find(a);
            int f_b = find(b);
            // std::cout << d[a] << " " << d[b] << std::endl;
            if (f_a != f_b) {
                d[f_a] = c - d[a];
                fa[f_a] = b;
            } else {
                if (c != d[a] - d[b]) tag = 1;
            }
        }
        if (tag)
            std::cout << "NO" << std::endl;
        else
            std::cout << "YES" << std::endl;
    }
    return 0;
}