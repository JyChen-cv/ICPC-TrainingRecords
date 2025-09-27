#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <vector>

#define int long long
const int N = 10000;
std::vector<int> nod[N + 2];
int w[N + 2], rem[N + 2], root, dp[N + 2][3];

void dfs(int x) {
    dp[x][0] = w[x];
    for (int i = 0; i < (int)nod[x].size(); i++) {
        int son = nod[x][i];

        dfs(son);
        dp[x][2] += dp[son][1];
        dp[x][0] += std::min(std::min(dp[son][0], dp[son][1]), dp[son][2]);
    }

    int tag = 0, res = 1e9;
    for (int i = 0; i < (int)nod[x].size(); i++) {
        int son = nod[x][i];
        if (dp[son][0] <= dp[son][1]) {
            tag = 1;
            dp[x][1] += dp[son][0];
        } else {
            dp[x][1] += dp[son][1];
            res = std::min(res, dp[son][0] - dp[son][1]);
        }
        // dp[x][1]=std::min(dp[x][1],dp[son][2]+dp[x][0]-std::min(dp[son][1],dp[son][2]));
    }
    if (!tag) dp[x][1] += res;
    // std::cout << x << std::endl;
    // std::cout << dp[x][0] << " " << dp[x][1] << " " << dp[x][2] << std::endl;
}

signed main() {
    int n;
    std::cin >> n;
    for (int i = 1; i <= n; i++) {
        int ls, num, lss;
        std::cin >> ls >> w[ls] >> num;
        for (int j = 1; j <= num; j++) {
            std::cin >> lss;
            rem[lss] = 1;
            nod[ls].push_back(lss);
        }
    }

    for (int i = 1; i <= n; i++) {
        if (rem[i] == 0) {
            root = i;
        }
    }
    dfs(root);
    std::cout << std::min(dp[root][0], dp[root][1]) << std::endl;
    return 0;
}

// 这道题目被特例卡住了，这也警醒我，确实平时思考特例太少了。。。要多加思考，acm赛制。。。特例出现就是暴毙。。