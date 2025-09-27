// 观察数据范围（9e6...1e7）能想到大概只能是一次bfs的时间，
// 更重要的是想到这道题目的本质，就是状态只与到这个点的最短操作次数（可能用蛇头位置和蛇身长度来表达更好）有关而与蛇身现在的状态基本无关。如果在考场上能想明白这一点这道题目才有可能被解决。
// 由于每条边都是1，所以这个问题本质上不用dijkstra来求解，只要第一访问到就一定是最小值

#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <queue>

const int N = 3e3;
const __int128 mod = (__int128)1 << (64);
typedef unsigned long long ull;
int d[N + 2][N + 2], v[N + 2][N + 2], tag[N + 2][N + 2];
int n, m, k;
const int dx[5] = {0, 1, -1, 0, 0};
const int dy[5] = {0, 0, 0, 1, -1};

struct node {
    int x, y;
    int d;
    bool operator<(const node &k) const {
        return d > k.d;
    }
};

bool check(int x, int y) {
    if (x <= 0 || x > n || y <= 0 || y > m) return 0;
    if (tag[x][y] == -1 || v[x][y]) return 0;
    return 1;
}

void print(__int128 x) {
    // if (x < 0)putchar('-'), x = -x;
    if (x > 9) print(x / 10);  // 注意这里是x>9不是x>10 (2019.10 wa哭了回来标记一下)
    std::cout << int(x % 10);
}

int main() {
    std::cin >> n >> m >> k;
    int inix, iniy;
    for (int i = 1; i <= k; i++) {
        int a, b;
        std::cin >> a >> b;
        tag[a][b] = i;
        if (i == 1) {
            inix = a;
            iniy = b;
        }
    }
    for (int i = 1; i <= n; i++) {
        std::string c;
        std::cin >> c;
        for (int j = 0; j < m; j++) {
            if (c[j] == '.')
                continue;
            else
                tag[i][j + 1] = -1;
        }
    }

    std::queue<node> q1;
    std::priority_queue<node> q2;
    memset(d, 0x3f, sizeof d);
    d[inix][iniy] = 0;
    v[inix][iniy] = 1;
    q1.push(node{inix, iniy, 0});
    while (q1.size() + q2.size()) {
        int x, y;
        if (q1.size() && q2.size()) {
            if (q1.front().d <= q2.top().d) {
                x = q1.front().x, y = q1.front().y;
                q1.pop();
            } else {
                x = q2.top().x, y = q2.top().y;
                q2.pop();
            }
        } else if (q1.size()) {
            x = q1.front().x, y = q1.front().y;
            q1.pop();
        } else {
            x = q2.top().x, y = q2.top().y;
            q2.pop();
        }
        // std::cout << x << "," << y << ": " << d[x][y] << std::endl;

        for (int i = 1; i <= 4; i++) {
            int xx = x + dx[i], yy = y + dy[i];
            if (check(xx, yy)) {
                v[xx][yy] = 1;
                if (tag[xx][yy]) {
                    int ls = std::max(k - tag[xx][yy] + 1, d[x][y] + 1);
                    d[xx][yy] = ls;
                    q2.push({xx, yy, ls});
                } else {
                    d[xx][yy] = d[x][y] + 1;
                    q1.push({xx, yy, d[x][y] + 1});
                }
            }
        }
    }

    __int128 ans = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            // std::cout << (d[i][j] == 0x3f3f3f3f ? -1 : d[i][j]) << " \n"[j == m];
            if (d[i][j] != 0x3f3f3f3f) {
                ans += (long long)d[i][j] * d[i][j];
                ans %= mod;
            }
        }
    }

    // print(ans);
    // std::cout << std::endl;
    std::vector<int> aaa;
    while (ans) {
        aaa.push_back(int(ans % 10));
        ans /= 10;
    }
    if (!aaa.size()) aaa.push_back(0);
    for (int i = (int)aaa.size() - 1; i >= 0; i--) {
        std::cout << aaa[i];
    }
    return 0;
}