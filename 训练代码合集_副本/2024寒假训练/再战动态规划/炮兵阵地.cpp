#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>

const int N = 100;
char mapp[N + 2][N + 2];
int main() {
    int n, m;
    std::cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        scanf("%s", mapp[i] + 1);
    }
    return 0;
}