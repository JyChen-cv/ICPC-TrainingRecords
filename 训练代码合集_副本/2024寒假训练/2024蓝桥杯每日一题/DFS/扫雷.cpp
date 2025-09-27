#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <queue>

const int N = 5e4;
struct node {
    double x, y, r;
    void input() {
        std::cin >> x >> y >> r;
    }
} mapp[N + 2];
int v[N + 2];

int main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);
    int n, m;
    std::cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        mapp[i].input();
    }

    std::queue<node> q;
    for (int i = 1; i <= m; i++) {
        node a;
        a.input();
        q.push(a);
    }
    while (q.size()) {
        node ls = q.front();
    }
    return 0;
}