#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <vector>

using namespace std;
using ini = long long;
using ll = long long;
const ini eps = 0;
const ll mod = 1e9 + 7;

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
    ll dis2(const point &a) const {
        point res = *this - a;
        return res.x * res.x + res.y * res.y;
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
    T rotcaliper(convex &d) const {
        const auto &p = this->p;
        // if (p.size() <= 2) return 0;
        const auto area = [](const point<T> &u, const point<T> &v, const point<T> &w) {
            return (w - u) ^ (w - v);
        };
        T ans = 0;
        for (size_t i = 0, j = 0; i < p.size(); i++) {
            ll res = 1e18;
            const auto nxti = this->nxt(i);
            res = min(res, area(p[i], p[nxti], d.p[j]));
            while (area(p[i], p[nxti], d.p[d.nxt(j)]) < area(p[i], p[nxti], d.p[j])) {
                j = d.nxt(j);
                res = min({res, d.p[j].dis2(p[i]), d.p[j].dis2(p[nxti])});
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

void solve() {
    int m, n;
    Polygon q, p;
    std::cin >> m;
    for (int i = 1; i <= m; i++) {
        int a, b;
        std::cin >> a >> b;
        q.p.push_back({a, b});
    }
    std::cin >> n;
    for (int i = 1; i <= n; i++) {
        int a, b;
        std::cin >> a >> b;
        p.p.push_back({a, b});
    }

    Convex tq = convexhull(q.p), tp = convexhull(p.p);
    int ans = tp.rotcaliper(tq);
    std::cout << ans % mod << std::endl;
}
int main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(nullptr), std::cout.tie(nullptr);
    int times;
    std::cin >> times;
    while (times--) {
        solve();
    }
    return 0;
}