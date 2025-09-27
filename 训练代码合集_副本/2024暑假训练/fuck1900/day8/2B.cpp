// 出现0的话要单独考虑

#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <vector>

#define int long long
const int N = 1e3;
int a[N + 2][N + 2], dp[N + 2][N + 2][2], num[N + 2][N + 2][2];
char rem[N + 2][N + 2][2];

inline int read() {
    int s = 0, w = 1;
    char ch = getchar();
    while (ch < '0' || ch > '9') {
        if (ch == '-') w = -1;
        ch = getchar();
    }
    while (ch >= '0' && ch <= '9') s = s * 10 + ch - '0', ch = getchar();
    return s * w;
}
signed main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0), std::cout.tie(0);
    int n;
    std::cin >> n;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            a[i][j] = read();
            int ls1 = a[i][j], ls2 = a[i][j];
            int num1 = 0, num2 = 0;
            while (ls1 % 2 == 0) {
                num1++, ls1 /= 2;
            }
            while (ls2 % 5 == 0) {
                num2++, ls2 /= 5;
            }
            num[i][j][0] = num1;
            num[i][j][1] = num2;
        }
    }

    for (int i = 0; i <= n; i++)
        for (int k = 0; k <= 1; k++) dp[i][0][k] = dp[0][i][k] = 1e15;
    dp[0][1][0] = dp[0][1][1] = 0;
    for (int k = 0; k <= 1; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (dp[i - 1][j][k] < dp[i][j - 1][k]) {
                    dp[i][j][k] = dp[i - 1][j][k] + num[i][j][k];
                    rem[i][j][k] = 'D';
                } else {
                    dp[i][j][k] = dp[i][j - 1][k] + num[i][j][k];
                    rem[i][j][k] = 'R';
                }
            }
        }
    }

    std::vector<char> ans;
    if (dp[n][n][0] < dp[n][n][1]) {
        int ni = n, nj = n;
        char dir = rem[ni][nj][0];
        while (dir) {
            ans.push_back(dir);
            if (dir == 'D')
                ni--;
            else
                nj--;
            dir = rem[ni][nj][0];
        }
    } else {
        int ni = n, nj = n;
        char dir = rem[ni][nj][1];
        while (dir) {
            ans.push_back(dir);
            if (dir == 'D')
                ni--;
            else
                nj--;
            dir = rem[ni][nj][1];
        }
    }
    std::cout << std::min(dp[n][n][0], dp[n][n][1]) << std::endl;
    for (int i = (int)ans.size() - 2; i >= 0; i--) {
        std::cout << ans[i];
    }
    puts("");
    return 0;
}