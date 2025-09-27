#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <vector>

// const int inf = 1e9;
const int N = 5e5;
int mapp[N + 2], du[N + 2], nxt[N * 2 + 2], head[N + 2], ver[N * 2 + 2];
int tot, n;
long long ans = 0, f[N + 2];
std::vector<long long> node[N + 2];

void add(int x, int y) {
    tot++;
    du[y]++;
    ver[tot] = y;
    nxt[tot] = head[x];
    head[x] = tot;
}

bool cmp(int x, int y) {
    return x > y;
}

void dfs(int x, int fa) {
    std::vector<long long> &q = node[x];
    for (int i = head[x]; i; i = nxt[i]) {
        int y = ver[i];
        if (y == fa) continue;
        dfs(y, x);
        q.push_back(f[y]);
    }
    // std::cout << x << " " << fa << " " << q.size() << std::endl;
    std::sort(q.begin(), q.end(), cmp);
    if (!q.size()) {
        f[x] = mapp[x];
    } else if (q.size() >= 2) {
        long long q1 = q[0];
        long long q2 = q[0] + q[1] + mapp[x];
        for (int i = 2; i < (int)q.size(); i++) {
            if (q[i] >= 0)
                q2 += q[i];
            else
                break;
        }
        f[x] = std::max(q1, q2);
    } else {
        f[x] = q[0];
    }
}

void dfs(int x, int fa, int chuan) {
    std::vector<long long> &q = node[x];
    q.push_back(chuan);
    std::sort(q.begin(), q.end(), cmp);
    long long q1 = 0, q2 = 0, mxx = 0;
    int tag = 0;
    if (q.size() >= 3) {
        q1 = q[0] + q[1];
        q2 = q[0] + q[1] + q[2] + mapp[x];
        for (int i = 3; i < (int)q.size(); i++) {
            if (q[i] >= 0) {
                tag = i;
                q2 += q[i];
            } else
                break;
        }
        if (q1 > q2) {
            tag = 1;
            mxx = std::max(mxx, q1);
        } else {
            tag = 2;
            mxx = std::max(mxx, q2);
        }
    } else if (q.size() >= 2) {
        tag = 1;
        q1 = q[0] + q[1];
        q2 = q[0] + mapp[x];
        if (q1 > q2) {
            mxx = q1;
        } else {
            mxx = q2;
            tag = 0;
        }
    } else {
        mxx = mapp[x] + q[0];
    }
    std::cout << x << " " << fa << " " << chuan << " " << mxx << " " << tag << std::endl;
    std::cout << q[0] << " " << q[1] << " " << q[2] << std::endl;
    ans = std::max(ans, mxx);

    for (int i = head[x]; i; i = nxt[i]) {
        int y = ver[i];
        if (y == fa) continue;
        if (f[y] >= q[tag])
            dfs(y, x, mxx - f[y]);
        else
            dfs(y, x, mxx);

        // long long q1 = q[0]==f[y]? q[1]:q[0];
        // int tag=0,ls=2;
        // long long q2 = q[0] + q[1] + mapp[x];
        // if (q[0]==f[y] || q[1]==f[y]) {
        //     ls++;
        //     tag++;
        //     q2=q[0]+q[1]+q[2]+mapp[x]-f[y];
        // }
        // for (int i = ls; i < (int)q.size(); i++) {
        //     if (q[i]==f[y] && !tag) {
        //         tag++;
        //         continue;
        //     }
        //     if (q[i] >= 0)
        //         q2 += q[i];
        //     else
        //         break;
        // }
    }
}

int main() {
    int t;
    std::cin >> t;
    while (t--) {
        tot = 0;
        ans = 0;
        std::cin >> n;
        for (int i = 1; i <= n; i++) {
            scanf("%d", mapp + i);
            head[i] = 0;
            du[i] = 0;
            f[i] = 0;
            node[i].clear();
        }
        for (int i = 1; i < n; i++) {
            int a, b;
            scanf("%d%d", &a, &b);
            add(a, b);
            add(b, a);
        }

        dfs(1, 0);
        for (int i = 1; i <= n; i++) {
            std::cout << f[i] << " ";
        }
        puts("");
        dfs(1, 0, 0);
        std::cout << ans << std::endl;
    }
    return 0;
}