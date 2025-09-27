#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <vector>

std::vector<int> l;
long long n;
int main() {
    std::cin >> n;
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        if (i % 2 == 1)
            ans++;
        else if (i % 4 == 0)
            ans++;
    }
    std::cout << ans << std::endl;
    return 0;
}