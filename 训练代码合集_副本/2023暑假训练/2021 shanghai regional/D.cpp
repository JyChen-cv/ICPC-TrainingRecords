#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <vector>

const int N = 5000;
bool ta[N + 2];
typedef long long ll;
std::vector<ll> zhi;

ll gcd(ll x, ll y) {
    return y ? gcd(y, x % y) : x;
}

int main() {
    for (int i = 2; i * i <= 1e7; i++) {
        if (!ta[i]) {
            zhi.push_back(i);
            for (int j = 2; j * i <= 4e3; j++) ta[j * i] = 1;
        }
    }
    // for (int i = 0; i < (int)zhi.size(); i++) {
    //     std::cout << zhi[i] << " ";
    // }
    // std::cout << zhi.size() << std::endl;

    int t;
    std::cin >> t;
    while (t--) {
        ll a, b;
        bool tt = 1;
        std::cin >> a >> b;
        ll ls = gcd(a, b);
        a /= ls;
        b /= ls;
        ll aa = a + 2 * b;
        ll bb = a - 2 * b;
        if (bb < 0) {
            std::cout << 0 << " " << 0 << std::endl;
            continue;
        }
        // std::cout << aa << " " << bb << std::endl;

        ll k = 1;
        for (int i = 0; i < (int)zhi.size(); i++) {
            int tag = 0, tag2 = 0;
            if (aa < zhi[i]) break;
            while (aa % zhi[i] == 0 && aa) {
                aa /= zhi[i];
                tag++;
            }
            while (bb % zhi[i] == 0 && bb) {
                bb /= zhi[i];
                tag2++;
            }
            // std::cout << aa << " " << bb << std::endl;
            if (std::abs(tag - tag2) % 2) tt = 0;
            if (tag % 2) k *= zhi[i];
        }
        if (tt)
            // std::cout << (sqrt((a + 2 * b) / k) + sqrt((a - 2 * b) / k)) / 2 << " " << (sqrt((a + 2 * b) / k) - sqrt((a - 2 * b) / k)) / 2 << std::endl;
            std::cout << (sqrt((a + 2 * b) * k) + sqrt((a - 2 * b) * k)) / 2 << " " << (sqrt((a + 2 * b) * k) - sqrt((a - 2 * b) * k)) / 2 << std::endl;
        else
            std::cout << 0 << " " << 0 << std::endl;
    }
    return 0;
}