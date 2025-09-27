#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>

const int N = 1e5;
std::string a[N + 2];
int main() {
    int n, m, cnt = 0;
    std::cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        std::cin >> a[i];
    }
    int cntt = 0;
    for (int i = 1; i <= n; i++) {
        std::string b;
        std::cin >> b;
        for (int j = 0; j < (int)b.size(); j++) {
            if (b[j] != a[i][j]) cntt++;
        }
    }
    if (std::abs(cnt - cntt) > (m * n) / 2) {
        for (int i = 1; i <= n; i++) {
            for (int j = 0; j < (int)a[i].size(); j++) {
                std::cout << (a[i][j] == 'X' ? '.' : 'X');
            }
            std::cout << std::endl;
        }
    } else {
        for (int i = 1; i <= n; i++) {
            std::cout << a[i] << std::endl;
        }
    }
    return 0;
}

/*
2 4
X..X
X.XX
X.X.
.X..

*/