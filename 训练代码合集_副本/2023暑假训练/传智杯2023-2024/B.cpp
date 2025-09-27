#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <vector>

const int N = 1e5;
int nxt[N * 2 + 2], ver[N * 2 + 2], head[N + 2], tot, v[N + 2], pt[N + 2];
bool tag = 0, col[N + 2];

void add(int x, int y) {
    tot++;
    ver[tot] = y;
    nxt[tot] = head[x];
    head[x] = tot;
}

void dfs(int x, int fa) {
    // if (tag) return ;
    int res = 0;
    for (int i = head[x]; i; i = nxt[i]) {
        int y = ver[i];
        if (fa == y) continue;
        dfs(y, x);
        if (v[y] == 1)
            continue;
        else if (!v[y]) {
            v[y] = 1;
            v[x] = 1;
            pt[x] = y;
            pt[y] = x;
            res++;
        }
    }
    if (res >= 2) tag = 1;
}

void dfs(int x, int fa, int c) {
    col[x] = c;
    for (int i = head[x]; i; i = nxt[i]) {
        int y = ver[i];
        if (fa == y) continue;
        if (pt[x] == y)
            dfs(y, x, c);
        else
            dfs(y, x, c ^ 1);
    }
}

int main() {
    int n;
    std::cin >> n;
    for (int i = 1; i < n; i++) {
        int a, b;
        scanf("%d%d", &a, &b);
        add(a, b);
        add(b, a);
    }
    dfs(1, 0);
    if (tag || n % 2 == 1)
        std::cout << -1 << std::endl;
    else {
        dfs(1, 0, 1);
        for (int i = 1; i <= n; i++) {
            if (col[i])
                putchar('R');
            else
                putchar('B');
        }
    }
    return 0;
}