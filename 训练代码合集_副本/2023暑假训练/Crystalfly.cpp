#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <vector>

const int N = 1e5;
int nxt[N * 2 + 2], ver[N * 2 + 2], mapp[N + 2], head[N + 2], t[N + 2], tot;

void add(int x, int y) {
    tot++;
    ver[tot] = y;
    nxt[tot] = head[x];
    head[x] = tot;
}

int dfs(int x, int fa) {
    int mx = 0;
    for (int i = head[x]; i; i = nxt[i]) {
        int y = ver[i];
        if (y == fa) continue;
        mx = std::max(mx, dfs(y, x));
    }

    std::vector<int> q3, q;
    for (int i = head[x]; i; i = nxt[i]) {
        int y = ver[i];
        if (y == fa) continue;
        if (t[y] == 3)
            q3.push_back(mapp[y]);
        else
            q.push_back(mapp[y]);
    }
    // std::cout << x << " " << fa << " " << mx << " " << q.size() << " " << q3.size() << std::endl;
    std::sort(q.begin(), q.end());
    std::sort(q3.begin(), q3.end());
    if (!q3.size() && !q.size())
        return 0;
    else if (!q3.size())
        return q.size() ? q[q.size() - 1] + mx : 0;
    else if (!q.size()) {
        if (q3.size() >= 2)
            return q3[q3.size() - 1] + q3[q3.size() - 2] + mx;
        else if (q3.size() >= 1)
            return q3[q3.size() - 1] + mx;
        else
            return 0;
    } else {
        return q3[q3.size() - 1] + mx + std::max(q[q.size() - 1], q3.size() >= 2 ? q3[q3.size() - 2] : 0);
    }
}

int main() {
    int T;
    std::cin >> T;
    while (T--) {
        int n;
        scanf("%d", &n);
        tot = 0;
        for (int i = 1; i <= n; i++) {
            head[i] = 0;
        }
        for (int i = 1; i <= n; i++) {
            scanf("%d", mapp + i);
        }
        for (int i = 1; i <= n; i++) {
            scanf("%d", t + i);
        }

        for (int i = 1; i < n; i++) {
            int a, b;
            scanf("%d%d", &a, &b);
            add(a, b);
            add(b, a);
        }
        printf("%d\n", dfs(1, 0) + mapp[1]);
    }
    return 0;
}