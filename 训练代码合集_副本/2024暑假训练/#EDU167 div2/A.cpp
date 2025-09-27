#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <vector>

int main() {
    int n, tag = 0;
    std::cin >> n;
    for (int i = 1; i <= n; i++) {
        tag = 0;
        int a, b;
        std::cin >> a >> b;
        if (b >= -1) tag = 1;
        std::cout << (tag == 1 ? "YES" : "NO") << std::endl;
    }
    return 0;
}