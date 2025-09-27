#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <map>
#include <vector>

int main() {
    int n;
    std::cin >> n;
    for (int t = 1; t <= n; t++) {
        int a = 0, ans = 0;
        std::cin >> a;
        for (int i = 1; i <= a; i++) {
            int resu = 0;
            std::vector<int> res;
            for (int j = 1; j < i; j++) res.push_back(j * j);
            for (int j = i; j <= a; j++) res.push_back(j * (a + i - j));
            std::sort(res.begin(), res.end());
            for (int j = 0; j < (int)res.size() - 1; j++) resu += res[j];
            ans = std::max(ans, resu);
        }
        std::cout << ans << std::endl;
    }
    return 0;
}