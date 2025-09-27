#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>

int main() {
    int t;
    std::cin >> t;
    while (t--) {
        int n;
        std::cin >> n;
        std::string a, b;
        std::cin >> a >> b;
        int s_A = 0, s_B = 0, s = 0;
        for (int i = 0; i < n; i++) {
            if (a[i] == b[i])
                continue;
            else if (a[i] == '1')
                s_A++;
            else
                s_B++;
        }
        std::cout << std::max(s_A, s_B) << std::endl;
    }
    return 0;
}