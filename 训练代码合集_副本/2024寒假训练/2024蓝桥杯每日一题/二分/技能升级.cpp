#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>

const int N = 1e5;
typedef long long ll;
#define a first
#define b second
std::pair<ll, ll> mapp[N + 2];
int n, m;

bool check(ll x) {
    int res = 0;
    for (int i = 1; i <= n; i++) {
        if (x >= mapp[i].a) continue;
        ll ls = mapp[i].a - x - 1;
        ls /= mapp[i].b;
        res += ls + 1;
        if (res > m) return 0;
    }
    return 1;
}
ll call(ll x) {
    ll res = 0;
    for (int i = 1; i <= n; i++) {
        if (x > mapp[i].a) continue;
        ll ls = (mapp[i].a - x) / mapp[i].b + 1;
        if ((mapp[i].a - x) % mapp[i].b == 0) ls--;
        res += (mapp[i].a + mapp[i].a - (ls - 1) * mapp[i].b) * (ls) / 2;
        m -= ls;
    }
    return res;
}

int main() {
    std::cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        std::cin >> mapp[i].a >> mapp[i].b;
    }

    ll l = 0, r = 1e6;
    while (l < r) {
        ll mid = (l + r) >> 1;
        if (check(mid) == 0)
            l = mid + 1;
        else
            r = mid;
    }
    // std::cout << l << std::endl;
    std::cout << call(l) + m * l << std::endl;
    return 0;
}