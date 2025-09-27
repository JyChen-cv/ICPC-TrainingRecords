#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>

int main() {
    std::string a;
    std::cin >> a;
    int ls = 0, ans = 0;
    for (int i = 0; i < (int)a.size(); i++) {
        if (ls == 0) {
            ls = a[i];
            continue;
        } else {
            if (a[i] == ls || a[i] == '?' || ls == '?') {
                ans++;
                ls = 0;
            } else
                ls = a[i];
        }
    }
    std::cout << ans << std::endl;
    return 0;
}