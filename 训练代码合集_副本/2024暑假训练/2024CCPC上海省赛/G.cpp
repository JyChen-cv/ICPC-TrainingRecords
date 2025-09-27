#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <vector>

#define x first
#define y second
const int N = 10;
const int mod = 998244353;
std::vector<std::pair<int, int> > q;
int tag[N + 2];
bool v[1030][102][102], txt[102][102], dir[12][5];  // 1 2 3 4 上下左右
int n, m, ans[1030][102][102], ma[102][102];

int dis(std::pair<int, int> a, std::pair<int, int> b) {
    int res = std::abs(a.x - b.x) + std::abs(a.y - b.y);
    return res;
}

const int dx[10] = {-2, -2, 2, 2, 1, -1, -1, 1};
const int dy[10] = {-1, 1, 1, -1, -2, -2, 2, 2};

bool check(int x, int y) {
    return (x <= n && x >= 1) && (y <= n && y >= 1);
}

void deal() {
    for (int i = 0; i < m; i++) {
        if (!tag[i]) continue;
        for (int j = i + 1; j < m; j++) {
            if (!tag[j]) continue;
            // std::cout << i << " " << j << std::endl;
            if (dis(q[i], q[j]) != 1) continue;
            if (q[i].x > q[j].x) {
                dir[i][1] = dir[j][2] = 1;
            } else if (q[i].x < q[j].x) {
                dir[i][2] = dir[j][1] = 1;
            } else if (q[i].y < q[j].y) {
                dir[i][4] = dir[j][3] = 1;
            } else
                dir[i][3] = dir[j][4] = 1;
        }
    }

    // for (int i = 0; i < m; i++) {
    //     std::cout << dir[i][1] << " " << dir[i][2] << " " << dir[i][3] << " " << dir[i][4] << std::endl;
    // }
    // std::cout << std::endl;

    for (int i = 0; i < m; i++) {
        for (int j = 0; j <= 7; j++) {
            if (!tag[i]) continue;
            if (dir[i][j / 2 + 1])
                continue;
            else {
                int xx = q[i].x + dx[j], yy = q[i].y + dy[j];
                if (check(xx, yy)) {
                    // std::cout << q[i].x << " " << q[i].y << " " << i << " " << j << " " << xx << " ??? " << yy << std::endl;
                    txt[xx][yy] = 1;
                }
            }
        }
    }

    // for (int i = 1; i <= n; i++) {
    //     for (int j = 1; j <= n; j++) {
    //         std::cout << txt[i][j] << " ";
    //     }
    //     std::cout << std::endl;
    // }
    // std::cout << std::endl;
}

int main() {
    std::cin >> n >> m;
    n++;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) ma[i][j] = -1;
    }
    for (int i = 1; i <= m; i++) {
        int a, b;
        std::cin >> a >> b;
        a++, b++;
        q.push_back(std::make_pair(a, b));  // 从0开始的
        ma[a][b] = q.size() - 1;
    }
    int num = (1 << m) - 1;
    for (int i = 0; i <= num; i++) {
        for (int j = 0; j < m; j++) {
            tag[j] = 0;
            for (int k = 1; k <= 4; k++) dir[j][k] = 0;
        }
        for (int j = 0; j < m; j++) {
            if (i & (1 << j)) tag[j] = 1;
        }
        // for (int j = 0; j < m; j++) {
        //     std::cout << tag[j] << " ";
        // }
        // std::cout << std::endl;
        // std::cout << i << std::endl;
        deal();
        for (int x = 1; x <= n; x++) {
            for (int y = 1; y <= n; y++) {
                v[i][x][y] = txt[x][y];
                txt[x][y] = 0;
            }
        }
    }

    ans[num][1][0] = 1;
    for (int i = num; i >= 0; i--) {
        for (int x = 1; x <= n; x++) {
            for (int y = 1; y <= n; y++) {
                if (v[i][x][y]) continue;  // 如果当前早情况下遭受攻击，则跳过
                int ls = ma[x][y];         // 判断这里有几号马
                if (ls != -1) {
                    // std::cout << i << " " << ls << std::endl;
                    if ((i & (1 << ls)) == 0) {
                        ans[i][x][y] = ans[i + (1 << ls)][x - 1][y] + ans[i + (1 << ls)][x][y - 1];
                        ans[i][x][y] %= mod;
                    } else
                        ans[i][x][y] = 0;
                } else
                    ans[i][x][y] = (ans[i][x - 1][y] + ans[i][x][y - 1]) % mod;
            }
        }
        // break;
        // std::cout << i << std::endl;
        // for (int x = 1; x <= n; x++) {
        //     for (int y = 1; y <= n; y++) {
        //         std::cout << v[i][x][y] << " ";
        //     }
        //     std::cout << std::endl;
        // }
        // std::cout << std::endl;
        // for (int x = 1; x <= n; x++) {
        //     for (int y = 1; y <= n; y++) {
        //         std::cout << ans[i][x][y] << " ";
        //     }
        //     std::cout << std::endl;
        // }
        // std::cout << std::endl;
    }
    int anss = 0;
    for (int i = 0; i <= num; i++) {
        anss += ans[i][n][n];
        anss %= mod;
    }
    std::cout << anss << std::endl;
    return 0;
}
/*
2 8
0 1
0 2
1 0
1 1
1 2
2 0
2 1
2 2

2 4
1 1
1 2
2 1
2 2

*/