#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <vector>

#define int long long
const int N = 2e5, M = 4e5;
int head[N + 2], ver[M + 2], nxt[M + 2], tot, du[N + 2];
int v[N + 2], numl[N + 2], numx[N + 2], ans[N + 2];
std::vector<int> q, lp, xd, rel;
std::vector<std::pair<int, int>> rex;

void add(int x, int y) {
    tot++;
    ver[tot] = y;
    nxt[tot] = head[x];
    head[x] = tot;
    du[y]++;
}

void dfs(int x) {
    v[x] = 1;
    q.push_back(x);
    for (int i = head[x]; i; i = nxt[i]) {
        int y = ver[i];
        if (v[y]) continue;
        dfs(y);
    }
}

bool cmp(std::pair<int, int> x, std::pair<int, int> y) {
    return x.first > y.first;
}

bool cmp2(int x, int y) {
    return x > y;
}

signed main() {
    int n, m;
    std::cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        int a, b;
        std::cin >> a >> b;
        add(a, b);
        add(b, a);
    }

    for (int i = 1; i <= m; i++) {
        if (!v[i]) {
            q.clear();
            dfs(i);
            if (q.size() < 3) {
                if (du[q[0]] == 2 && du[q[q.size() - 1]] == 2)
                    lp.push_back(2);
                else
                    continue;  // 特判两个成环会出错
            }
            if (du[q[q.size() - 1]] == 1) {
                xd.push_back(q.size() - 1);
            } else {
                lp.push_back(q.size());
            }
        }
    }

    std::sort(lp.begin(), lp.end());
    for (auto i : lp) numl[i]++;
    lp.erase(unique(lp.begin(), lp.end()), lp.end());
    for (auto i : lp) {
        for (int j = 0; j <= 20; j++) {
            if (numl[i] >= (1 << j)) {
                rel.push_back(i * (1 << j));
                numl[i] -= (1 << j);
            } else {
                if (numl[i])
                    rel.push_back(i * numl[i]);
                break;
            }
        }
    }

    for (int i = 0; i < (int)rel.size(); i++) {
        for (int j = n; j >= 0; j--) {
            if (ans[j - rel[i]] == j - rel[i]) ans[j] = j;  // 这样ans[0]=0就合法了
        }
    }
    int tag = 0, mmax = 0;
    for (int i = 1; i <= n; i++) {
        if (ans[i]) mmax = i;
    }
    for (int i = 1; i <= mmax; i++) {
        if (!ans[i]) {
            ans[i] = i - tag - 1 + ans[tag];
        } else
            tag = i;
    }

    std::sort(xd.begin(), xd.end(), cmp2);
    int lst = mmax;
    for (int i = 0; i < (int)xd.size(); i++) {
        if (lst > n) break;
        ans[lst + xd[i]] = ans[lst] + xd[i] - 1;
        lst += xd[i];
    }

    tag = mmax;
    for (int i = mmax + 1; i <= lst; i++) {
        if (!ans[i]) {
            ans[i] = i - tag - 1 + ans[tag];
        } else
            tag = i;
    }

    for (int i = 1; i <= std::min(lst, n); i++) {
        std::cout << ans[i] << " ";
    }
    for (int i = lst + 1; i <= n; i++) {
        std::cout << ans[lst] << " ";
    }
    std::cout << std::endl;

    return 0;
}

/*
12 14
1 2
2 3
1 3
4 5
5 6
6 7
4 7
8 9
9 10
8 10
11 12
13 14


3 6
1 2
2 5
1 6

6 10
1 2
2 3
4 5
5 6
8 9
6 7

*/