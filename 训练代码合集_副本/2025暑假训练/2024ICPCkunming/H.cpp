#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <vector>
#include <queue>
#include <map>
#include <unordered_map>
#include <cstring>
#include <set>
#include <bitset>

using namespace std;

// using ini =long long;
using ini = long double;  // 全局数据类型

const ini eps = 1e-12;
const ini INF = numeric_limits<ini>::max();
const long double PI = 3.1415926535897932384l;

// 点与向量
template <typename T>
struct point {
	T x, y;

	bool operator==(const point &a) const { return (abs(x - a.x) <= eps && abs(y - a.y) <= eps); }
	bool operator<(const point &a) const {
		if (abs(x - a.x) <= eps) return y < a.y - eps;
		return x < a.x - eps;
	}
	bool operator>(const point &a) const { return !(*this < a || *this == a); }
	point operator+(const point &a) const { return {x + a.x, y + a.y}; }
	point operator-(const point &a) const { return {x - a.x, y - a.y}; }
	point operator-() const { return { -x, -y}; }
	point operator*(const T k) const { return {k * x, k * y}; }
	point operator/(const T k) const { return {x / k, y / k}; }
	T operator*(const point &a) const { return x * a.x + y * a.y; }  // 点积
	T operator^(const point &a) const { return x * a.y - y * a.x; }  // 叉积，注意优先级
	int toleft(const point &a) const {
		const auto t = (*this) ^ a;
		return (t > eps) - (t < -eps);
	}  // to-left 测试
	T len2() const { return (*this) * (*this); }                   // 向量长度的平方
	T dis2(const point &a) const { return (a - (*this)).len2(); }  // 两点距离的平方

	// 涉及浮点数
	long double len() const { return sqrtl(len2()); }                                                                       // 向量长度
	long double dis(const point &a) const { return sqrtl(dis2(a)); }                                                        // 两点距离
	long double ang(const point &a) const { return acosl(max(-1.0l, min(1.0l, ((*this) * a) / (len() * a.len())))); }       // 向量夹角
	point rot(const long double rad) const { return {x * cos(rad) - y * sin(rad), x * sin(rad) + y * cos(rad)}; }           // 逆时针旋转（给定角度）
	point rot(const long double cosr, const long double sinr) const { return {x * cosr - y * sinr, x * sinr + y * cosr}; }  // 逆时针旋转（给定角度的正弦与余弦）
};

using Point = point<ini>;

// 极角排序
struct argcmp {
	bool operator()(const Point &a, const Point &b) const {
		const auto quad = [](const Point & a) {
			if (a.y < -eps) return 1;
			if (a.y > eps) return 4;
			if (a.x < -eps) return 5;
			if (a.x > eps) return 3;
			return 2;
		};
		const int qa = quad(a), qb = quad(b);
		if (qa != qb) return qa < qb;
		const auto t = a ^ b;
		if (abs(t) <= eps) return a * a < b * b - eps; // 不同长度的向量需要分开
		return t > eps;
	}
};

std::vector<Point> q;

inline ini calu(Point x) {
	return PI + atan2(x.y, x.x);
	// if (x.x < -eps && x.y >= -eps) {  // 象限4
	// 	return PI + atan2(x.y, x.x);
	// }
	// else if (x.x < -eps && x.y < -eps) {  // 象限3
	// 	return PI + atan2(x.y, x.x);
	// }
	// else if (x.x >= -eps && x.y < -eps) {  // 象限2
	// 	return PI + atan2(x.y, x.x);
	// }
	// else {
	// 	return PI + atan2(x.y, x.x);
	// }
}

void solve() {
	q.clear();
	int n, k;
	scanf("%d%d", &n, &k);
	for (int i = 1; i <= n; i++) {
		Point a;
		scanf("%Lf%Lf", &a.x, &a.y);
		q.push_back(a);
	}
	std::sort(q.begin(), q.end(), argcmp());
	// for (auto i : q) {
	// 	std::cout << i.x << " " << i.y << std::endl;
	// 	std::cout << calu(i) << std::endl;
	// }
	int s = 0;
	ini ans = 0;
	if (n == k) {
		ans = PI * 2;
		printf("%.8Lf\n", ans);
		return ;
	}
	for (int i = 0; i < n + k; i++) {
		int len = i - s + 1;
		int st = s % n, ed = i % n;
		if (len <= k) continue;
		ini x1 = calu(q[st]);
		ini x2 = calu(q[ed]);
		// std::cout << x1 << " " << q[st].x << " " << q[st].y << std::endl;
		// std::cout << x2 << " " << q[ed].x << " " << q[ed].y << std::endl;
		argcmp cmp;
		if (cmp(q[ed] , q[st])) x2 += 2 * PI;
		// std::cout << x1 << " " << q[st].x << " " << q[st].y << std::endl;
		// std::cout << x2 << " " << q[ed].x << " " << q[ed].y << std::endl;
		ans = std::max(ans , x2 - x1);
		s++;
	}
	printf("%.8Lf\n", ans);
}

signed main() {
	// std::ios::sync_with_stdio(0);
	// std::cin.tie(0), std::cout.tie(0);
	// std::cout << atan2(1, 1) << std::endl;
	// std::cout << atan2(1, -1) << std::endl;
	// std::cout << atan2(-1, 1) << std::endl;
	// std::cout << atan2(-1, -1) << std::endl;
	int times = 1;
	scanf("%d", &times);
	while (times--) {
		solve();
	}
	return 0;
}