#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iostream>

void solve() {
    std::string a;
    std::cin >> a;
    int tag = 0;
    std::cout << a[0];
    for (int i = 1; i < (int)a.size(); i++) {
        if (a[i] == a[i - 1] && !tag) {
            if (a[i] == 'a')
                std::cout << 'b';
            else
                std::cout << 'a';
            tag = 1;
        }
        std::cout << a[i];
    }
    if (!tag) {
        if (a[(int)a.size() - 1] == 'a')
            std::cout << 'b';
        else
            std::cout << 'a';
    }
    std::cout << std::endl;
}

int main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0), std::cout.tie(0);
    int times = 1;
    std::cin >> times;
    while (times--) {
        solve();
    }
    return 0;
}