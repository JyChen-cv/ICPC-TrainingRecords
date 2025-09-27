#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <vector>

const int N = 100;
const int mod = 1e9 + 7;
int dp[N + 2][N + 2], ne[N + 2];
char a[N + 2];
int main() {
    int n;
    std::cin >> n;
    std::cin >> (a + 1);
    int m = strlen(a + 1);
    for (int i = 2, j = 0; i <= m; i++) {
        while (j && a[i] != a[j + 1]) j = ne[j];
        if (a[i] == a[j + 1]) j++;
        ne[i] = j;
    }
    // std::vector<int> k[N + 2];
    // for (int i = 1; i <= n; i++) {
    //     k[ne[i]].push_back(i);
    // }
    for (int i = 1; i <= m; i++) std::cout << ne[i] << " ";
    std::cout << std::endl;

    int ans = 0;
    dp[0][0] = 1;
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j < m; j++) {
            // dp[i + 1][ne[i]] += dp[i - 1]
        }
    }
    for (int i = 0; i < m; i++) ans = (ans + dp[n][i]) % mod;
    std::cout << ans << std::endl;
    return 0;
}