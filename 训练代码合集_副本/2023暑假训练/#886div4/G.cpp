#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <map>

std::map<long long, long long> h, v, l, r;
int main() {
    int t;
    std::cin >> t;
    while (t--) {
        h.clear();
        v.clear();
        l.clear();
        r.clear();
        int n;
        std::cin >> n;
        for (int i = 1; i <= n; i++) {
            int x, y;
            std::cin >> x >> y;
            h[x]++;
            v[y]++;
            l[x + y]++;
            r[x - y]++;
        }
        long long ans = 0;
        for (auto i = h.begin(); i != h.end(); i++) {
            ans += i->second * (i->second - 1);
        }
        for (auto i = v.begin(); i != v.end(); i++) {
            ans += i->second * (i->second - 1);
        }
        for (auto i = l.begin(); i != l.end(); i++) {
            ans += i->second * (i->second - 1);
        }
        for (auto i = r.begin(); i != r.end(); i++) {
            ans += i->second * (i->second - 1);
        }
        std::cout << ans << std::endl;
    }
    return 0;
}