#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <vector>

const int N = 2e5;
int s[N + 2];
int main() {
    int t;
    std::cin >> t;
    while (t--) {
        int n;
        std::cin >> n;
        for (int i = 1; i <= n; i++) s[i] = 0;
        for (int i = 1; i <= n; i++) {
            if (s[i]) continue;
            int l = i;
            while (l <= n) {
                s[l] = 1;
                std::cout << l << " ";
                l *= 2;
            }
        }
        std::cout << std::endl;
    }
    return 0;
}