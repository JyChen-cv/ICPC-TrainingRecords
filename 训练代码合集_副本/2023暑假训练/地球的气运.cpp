#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <vector>

int main() {
    int a, sum = 0, tag = 0, now = 0;
    for (int i = 1; i <= 12; i++) {
        now += 300;
        std::cin >> a;
        if (now < a && !tag) {
            tag = i;
        } else {
            now -= a;
            sum += now / 100 * 100;
            now %= 100;
        }
    }
    if (tag) {
        std::cout << -tag << std::endl;
    } else
        std::cout << sum / 5 * 6 + now << std::endl;
    return 0;
}