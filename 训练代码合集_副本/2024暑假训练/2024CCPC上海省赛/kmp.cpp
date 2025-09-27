#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>

const int N = 1e5;
int rp[N + 2];
int main() {
    std::string a;
    std::cin >> a;
    int j = -1;
    rp[0] = -1;
    for (int i = 0; i + 1 < (int)a.size(); i++) {
        while (j > -1 && a[j + 1] != a[i + 1]) j = rp[j];
        if (a[j + 1] == a[i + 1]) j++;
        rp[i + 1] = j;
    }
    for (int i = 0; i < (int)a.size(); i++) {
        std::cout << rp[i] << " ";
    }
    std::cout << std::endl;
    return 0;
}