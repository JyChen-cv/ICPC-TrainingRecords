#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <vector>

using namespace std;
// #define fi first
// #define se second
#define mp(a,b) make_pair(a,b)
#define pb(x) push_back(x)
#define P0 (Point) {0,0}
typedef double db;  // 开long double记得改输入输出函数
typedef long long ll;
typedef unsigned long long ull;
const db eps = 1e-9;
const db pi = acos(-1);

using ini = db;  // 设置全局数据类型

int sign(db k) {if (k > eps) { return 1; } else if (k < -eps) { return -1; } else { return 0; }}
int cmp(db k1, db k2) {return sign(k1 - k2);} // 返回 k1 和 k2 的关系

template<typename T = ini>struct point {
	T x, y;
	void scan() {T k1, k2; cin >> k1 >> k2; x = k1, y = k2;}

	void operator = (const point &k) {x = k.x, y = k.y; return;}
	point operator + (const point &k) const {return (point) {x + k.x, y + k.y};}
	point operator - (const point &k) const {return (point) {x - k.x, y - k.y};}
	point operator * (const T &k) const {return (point) {x * k, y * k};}
	point operator / (const T &k) const {return (point) {x / k, y / k};}
	bool operator == (const point &k) const {return cmp(x, k.x) == 0 && cmp(y, k.y) == 0;}
	int operator < (const point k) const {int tmp = cmp(x, k.x); if (tmp == -1) return 1; else if (tmp == 1) return 0; else return cmp(y, k.y) == -1;}

	// 顺时针旋转 目前都是绕原点旋转的，后续可以加一个绕特定点旋转
	point cturn(db k) {return (point) {x*cos(k) + y*sin(k), -x*sin(k) + y*cos(k)};}
	point cturn90() {return (point) {y, -x};}
	// 逆时针旋转
	point acturn(db k) {return (point) {x*cos(k) - y*sin(k), x*sin(k) + y*cos(k)};}
	point acturn90() {return (point) { -y, x};}
	// 返回模长
	T abs() {return sqrt(x * x + y * y);}
	T abs2() {return (x * x + y * y);}
	// 返回单位向量
	point unit() {db w = abs(); return (point) {x / w, y / w};}
	// 返回向量角
	db getw() {return atan2(y, x);}
};
using Point = point<ini>;
db dis(Point k1, Point k2) {return (k1 - k2).abs();} // 返回两个点的欧式距离
db cross(Point k1, Point k2) {return k1.x * k2.y - k1.y * k2.x;}
db dot(Point k1, Point k2) {return k1.x * k2.x + k1.y * k2.y;}

template<typename T = ini>struct line {
	// p0 -> p1
	point<T> p[2];
	void scan() {p[0].scan(); p[1].scan();}

	Point &operator[](int k) {return p[k];}
	bool online(Point k) {return sign(cross(p[1] - p[0], k - p[0])) == 0;}  // 这里应该是 == 0吧？不是>0吧
	Point dir() {return p[1] - p[0];} // 返回方向向量(非单位向量)
	db len() {return dis(p[1], p[0]);}
};
using Line = line<ini>;
bool parallel(Line k1, Line k2) {return sign(cross(k1.dir(), k2.dir())) == 0;}
bool orthogonal(Line k1, Line k2) {return sign(dot(k1.dir(), k2.dir())) == 0;}
bool sameDir(Line k1, Line k2) {return parallel(k1, k2) && sign(dot(k1.dir(), k2.dir())) == 1;}

Point projection(Point k1, Line k2) {
	// 传入点k1和直线k2，输出k1在k2上的投影
	Point d = k2.dir();
	return k2[0] + d * dot(d, k1 - k2[0]) / dot(d, d);
}
Point reflection(Point k1, Line k2) {
	// 传入点k1和直线k2，输出k1关于k2点对称点
	Point tmp = projection(k1, k2);
	return tmp * 2 - k1;
}
int toLeft(Point k1, Line k2) {
	// 1->点在线左侧，0->点在线上，-1->点在线右侧
	return sign(cross(k2.dir(), k1 - k2[0]));
}
bool onSegement(Point k1, Line k2) {
	return sign(cross(k1 - k2[0], k1 - k2[1])) == 0 && sign(dot(k1 - k2[0], k1 - k2[1])) <= 0;
}
bool lineSegIntersectionCheck(Line k1, Line k2) {
	// k1->Line;k2->segement 判断直线和线段相交
	if (parallel(k1, k2)) return 0;
	return toLeft(k2[0], k1) * toLeft(k2[1], k1) <= 0;
}
bool segmentIntersectioncheck(Line k1, Line k2) {
	// 判断两个线段是否相交
	// !主要考虑三点共线和四点共线的情况,需要先特判!
	if (parallel(k1, k2) && projection(k1[0], k2) == k1[0]) {return onSegement(k1[0], k2) || onSegement(k2[0], k1);}
	return toLeft(k1[0], k2) * toLeft(k1[1], k2) <= 0 && toLeft(k2[0], k1) * toLeft(k2[1], k1) <= 0;
}
Point intersection(Line k1, Line k2) {
	// 返回直线/线段的交点,先判断能否相交再求交
	Point u = k1[0] - k2[0];
	db t = cross(k2.dir(), u) / cross(k1.dir(), k2.dir());
	return k1[0] + k1.dir() * t;
}
db segmentDis(Line k1, Line k2) {
	// 返回两个线段之间的最短距离
	if (segmentIntersectioncheck(k1, k2)) return 0;
	db res = (db)1e30; Point tmp;
	tmp = projection(k1[0], k2); if (onSegement(tmp, k2)) res = std::min(res, dis(k1[0], tmp));
	tmp = projection(k1[1], k2); if (onSegement(tmp, k2)) res = std::min(res, dis(k1[1], tmp));
	tmp = projection(k2[0], k1); if (onSegement(tmp, k1)) res = std::min(res, dis(k2[0], tmp));
	tmp = projection(k2[1], k1); if (onSegement(tmp, k1)) res = std::min(res, dis(k2[1], tmp));
	res = std::min(res, dis(k1[0], k2[0]));
	res = std::min(res, dis(k1[1], k2[0]));
	res = std::min(res, dis(k1[0], k2[1]));
	res = std::min(res, dis(k1[1], k2[1]));
	return res;
}

template<typename T = ini>struct polygon {  // 普通多边形，点集// 记得开vector
	vector<point<T>> p;
	void scan(int n) {for (int i = 1; i <= n; i++) {Point k; k.scan(); p.pb(k);};}
	void push(Point k) {p.push_back(k);}
	void pop() {p.pop_back();}
	Point &operator[](int k) {return p[k];}
	void srt() {sort(p.begin(), p.end());}
	int size() {return p.size();}
	int nxt(int k) {return (k + 1) % p.size();}
	int pre(int k) {return (k - 1 + p.size()) % p.size();}
	db area() {
		int num = p.size(); db res = 0;
		for (int i = 1; i + 1 < num; i++) {res += cross(p[i] - p[0], p[i + 1] - p[i]);}
		return res / 2;
	}
	db perimeter() {
		int num = p.size(); db res = 0;
		for (int i = 0; i < num; i++) {res += dis(p[i], p[(i + 1) % num]);}
		return res;
	}
	bool convexCheck() {
		int num = p.size(), tmp = 0;
		for (int i = 0; i < num; i++) {
			if (tmp == 0) tmp = toLeft(p[(i + 1) % num], (Line) {p[(i - 1 + num) % num], p[i]});
			else if (toLeft(p[(i + 1) % num], (Line) {p[(i - 1 + num) % num], p[i]}) *tmp == -1) return 0;
		}
		return 1;
	}
	int pointPos(const Point &k) const {
		// 2->contain; 1->onsegment; 0->otherwise
		int num = p.size(), res = 0;
		for (int i = 0; i < num; i++) {
			if (onSegement(k, (Line) {p[i], p[(i + 1) % num]})) {return 1;}
			db lmin = min(p[i].y, p[(i + 1) % num].y), lmax = max(p[i].y, p[(i + 1) % num].y);
			if (cmp(lmin, k.y) >= 0 || cmp(lmax , k.y) < 0) continue;
			if (toLeft(k, (Line) {p[i], p[(i + 1) % num]}) == 1) res++; else res--;
		}
		return res << 1;
	}
	polygon convexHull()  {
		// 求凸包，返回的结果一定是一个Convex,需要自己转换一下就是了
		sort(p.begin(), p.end());
		polygon res;
		for (int i = 0; i < p.size(); i++) {
			while (res.size() > 1 && toLeft(p[i], (Line) {res[res.size() - 2], res[res.size() - 1]}) <= 0) {res.pop();}
			res.push(p[i]);
		}
		int now = res.size();
		for (int i = p.size() - 2; i >= 0; i--) {
			while (res.size() > now && toLeft(p[i], (Line) {res[res.size() - 2], res[res.size() - 1]}) <= 0) {res.pop();}
			res.push(p[i]);
		}
		res.pop();
		return res;
	}
	// 如下操作只有convex才可以进行
	void rotatingCaliper(const auto &func) {
		if (p.size() == 1) return;
		if (p.size() == 2) {
			func(p[0], p[1], p[1]);
			return;
		}
		auto area = [](const Point & u, const Point & v, const Point & w) {return abs(cross((w - u) , (w - v)));};  // 这个绝对值只要不是自己和自己旋转卡壳就不能省去

		for (int i = 0, j = 0; i < (int)p.size(); i++) {
			int nxti = nxt(i);

			while (area(p[i], p[nxti], p[j]) <= area(p[i], p[nxti], p[nxt(j)])) {
				j = nxt(j);

			}
			func(p[i], p[nxti], p[j]);
		}
	}
	T diameter2() {
		T ans = 0;
		// auto应该是一个地址值
		auto func = [&](const Point & u, const Point & v, const Point & w) {
			ans = max(ans, (w - u).abs2());
			ans = max(ans, (w - v).abs2());
		};
		rotatingCaliper(func);
		return ans;
	}
	// 可以加一个最小矩形覆盖
};
using Polygon = polygon<ini>;

bool cmpA(Point k1, Point k2) {return toLeft(k1, (Line) {P0, k2}) < 0;}
void argPointSort1(vector<Point> &k) {
	// 1e9数据范围请开long double,精度很高，速度一般
	vector<Point> q[5]; int num = k.size();
	for (int i = 0; i < num; i++) {
		if (cmp(k[i].y, 0) < 0) q[0].pb(k[i]);
		else if (cmp(k[i].y, 0) == 0) {
			if (cmp(k[i].x, 0) == 0) q[1].pb(k[i]);
			else if (cmp(k[i].x, 0) > 0) q[2].pb(k[i]);
			else q[4].pb(k[i]);
		} else q[3].pb(k[i]);
	}
	sort(q[0].begin(), q[0].end(), cmpA); sort(q[3].begin(), q[3].end(), cmpA); k.clear();
	for (int i = 0; i <= 4; i++) {num = q[i].size(); for (int j = 0; j < num; j++) k.pb(q[i][j]);}
}

int main() {

	return 0;
}
