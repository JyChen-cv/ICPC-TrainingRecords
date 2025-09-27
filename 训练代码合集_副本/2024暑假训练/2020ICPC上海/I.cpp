#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>

const int N = 500;
#define double long double
double dis[N + 2][N * 2 + 2];
const double pi = acos(-1);
// const double st = 360 / acos(-1);

int main() {
    int n, m;
    std::cin >> n >> m;
    m *= 2;
    // std::cout << st << std::endl;
    double ans = 0;
    for (int i = 1; i <= n; i++) {
        double sum = 0;
        for (int j = 1; j <= m; j++) {
            dis[0][j] = i * m;
        }
        for (int j = 1; j <= i; j++) {
            for (int k = 1; k <= m; k++) {
                dis[j][k] = dis[j - 1][k] + m;
            }
            dis[j][1] = (i - j) * m;
            for (int k = 1; k <= m; k++) {
                int juedui = std::min(k - 1, m + 1 - k);
                // std::cout << k << " " << deg * juedui << " " << m << " " << juedui << std::endl;
                if (pi * juedui > m) {  // 一定从内部走时最优秀的
                    continue;
                }
                dis[j][k] = dis[j][1] + juedui * j * 2 * pi;
            }
        }
        for (int j = 1; j < i; j++) {
            for (int k = 1; k <= m; k++) {
                sum += dis[j][k];
            }
        }
        // sum *= m;
        if (m != 2) sum += dis[0][1];  // 统计原点
        for (int j = 1; j <= m; j++) {
            sum += dis[i][j] / 2;
        }
        ans += sum;
        // for (int j = 1; j <= i; j++) {
        //     for (int k = 1; k <= m; k++) {
        //         std::cout << dis[j][k] << " ";
        //     }
        //     std::cout << std::endl;
        // }
        // std::cout << std::endl;
    }
    printf("%.10Lf\n", ans);
    return 0;
}