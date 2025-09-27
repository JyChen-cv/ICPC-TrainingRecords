#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <vector>

#define x first
#define y second
typedef long long ll;
const int N = 2000, M = 2e5;
const ll mod = 1e9 + 7;
std::pair<ll, ll> a[N + 2];
ll pc[M + 2], pc_inv[M + 2], f[N + 2];
int n, m, num;

ll q_pow(ll x, ll y) {
    if (!y) return 1;
    ll mid = q_pow(x, y >> 1);
    if (y % 2)
        return mid * mid % mod * x % mod;
    else
        return mid * mid % mod;
}

ll C(ll x, ll y) {
    return pc[x] * pc_inv[y] % mod * pc_inv[x - y] % mod;
}

int main() {
    pc[0] = 1;
    pc_inv[0] = 1;
    for (int i = 1; i <= 200000; i++) {
        pc[i] = pc[i - 1] * i % mod;
        pc_inv[i] = q_pow(pc[i], mod - 2);
    }
    std::cin >> n >> m >> num;
    for (int i = 1; i <= num; i++) {
        std::cin >> a[i].x >> a[i].y;
    }
    num++;
    a[num].x = n, a[num].y = m;
    std::sort(a + 1, a + num + 1);
    for (int i = 1; i <= num; i++) {
        ll ls = 0;
        for (int j = 1; j < i; j++) {
            if (a[j].x > a[i].x || a[j].y > a[i].y) continue;
            ls += f[j] * C(a[i].x - a[j].x + a[i].y - a[j].y, a[i].x - a[j].x);
            ls %= mod;
        }
        f[i] = ((C(a[i].x + a[i].y - 1 - 1, a[i].x - 1) - ls) + mod) % mod;
    }
    std::cout << f[num] << std::endl;
    return 0;
}