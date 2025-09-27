#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
const double eps = 1e-10;
struct Point {
    double x, y;
    Point operator-(const Point t) const {
        Point res;
        res.x = x - t.x;
        res.y = y - t.y;
        return res;
    }
    Point operator+(const Point t) const {
        Point res;
        res.x = x + t.x;
        res.y = y + t.y;
        return res;
    }
    Point operator*(const double t) const {
        Point res;
        res.x = x * t;
        res.y = y * t;
        return res;
    }
    bool operator==(const Point t) const {
        if (x == t.x && y == t.y) return 1;
        return 0;
    }
    void input() {
        scanf("%lf%lf", &x, &y);
    }
} a, b, c, t;
int sign(double x) {
    if (std::fabs(x) < eps)
        return 0;
    else if (x < 0)
        return -1;
    else
        return 1;
}
int cmp(double x, double y) {
    if (fabs(x - y) < eps) return 0;
    if (x < y) return -1;
    return 1;
}
double dot(Point a, Point b) {
    return a.x * b.x + a.y * b.y;
}
double cross(Point a, Point b) {
    return a.x * b.y - b.x * a.y;
}
bool on_segment(Point p, Point a, Point b) {
    return sign(cross(p - a, p - b)) == 0 && sign(dot(p - a, p - b)) <= 0;
}

void deal(Point &st, Point &ed, int i) {
    if (i == 1) {
        st = a, ed = b;
    } else if (i == 2) {
        st = b, ed = c;
    } else {
        st = c, ed = a;
    }
}

double area(Point x, Point y, Point z) {
    return std::fabs(cross(x, y) + cross(y, z) + cross(z, x)) / 2;
}

int main() {
    // freopen("/Users/chenjiayou/Desktop/Cpp/2019 nanjing regional/data.txt", "r", stdin);
    int tt;
    std::cin >> tt;
    while (tt--) {
        a.input(), b.input(), c.input();
        t.input();
        int tag = 0;
        if (on_segment(t, a, b))
            tag = 1;
        else if (on_segment(t, b, c))
            tag = 2;
        else if (on_segment(t, a, c))
            tag = 3;
        if (!tag) {
            std::cout << -1 << std::endl;
            continue;
        }
        double s = area(a, b, c);
        // std::cout << s << std::endl;
        Point stt, edd;
        deal(stt, edd, tag);

        for (int i = 1; i <= 3; i++) {
            if (tag == i)
                continue;
            else {
                Point st, ed;
                deal(st, ed, i);
                if (st == t || ed == t) continue;
                if (!on_segment(st, stt, edd)) std::swap(st, ed);
                double t1 = 0, t2 = 1;
                while ((t2 - t1) > eps) {
                    double mid = (t1 + t2) / 2;
                    Point ls = st + (ed - st) * mid;
                    // std::cout << ls.x << " " << ls.y << std::endl;
                    double lss = area(ls, st, t);
                    if (lss < s / 2)
                        t1 = mid;
                    else if (lss == s / 2) {
                        t1 = mid;
                        break;
                    } else
                        t2 = mid;
                }
                Point ls = st + (ed - st) * t1;
                if (sign(area(ls, st, t) - s / 2) == 0) {
                    printf("%.7lf %.7lf\n", ls.x, ls.y);
                    break;
                }
            }
        }
    }

    return 0;
}