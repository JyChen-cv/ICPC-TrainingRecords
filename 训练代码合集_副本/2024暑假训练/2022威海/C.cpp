#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <unordered_map>
#include <vector>

using namespace std;

// using ini =long long;
using ini = long long;  // 全局数据类型

const ini eps = 0;
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

std::vector<Point> q;
inline int gcd(int x, int y) {
	if (x < 0) x = -x; if (y < 0) y = -y;
	return y == 0 ? x : gcd(y, x % y);
}

bool check(std::vector<Point> &d) {
	std::sort(d.begin(), d.end());
	int tag = 1;
	std::map<Point, int> mp;
	for (int i = 1; i < (int)d.size(); i++) {
		Point res = d[i] - d[i - 1];
		int ls = gcd(res.x, res.y);
		res.x /= ls, res.y /= ls;
		mp[res]++;
	}
	if (mp.size() > 1) tag = 0;

	if (tag) return 0;
	else {
		for (int i = 0; i < (int)d.size(); i++) {
			mp.clear();
			tag = 1;
			for (int j = 0; j < (int)d.size(); j++) {
				if (i == j) continue;
				else {
					Point res = d[j] - d[i];
					int ls = gcd(res.x, res.y);
					res.x /= ls, res.y /= ls;
					mp[res]++;
				}
			}
			// std::cout << i << std::endl;
			// for (auto j : ls) {
			// 	std::cout << j.x << " " << j.y << std::endl;
			// }
			for (auto j : mp) {
				if (j.second > 1) tag = 0;
			}
			if (tag) {
				std::cout << "YES" << std::endl;
				std::cout << d[i].x << " " << d[i].y << std::endl;
				for (int j = 0; j < (int)d.size(); j++) {
					if (i == j) continue;
					std::cout << d[j].x << " " << d[j].y << std::endl;
				}
				return 1;
			}
		}
		return 0;
	}
}
void solve() {
	int n; std::cin >> n; q.clear(); q.push_back({0, 0});
	for (int i = 1; i <= n; i++) {
		int a, b; std::cin >> a >> b;
		q.push_back((Point) {a, b});
	}
	if (n < 5) {
		std::cout << "NO" << std::endl;
		return ;
	}

	std::vector<Point> due;
	for (int i = 1; i <= 4; i++) due.push_back(q[i]);
	for (int i = 5; i <= n; i++) {
		due.push_back(q[i]);
		if (check(due)) return ;
		due.pop_back();
	}
	std::cout << "NO" << std::endl;
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