#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>

double mapp[100005];
int main() {
    int n;
    std::cin >> n;
    double al = 0;
    for (int i = 1; i <= n; i++) {
        std::cin >> mapp[i];
        al += mapp[i];
    }
    printf("%.7lf ", (al * 2) / (n + 1));
    for (int i = 2; i <= n; i++) {
        printf("%.7lf ", al / (n + 1));
    }
    std::cout << std::endl;

    return 0;
}