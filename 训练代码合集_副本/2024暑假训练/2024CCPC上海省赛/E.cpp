#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>

const int N = 40;
int num[N + 2];

int main() {
    int n;
    std::cin >> n;
    std::string c;
    std::cin >> c;
    // std::cout << c.size();
    for (int i = 0; i < n; i++) {
        if (c[i] >= 'A' && c[i] <= 'Z') c[i] -= 'A', c[i] += 'a';
    }
    for (int i = 0; i < n; i++) {
        num[c[i] - 'a' + 1]++;
    }
    // for (int i = 1; i <= 40; i++) {
    //     std::cout << num[i] << std::endl;
    // }
    int ans = std::min(num['h' - 'a' + 1], num[1]);
    ans /= 2;
    ans = std::min(ans, num['n' - 'a' + 1]);
    ans = std::min(ans, num['s' - 'a' + 1]);
    ans = std::min(ans, num['g' - 'a' + 1]);
    ans = std::min(ans, num['i' - 'a' + 1]);
    std::cout << ans << std::endl;
    return 0;
}