#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>

const int N = 3000;
int a[N + 2], b[N + 2], f[N + 2][N + 2];  // 集合: 所有由第一个序列的前i个字母，和第二个序列的前j个字母构成的，且以b[j]为结尾的公共上升子序列的合集
                                          // 性质: 最大值
int tag[N + 2], res[N + 2];

int main() {
    int n;
    std::cin >> n;
    for (int i = 1; i <= n; i++) std::cin >> a[i];
    for (int i = 1; i <= n; i++) std::cin >> b[i];

    // case2:优化版本，时间复杂度O(n^2)
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (tag[j] == 0) tag[j] = 1;
            if (a[i] == b[j]) {
                f[i][j] = std::max(f[i][j], 1);
                for (int k = tag[j]; k < i; k++) {
                    if (a[k] < a[i]) res[j] = std::max(res[j], f[k][j - 1] + 1);
                }
                tag[j] = i;
                f[i][j] = std::max(f[i][j], res[j]);
            } else
                f[i][j] = f[i][j - 1];
        }
        // std::cout << f[i][n] << " ";
        ans = std::max(ans, f[i][n]);
    }

    // 输出
    std::cout << ans << std::endl;
    return 0;
}
