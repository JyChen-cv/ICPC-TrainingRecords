#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <queue>
#include <vector>
#include <map>

typedef long long ll;
std::map<ll, ll> p;

ll lowbit(ll x) {
    return x & (-x);
}

int main() {
    ll ls = 1;
    p[ls] = 0;
    for (int i = 1; i <= 62; i++) {
        ls *= 2;
        p[ls] = i;
    }

    int t;
    std::cin >> t;
    while (t--) {
        ll n;
        std::cin >> n;
        ll num = 1, m = 0;
        while (num * 2 <= n) {
            num *= 2;
            m++;
        }
        n -= num;
        std::vector<ll> ans;

        while (n) {
            ll l = lowbit(n);
            n -= l;
            l = m - (p[l]);
            ans.push_back(l);
        }
        for (int i = 1; i <= m; i++) ans.push_back(i);
        std::cout << ans.size() << std::endl;
        for (int i = 0; i <= (int)ans.size() - 1; i ++) {
            printf("%lld ", ans[i]);
        }
        std::cout << std::endl;
    }
    return 0;
}