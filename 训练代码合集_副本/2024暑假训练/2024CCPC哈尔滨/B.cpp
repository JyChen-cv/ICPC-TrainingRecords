#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <set>
#include <vector>

using namespace std;

using ini = long long;

const ini eps = 0;

template <typename T>
struct point {
	T x, y;
	bool operator==(const point &a) const {
		return (std::abs(x - a.x) <= eps && abs(y - a.y) <= eps);
	};
	point operator-(const point &a) const { return {x - a.x, y - a.y}; }
	bool operator<(const point &a) const {
		if (abs(x - a.x) <= eps) return y < a.y - eps;
		return x < a.x - eps;
	}
	T operator*(const point &a) const { return x * a.x + y * a.y; }  // 点积
	T operator^(const point &a) const { return x * a.y - y * a.x; }  // 叉积，注意优先级
	int toleft(const point &a) const {
		const auto t = (*this) ^ a;
		return (t > eps) - (t < -eps);
	}
};
using Point = point<ini>;

template <typename T>
struct line {
	point<T> p, v;

	int toleft(const point<T> &a) const { return v.toleft(a - p); }
};
using Line = line<ini>;

template <typename T>
struct polygon {
	vector<point<T>> p;
	size_t nxt(const size_t i) const { return i == p.size() - 1 ? 0 : i + 1; }
	size_t pre(const size_t i) const { return i == 0 ? p.size() - 1 : i - 1; }
	T area() const {
		T sum = 0;
		for (size_t i = 0; i < p.size(); i++) sum += p[i] ^ p[nxt(i)];
		return sum;
	};
};
using Polygon = polygon<ini>;

template <typename T>
struct convex : polygon<T> {
	T rotcaliper(const convex<T> &q) const {
		const auto &p = this->p;

		const auto area = [](const point<T> &a, const point<T> &b, const point<T> &c) {
			return (b - a) ^ (c - a);
		};
		T ans = 2e18;
		for (size_t i = 0, j = 0; i < p.size(); i++) {
			const auto nxti = this->nxt(i);
			ans = min(ans, area(p[i], p[nxti], q.p[j]));
			while (area(p[i], p[nxti], q.p[q.nxt(j)]) < area(p[i], p[nxti], q.p[j])) {
				j = q.nxt(j);
				ans = min(ans, area(p[i], p[nxti], q.p[j]));
			}
		}
		return ans;
	};
};
using Convex = convex<ini>;

Convex convexhull(vector<Point> &p) {
	vector<Point> st;
	if (p.size() <= 2) return Convex{p};
	sort(p.begin(), p.end());
	const auto check = [](const vector<Point> &st, const Point & u) {
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
	return Convex{st};
}

void solve() {
	// freopen("/Users/chenjiayou/Desktop/2024暑假训练/2024哈尔滨/okok.in", "r", stdin);
	int n;
	Polygon q;
	std::cin >> n;
	for (int i = 1; i <= n; i++) {
		Point a;
		std::cin >> a.x >> a.y;
		q.p.push_back(a);
	}
	auto res = convexhull(q.p);
	sort(res.p.begin(), res.p.end());
	sort(q.p.begin(), q.p.end());
	vector<Point> qd;
	size_t poi = 0;
	for (int i = 0; i < (int)q.p.size(); i++) {
		if (poi < res.p.size() && res.p[poi] == q.p[i]) {
			poi++;
			continue;
		}
		qd.push_back(q.p[i]);
	}
	auto res2 = convexhull(qd);
	res = convexhull(res.p);
	ini ans = res.area();
	// std::cout << ans << std::endl;
	if (res2.p.size() == 0) {
		std::cout << -1 << std::endl;
		return;
	}
	ini d = 0;
	d = res.rotcaliper(res2);
	std::cout << ans - d << '\n';
}

int main() {
	std::ios::sync_with_stdio(0);
	std::cin.tie(0), std::cout.tie(0);
	int times;
	std::cin >> times;
	while (times--) {
		solve();
	}
	return 0;
}