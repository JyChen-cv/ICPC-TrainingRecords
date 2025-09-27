#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>

const int N = 300000;  // 满足题目要求的情况下，把n上调到一个刚好大于它的2的整数次幂的一个数来方便计算
const double pi = acos(-1);

int n, m, rev[N + 2], bit, tot;
struct complex {
    double x, y;
    complex operator+(const complex t) const {
        return {x + t.x, y + t.y};
    }
    complex operator-(const complex t) const {
        return {x - t.x, y - t.y};
    }
    complex operator*(const complex t) const {
        return {x * t.x - y * t.y, x * t.y + y * t.x};
    }
} a[N + 2], b[N + 2];

void fft(complex a[], int inv) {
    for (int i = 0; i < tot; i++) {
        if (i < rev[i]) std::swap(a[i], a[rev[i]]);  // 相当于把反转的换回去
    }
    for (int mid = 1; mid < tot; mid <<= 1) {
        auto w1 = complex({cos(pi / mid), inv * sin(pi / mid)});
        for (int i = 0; i < tot; i += mid * 2) {
            auto wk = complex({1, 0});
            for (int j = 0; j < mid; j++, wk = wk * w1) {
                auto x = a[i + j], y = wk * a[i + j + mid];
                a[i + j] = x + y, a[i + j + mid] = x - y;
            }
        }
    }
}

int main() {
    std::cin >> n >> m;
    for (int i = 0; i <= n; i++) std::cin >> a[i].x;
    for (int i = 0; i <= m; i++) std::cin >> b[i].x;
    while ((1 << bit) < n + m + 1) bit++;
    tot = 1 << bit;
    for (int i = 0; i < tot; i++) {
        rev[i] = (rev[i >> 1] >> 1) | ((i & 1) << (bit - 1));
    }
    fft(a, 1), fft(b, 1);
    for (int i = 0; i < tot; i++) a[i] = a[i] * b[i];
    fft(a, -1);
    for (int i = 0; i <= n + m; i++)
        printf("%d ", (int)(a[i].x / tot + 0.5));
    return 0;
}