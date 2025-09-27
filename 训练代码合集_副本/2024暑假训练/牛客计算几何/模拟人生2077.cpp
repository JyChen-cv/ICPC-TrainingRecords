#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <vector>

using namespace std;
using ini = long long;
const ini eps = 0;

template <typename T>
struct point {
    T x, y;
    bool operator==(const point &a) const { return (abs(x - a.x) <= eps && abs(y - a.y) <= eps); }
    bool operator<(const point &a) const {
        if (abs(x - a.x) <= eps) return y < a.y - eps;
        return x < a.x - eps;
    }
    point operator+(const point &a) const {
        return {x + a.x, y + a.y};
    }
    point operator-(const point &a) const {
        return {x - a.x, y - a.y};
    }
    point operator-() const { return {-x, -y}; }
    T operator*(const point &a) const {
        return x * a.x + y * a.y;
    }
    T operator^(const point &a) const {
        return x * a.y - y * a.x;
    }
    int toleft(const point &a) const {
        const auto t = (*this) ^ a;
        return (t > eps) - (t < -eps);
    }
};
using Point = point<ini>;
template <typename T>
struct polygon {
    vector<point<T>> p;
    size_t nxt(const size_t i) const { return i == p.size() - 1 ? 0 : i + 1; }
    size_t pre(const size_t i) const { return i == 0 ? p.size() - 1 : i - 1; }
};
using Polygon = polygon<ini>;
template <typename T>
struct convex : polygon<T> {
    T rotcaliper() const {
        const auto &p = this->p;
        if (p.size() <= 2) return 0;
        const auto area = [](const point<T> &u, const point<T> &v, const point<T> &w) {
            return (w - u) ^ (w - v);
        };
        T ans = 0;
        for (size_t i = 0; i < p.size(); i++) {
            T res = 0;
            for (size_t j = 0, k = this->nxt(j); j < p.size(); j++) {  // 这里一定是两个方向都要去枚举，这样才能达到
                if (i == j) continue;
                res = max(area(p[i], p[j], p[k]), res);
                while (area(p[i], p[j], p[this->nxt(k)]) > area(p[i], p[j], p[k])) {
                    k = this->nxt(k);
                    res = max(area(p[i], p[j], p[k]), res);
                }
            }
            ans = std::max(ans, res);
        }
        return ans;
    };
};
using Convex = convex<ini>;

Convex convexhull(vector<Point> p) {
    vector<Point> st;
    if (p.size() < 3) return Convex{p};
    sort(p.begin(), p.end());
    const auto check = [](const vector<Point> &st, const Point &u) {
        const auto back1 = st.back(), back2 = *prev(st.end(), 2);
        return (back1 - back2).toleft(u - back1) <= 0;
    };
    for (const Point &u : p) {
        while (st.size() > 1 && check(st, u)) st.pop_back();
        st.push_back(u);
    }
    size_t k = st.size();
    p.pop_back();
    reverse(p.begin(), p.end());
    for (const Point &u : p) {
        while (st.size() > k && check(st, u)) st.pop_back();
        st.push_back(u);
    }
    st.pop_back();
    return {st};
}
int main() {
    int n;
    std::cin >> n;
    Polygon q;
    for (int i = 1; i <= n; i++) {
        int a;
        std::cin >> a;
        q.p.push_back({a, 0});
    }
    for (int i = 0; i < n; i++) {
        int a;
        std::cin >> a;
        q.p[i].y = a;
    }
    Convex to = convexhull(q.p);
    int ans2 = to.rotcaliper();
    std::cout << ans2 << std::endl;
}