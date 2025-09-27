#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>

using namespace std;
const double eps = 1e-9;
const double pi = acos(-1);

int sign(double x) {
    if (std::abs(x) < eps)
        return 0;
    else if (x < 0)
        return -1;
    else
        return 1;
}

struct point {
    double x, y;
    point() {
        x = eps;
        y = eps;
    }
    void input() {
        std::cin >> x >> y;
        if (x < eps) x = eps;
        if (y < eps) y = eps;
    }
    void output() {
        printf("%.8lf %.8lf ", x, y);
    }
    point operator-(point z) {
        point res;
        res.x = x - z.x;
        res.y = y - z.y;
        return res;
    }
    point operator+(point z) {
        point res;
        res.x = x + z.x;
        res.y = y + z.y;
        return res;
    }
} yuan, t;
double r, s;

double dis(point x) {
    double l1 = x.x;
    double l2 = x.y;
    double res = sqrt(l1 * l1 + l2 * l2);
    if (res < eps)
        return eps;
    else
        return res;
}
double dis(point x, point y) {
    double l1 = x.x - y.x;
    double l2 = x.y - y.y;
    return sqrt(l1 * l1 + l2 * l2);
}

point zhuan(point x, double ct) {
    point res;
    res.x = cos(ct) * x.x - sin(ct) * x.y;
    res.y = sin(ct) * x.x + cos(ct) * x.y;
    return res;
}

double cross(point x, point y) {
    return x.x * y.x + x.y * y.y;
}

int main() {
    std::cin >> r;
    yuan.input();
    std::cin >> s;
    t.input();

    t = t - yuan;
    if (sign(dis(t) - r / 2) == 0 || sign(dis(t) - r / 2) > 0) {  // 不影响最大值
        // std::cout << dis(t) << std::endl;
        double sum = r * r * 3 * sqrt(3) / 4;
        if (sign(sum - s) < 0) {
            std::cout << -1 << std::endl;
            return 0;
        }

        point a1, a2, a3;
        a1.y = (-1) * t.y * r / dis(t);
        a1.x = (-1) * t.x * r / dis(t);
        a2 = zhuan(a1, pi * 2 / 3);
        a3 = zhuan(a2, pi * 2 / 3);
        a1 = a1 + yuan, a2 = a2 + yuan, a3 = a3 + yuan;
        a1.output(), a2.output(), a3.output();
        puts("");
    } else {  // 影响最大值
        point a1, a2, a3;
        a1.y = (-1) * t.y * r / dis(t);
        a1.x = (-1) * t.x * r / dis(t);
        double rr = sqrt(r * r - (t.x * t.x + t.y * t.y));
        point dx;
        dx.x = rr * t.y / dis(t);
        dx.y = rr * t.x / dis(t);
        a2 = a1 - dx;
        a3 = a1 + dx;
        // a1.output(), a2.output(), a3.output();
        double sum = std::fabs(cross(a1, a2) + cross(a2, a3) + cross(a3, a1));
        // std::cout << sum << std::endl;
        if (sign(sum - s) < 0) {
            std::cout << -1 << std::endl;
            return 0;
        }

        a1 = a1 + yuan, a2 = a2 + yuan, a3 = a3 + yuan;
        a1.output(), a2.output(), a3.output();
        puts("");
        // std::cout << dis(t) << std::endl;
    }

    return 0;
}

/*
3 0 0 2 1.73205 1
*/