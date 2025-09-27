#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <vector>

#define int long long
typedef long long ll;
const int N = 5e5;

bool v[N + 2];
int cnt;
std::vector<ll> pri, par, num;
ll x, xb, y, yb;

ll gcd(ll a, ll b) {
    return b ? gcd(b, a % b) : a;
}

void dfs(ll xx, int tag) {
    if (tag == (int)par.size()) {
        // std::cout << xx << " " << par[0] << " " << par[1] << " " << par[2] << std::endl;
        ll ls1 = gcd(xx, x), ls2 = gcd(xx, y);
        if (xb == ls1 && xx * y == yb * ls2) cnt++;
        return;
    }
    ll lss = 1;
    for (int j = 0; j <= num[tag]; j++) {
        dfs(xx / lss, tag + 1);
        lss *= par[tag];
    }
}

signed main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);
    // std::cout.tie(0);
    for (int i = 2; i <= 450000; i++) {
        if (v[i] == 0) {
            pri.push_back(i);
            for (int j = 2; j * i <= 450000; j++) {
                v[j * i] = 1;
            }
        }
    }
    int t;
    std::cin >> t;
    while (t--) {
        std::cin >> x >> xb >> y >> yb;
        // x = 28805;
        // xb = 1;
        // y = 4;
        // yb = 100029072;
        // x = 41;
        // xb = 1;
        // y = 96;
        // yb = 288;
        cnt = 0;
        par.clear();
        num.clear();
        ll yy = yb;
        for (int i = 0; i < (int)pri.size(); i++) {
            ll res = 0;
            while (yy % pri[i] == 0) {
                res++;
                yy /= pri[i];
            }
            if (res) {
                par.push_back(pri[i]);
                num.push_back(res);
            }
        }
        if (yy != 1) par.push_back(yy);
        num.push_back(1);
        dfs(yb, 0);
        std::cout << cnt << std::endl;
    }
    return 0;
}