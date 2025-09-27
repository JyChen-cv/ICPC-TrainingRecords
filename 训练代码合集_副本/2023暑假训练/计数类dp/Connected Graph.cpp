#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <vector>

typedef long long ll;
const int N = 50;
int n;
ll p_2[N * N + 2], f[N + 2];

ll q_pow(ll x, ll y) {
    if (!y) return 1;
    ll mid = q_pow(x, y >> 1);
    if (y % 2)
        return mid * mid * x;
    else
        return mid * mid;
}

ll C(ll x, ll y) {
    return
}

int main() {
    p_2[0] = 1;
    for (int i = 1; i <= 2000; i++) {
        p_2[i] = p_2[i - 1] * 2;
    }
    for (int i = 1; i <= 50; i++) {
        f[i] = p_2[i * (i - 1) / 2];
        for (int j = 1; j < i; j++) {
            f[i] -= f[j] * C(i - 1, j - 1) * p_2[(i - j) * (i - j - 1) / 2];
        }
    }
    while (std::cin >> n && n) {
    }
    return 0;
}