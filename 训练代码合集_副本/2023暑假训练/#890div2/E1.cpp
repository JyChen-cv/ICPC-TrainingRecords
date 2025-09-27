#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <vector>

const int N = 5000;
int nxt[N + 2], ver[N + 2], head[N + 2], tot, siz[N + 2], ans;

void add(int x, int y) {
    tot++;
    ver[tot] = y;
    nxt[tot] = head[x];
    head[x] = tot;
}

void dfs(int x) {
    for (int i = head[x]; i; i = nxt[i]) {
        int y = ver[i];
        dfs(y);
        siz[x] += siz[y];
    }
    siz[x]++;
}

void deal(int x) {
    std::vector<int> a;
    int al = 0;
    for (int i = head[x]; i; i = nxt[i]) {
        int y = ver[i];
        deal(y);
        a.push_back(siz[y]);
        al += siz[y];
    }
    int ma = 0;
    if (!al)
        return;
    int f[al + 5];
    for (int i = 0; i <= al; i++) f[i] = 0;
    f[0] = 1;
    for (int i = 0; i < (int)a.size(); i++) {
        for (int j = al; j >= a[i]; j--) {
            if (f[j - a[i]]) {
                f[j] = 1;
                ma = std::max(ma, j * (al - j));
            }
        }
    }
    ans += ma;
}

int main() {
    int n;
    std::cin >> n;
    for (int i = 2; i <= n; i++) {
        int a;
        std::cin >> a;
        add(a, i);
    }

    dfs(1);
    deal(1);
    std::cout << ans << std::endl;
    return 0;
}