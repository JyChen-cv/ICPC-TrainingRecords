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
    for (int i = 1; i <= 2000; i++) {
        for (int j = 1; j < n; j++) {
            mapp[j] /= 2;
            mapp[j + 1] += mapp[j];
        }
        mapp[n] /= 2;
        mapp[1] += mapp[n];
    }
    for (int i = 1; i <= n; i++) {
        std::cout << mapp[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}