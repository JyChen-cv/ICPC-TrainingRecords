#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>

typedef long long ll;
void deal(int x, int dir[]) {
    if (x == 1) {
        std::swap(dir[2], dir[4]);
    } else if (x == 3)
        std::swap(dir[1], dir[3]);
}

void deal2(int x, ll &x1, ll &x2, ll &y1, ll &y2) {
    ll mid = (x2 - x1 + 1) >> 1;
    if (x == 1) {
        x2 -= mid;
        y2 -= mid;
    } else if (x == 2) {
        x2 -= mid;
        y1 += mid;
    } else if (x == 3) {
        x1 += mid;
        y2 -= mid;
    } else {
        x1 += mid;
        y1 += mid;
    }
}

std::pair<ll, ll> dfs(ll l, ll r, ll p, int dir[], ll x1, ll x2, ll y1, ll y2) {
    std::cout << l << " " << r << " " << p << " " << x1 << " " << x2 << " " << y1 << " " << y2 << " " << dir[1] << " " << dir[2] << " " << dir[3] << " " << dir[4] << std::endl;
    if (r == l) {
        return std::make_pair(x1, y1);
    }

    ll mid = (l + r) >> 1, midl = (l + mid) >> 1, midr = (mid + 1 + r) >> 1;
    int res;
    if (p <= midl) {
        res = dir[1];
        deal2(res, x1, x2, y1, y2);
        deal(res, dir);
        return dfs(l, midl, p, dir, x1, x2, y1, y2);
    } else if (p <= mid) {
        res = dir[2];
        deal2(res, x1, x2, y1, y2);
        deal(res, dir);
        return dfs(midl + 1, mid, p, dir, x1, x2, y1, y2);
    } else if (p <= midr) {
        res = dir[3];
        deal2(res, x1, x2, y1, y2);
        deal(res, dir);
        return dfs(mid + 1, midr, p, dir, x1, x2, y1, y2);
    } else {
        res = dir[4];
        deal2(res, x1, x2, y1, y2);
        deal(res, dir);
        return dfs(midr + 1, r, p, dir, x1, x2, y1, y2);
    }
}

ll dis(ll x1, ll x2, ll y1, ll y2) {
    return sqrt((x2 - x1) * (x2 - x1) * 100 + (y2 - y1) * (y2 - y1) * 100) + 0.5;
}

int main() {
    int t;
    std::cin >> t;
    while (t--) {
        ll n, a, b;
        std::cin >> n >> a >> b;
        int ini[5];
        ini[1] = 1;
        ini[2] = 2;
        ini[3] = 4;
        ini[4] = 3;
        std::pair<ll, ll> x, y;
        x = dfs(1ll, 1ll << (n * 2), a, ini, 1ll, 1ll << (n), 1ll, 1ll << (n));
        ini[1] = 1;
        ini[2] = 2;
        ini[3] = 4;
        ini[4] = 3;
        y = dfs(1ll, 1ll << (n * 2), b, ini, 1ll, 1ll << (n), 1ll, 1ll << (n));
        std::cout << x.first << " " << x.second << std::endl;
        std::cout << y.first << " " << y.second << std::endl;
        ll ans = dis(x.first, y.first, x.second, y.second);
        std::cout << ans << std::endl;
    }
    return 0;
}