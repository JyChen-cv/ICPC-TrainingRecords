#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <vector>

const int N = 100;
int n, ans = 1e9;
int biao[2000], v[2000];
std::vector<int> q[N + 2];

void dfs(int x, int res) {
    if (x > n) {
        ans = std::min(ans, res);
        return;
    }
    for (int i = 0; i < (int)q[x].size(); i++) {
        if (v[q[x][i]] == 0) {
            v[q[x][i]] = 1;
            dfs(x + 1, res + q[x][i]);
            v[q[x][i]] = 0;
        }
    }
}
int main() {
    biao[0] = 1;
    biao[1] = 1;
    for (int i = 2; i <= 1000; i++) {
        if (!biao[i]) {
            for (int j = 2; j * i <= 1000; j++) {
                biao[j * i] = 1;
            }
            // std::cout << i << " ";
        }
    }
    std::cin >> n;
    for (int i = 1; i <= n; i++) {
        int a;
        scanf("%d", &a);
        for (int j = 2; j <= a; j++) {
            if (biao[j]) continue;
            if (a % j == 0) q[i].push_back(j);
        }
        // for (int j = 0; j < (int)q[i].size(); j++) {
        //     std::cout << q[i][j] << " ";
        // }
        // std::cout << std::endl;
    }
    dfs(1, 0);
    std::cout << (ans == 1e9 ? -1 : ans) << std::endl;
    return 0;
}