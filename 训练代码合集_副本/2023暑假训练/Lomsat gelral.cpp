#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <map>
#include <vector>

const int N = 2e5;
std::map<int, int> node[N + 2];
int head[N + 2], ver[N + 2], nxt[N + 2], tot;
long long ans[N + 2];

void add(int x, int y) {
    tot++;
    ver[tot] = y;
    nxt[tot] = head[x];
    head[x] = tot;
}

void merge(int x, int y) {
    for (auto i : node[x]) {
        node[y][i.first] += i.second;
    }
    node[x].clear();
}

void dfs(int x, int fa) {
    for (int i = head[x]; i; i = nxt[i]) {
        int y = ver[i];
        if (y == fa) continue;
        dfs(y, x);
        merge(y, x);
    }
    long long mm = 0, sum = 0;
    for (auto i : node[x]) {
        if (i.second > mm) {
            sum = i.first;
            mm = i.second;
        } else if (i.second == mm) {
            sum += i.first;
        }
    }
    ans[x] = sum;
}

int main() {
    int n;
    std::cin >> n;
    for (int i = 1; i <= n; i++) {
        int a;
        scanf("%d", &a);
        node[i][a]++;
    }
    for (int i = 1; i < n; i++) {
        int a, b;
        scanf("%d%d", &a, &b);
        add(a, b);
        add(b, a);
    }
    dfs(1, 0);
    for (int i = 1; i <= n; i++) {
        printf("%lld ", ans[i]);
    }
    std::cout << std::endl;
    return 0;
}