#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>

#define x first
#define y second
const int N = 1e5;
double mapp[N + 2], dp[N + 2][2];
std::pair<double, double> chuan[N + 2];

double to(double x, double y) {
    if (x > y)
        return (x - y) / 1.3;
    else
        return (y - x) / 0.7;
}

int main() {
    int n;
    std::cin >> n;
    for (int i = 1; i <= n; i++) {
        std::cin >> mapp[i];
    }
    for (int i = 2; i <= n; i++) {
        std::cin >> chuan[i].x >> chuan[i].y;
    }

    dp[1][0] = mapp[1], dp[1][1] = 1e9;
    for (int i = 2; i <= n; i++) {
        dp[i][0] = std::min(dp[i - 1][0] + mapp[i] - mapp[i - 1], std::min(dp[i - 1][0] + to(0, chuan[i].x), dp[i - 1][1] + to(chuan[i - 1].y, chuan[i].x)) + chuan[i].y / 1.3);
        dp[i][1] = std::min(std::min(dp[i - 1][0] + to(0, chuan[i].x), dp[i - 1][1] + to(chuan[i - 1].y, chuan[i].x)), dp[i][0] + chuan[i].y / 0.7);
        // std::cout << dp[i][0] << " " << dp[i][1] << std::endl;
    }
    printf("%.2lf\n", dp[n][0]);
    return 0;
}