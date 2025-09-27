#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <vector>

const int N = 5e5;
int tot, head[N + 2], ver[N * 2 + 2], nxt[N * 2 + 2], fa[N + 2], v[N + 2], ans[N + 2];
std::vector<int> query[N + 2], query_id[N + 2];

void add(int x, int y) {
    tot++;
    ver[tot] = y;
    nxt[tot] = head[x];
    head[x] = tot;
}

void add_query(int x, int y, int id) {
    query[x].push_back(y), query[y].push_back(x);
    query_id[x].push_back(id), query_id[y].push_back(id);
}

int find(int x) {
    if (fa[x] == x)
        return x;
    else
        return fa[x] = find(fa[x]);
}

void tarjan(int x) {
    v[x] = 1;
    for (int i = head[x]; i; i = nxt[i]) {
        int y = ver[i];
        if (v[y]) continue;
        tarjan(y);
        fa[y] = x;
    }
    for (int i = 0; i < (int)query[x].size(); i++) {
        int y = query[x][i], id = query_id[x][i];
        if (v[y] == 2) {
            ans[id] = find(y);
        }
    }
    v[x] = 2;
}

int main() {
    int n, m, s;
    std::cin >> n >> m >> s;
    for (int i = 1; i <= n; i++) fa[i] = i;
    for (int i = 1; i < n; i++) {
        int a, b;
        scanf("%d%d", &a, &b);
        add(a, b);
        add(b, a);
    }
    for (int i = 1; i <= m; i++) {
        int a, b;
        scanf("%d%d", &a, &b);
        if (a == b)  // 这个特判一定要有,不然会无解
            ans[i] = a;
        else
            add_query(a, b, i);
    }
    tarjan(s);
    for (int i = 1; i <= m; i++) {
        printf("%d\n", ans[i]);
    }
    return 0;
}