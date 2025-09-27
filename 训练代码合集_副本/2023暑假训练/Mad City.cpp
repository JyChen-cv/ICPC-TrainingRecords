#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <vector>

const int N = 2e5;
int head[N + 2], nxt[N * 2 + 2], ver[N * 2 + 2], tot, dep[N + 2], hoop[N + 2], len;
int n, st, en, ro_st, ro_en, du[N + 2], stp, re;

void add(int x, int y) {
    ver[++tot] = y;
    nxt[tot] = head[x];
    head[x] = tot;
}

bool dfs(int x, int fr) {
    for (int i = head[x]; i != -1; i = nxt[i]) {
        int y = ver[i];
        if ((i ^ 1) == fr) continue;
        if (dep[y]) {
            if (len) continue;
            hoop[x] = 1;
            stp = y;
            len = std::abs(dep[x] + 1 - dep[y]);
            continue;
        }
        dep[y] = dep[x] + 1;
        if (dfs(y, i) && dep[x] >= dep[stp]) hoop[x] = 1;
    }
    return hoop[x];
}

int dfs2(int x, int fr) {
    for (int i = head[x]; i != -1; i = nxt[i]) {
        int y = ver[i];
        if (i == (fr ^ 1)) continue;
        if (hoop[y]) {
            return y;
        }
        int res = dfs2(y, i);
        if (res) return res;
    }
    return 0;
}

void find(int x, int tar, int fr, int d) {
    if (x == tar) {
        re = d;
        return;
    }
    for (int i = head[x]; i != -1; i = nxt[i]) {
        int y = ver[i];
        if ((i ^ 1) == fr) continue;
        find(y, tar, i, d + 1);
    }
}

int main() {
    int t;
    std::cin >> t;
    while (t--) {
        for (int i = 0; i <= tot; i++) nxt[i] = ver[i] = 0;
        tot = -1;  // 成对变换
        int tag = 0;
        std::cin >> n >> st >> en;
        for (int i = 1; i <= n; i++) {
            hoop[i] = dep[i] = du[i] = 0;
            head[i] = -1;  // 成对变换
        }
        for (int i = 1; i <= n; i++) {
            int a, b;
            std::cin >> a >> b;
            du[a]++;
            du[b]++;
            add(a, b);
            add(b, a);
            tag = (a == b);
        }

        int root = 0;
        du[0] = 5;
        for (int i = 1; i <= n; i++) {
            root = (du[root] > du[i] ? i : root);
        }
        if (tag) {
            std::cout << "No" << std::endl;
            continue;
        }
        len = 0;
        dep[root] = 1;
        dfs(root, -1);
        ro_st = (hoop[st] ? st : dfs2(st, -1));
        ro_en = (hoop[en] ? en : dfs2(en, -1));
        int dis = std::min(std::abs(dep[ro_st] - dep[ro_en]), len - std::abs(dep[ro_st] - dep[ro_en]));
        find(st, ro_st, -1, 0);
        int dis_st = re;
        find(en, ro_en, -1, 0);
        int dis_en = re;
        if (ro_st == ro_en)
            tag = (dis_st <= dis_en);
        else
            tag = (dis_st + dis <= dis_en);
        tag ? std::cout << "No" << std::endl : std::cout << "Yes" << std::endl;
    }
    return 0;
}