#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <vector>

const int N = 1000;
int fa[N + 2];
std::vector<int> mapp[N + 2];

bool check(int x, int y) {
    int m = mapp[x].size() - 1;
    for (int i = 0; i <= m; i++) {
        if (mapp[y][i] > mapp[x][i])
            continue;
        else
            return 0;
    }
    return 1;
}

int main() {
    int n, m;
    std::cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            int a;
            std::cin >> a;
            mapp[i].push_back(a);
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (i == j) continue;
            if (check(i, j)) {
                fa[i] = j;
                break;
            }
        }
        std::cout << fa[i] << std::endl;
    }
    return 0;
}