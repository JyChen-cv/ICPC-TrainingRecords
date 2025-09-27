#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <map>
#include <queue>
#include <vector>

int main() {
    int t;
    std::cin >> t;
    while (t--) {
        int n;
        std::cin >> n;
        int x = 1;
        while (n % x == 0) x++;
        for (int i = 1; i <= n; i++) printf("%c", 'a' + i % x);
        std::cout << std::endl;
    }
    return 0;
}