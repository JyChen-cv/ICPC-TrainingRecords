#include <cmath>
#include <cstring>
#include <iostream>
#include <unordered_map>

struct pro {
    std::string a;
    double ave, p;
    bool operator<(const pro &t) const {
        return ave < t.ave;
    }
} peo[102];
std::unordered_map<std::string, std::pair<double, double>> q;
signed main() {
    freopen("/Users/chenjiayou/Downloads/1.in", "r", stdin);
    for (int i = 1; i <= 93; i++) {
        double a, b, c;
        std::string x;
        std::cin >> a >> x >> b >> c;
        // std::cout << a << " " << x << " " << b << " " << c << std::endl;
        q[x].first += b * c;
        q[x].second += b;
    }
    for (int i = 1; i <= 94; i++) {
        double a, b, c;
        std::string x;
        std::cin >> a >> x >> b >> c;
        // std::cout << a << " " << x << " " << b << " " << c << std::endl;
        q[x].first += b * c;
        q[x].second += b;
    }
    int tot = 0;
    for (auto i : q) {
        tot++;
        peo[tot].a = i.first;
        // std::cout << i.second.first << std::endl;
        peo[tot].ave = i.second.first / i.second.second;
    }
    std::sort(peo + 1, peo + tot + 1);
    freopen("/Users/chenjiayou/Downloads/res.txt", "w", stdout);
    for (int i = 1; i <= tot; i++) {
        std::cout << peo[i].a << " " << peo[i].ave << std::endl;
    }
}