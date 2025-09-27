#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <vector>

using namespace std;
#define mp(a,b) make_pair(a,b)
#define fi first
#define se second
#define pb(x) push_back(x)
#define P0 (point){0,0}
// 开long double记得改输入输出函数
typedef long double db;

const db eps = 1e-11;
const db pi = acos(-1);

int sign(db k) {if (k > eps) { return 1; } else if (k < -eps) { return -1; } else { return 0; }}
int cmp(db k1, db k2) {return sign(k1 - k2);} // 返回 k1 和 k2 的关系

struct point {
	db x, y;
	point operator + (const point &k) const {return (point) {x + k.x, y + k.y};}
	point operator - (const point &k) const {return (point) {x - k.x, y - k.y};}
	point operator * (const double &k) const {return (point) {x * k, y * k};}
	point operator / (const double &k) const {return (point) {x / k, y / k};}
	bool operator == (const point &k) const {return cmp(x, k.x) == 0 && cmp(y, k.y) == 0;}
	int operator < (const point k) const {
		int tmp = cmp(x, k.x);
		if (tmp == -1) return 1; else if (tmp == 1) return 0; else return cmp(y, k.y) == -1;
	}
	// 顺时针旋转 目前都是绕远点旋转的，后续可以加一个绕特定点旋转
	point cturn(db k) {return (point) {x*cos(k) + y*sin(k), -x*sin(k) + y*cos(k)};}
	point cturn90() {return (point) {y, -x};}
	// 逆时针旋转
	point acturn(db k) {return (point) {x*cos(k) - y*sin(k), x*sin(k) + y*cos(k)};}
	point acturn90() {return (point) { -y, x};}
	// 返回模长
	db abs() {return sqrt(x * x + y * y);}
	db abs2() {return (x * x + y * y);}
	// 返回单位向量
	point unit() {db w = abs(); return (point) {x / w, y / w};}
	void scan() {db k1, k2; scanf("%Lf%Lf", &k1, &k2); x = k1, y = k2;}
	void print() {printf("%.00Lf %.00Lf\n", x, y);}
	// 返回向量角
	db getw() {return atan2(y, x);}
};
db dis(point k1, point k2) {return (k1 - k2).abs();} // 返回两个点的欧式距离
db cross(point k1, point k2) {return k1.x * k2.y - k1.y * k2.x;}
db dot(point k1, point k2) {return k1.x * k2.x + k1.y * k2.y;}

struct line {
	// p0 -> p1
	point p[2];
	void scan() {p[0].scan(); p[1].scan();}
	// 默认初始化，若开始则必须执行
	// line(point k1, point k2) {p[0] = k1, p[1] = k2;}
	point &operator[](int k) {return p[k];}
	bool include(point k) {return sign(cross(p[1] - p[0], k - p[0])) > 0;}
	point dir() {return p[1] - p[0];} // 返回方向向量(非单位向量)
	db len() {return dis(p[1], p[0]);}
};
bool parallel(line k1, line k2) {return sign(cross(k1.dir(), k2.dir())) == 0;}
bool orthogonal(line k1, line k2) {return sign(dot(k1.dir(), k2.dir())) == 0;}
bool sameDir(line k1, line k2) {return parallel(k1, k2) && sign(dot(k1.dir(), k2.dir())) == 1;}

point projection(point k1, line k2) {
	// 传入点k1和直线k2，输出k1在k2上的投影
	point d = k2.dir();
	return k2[0] + d * dot(d, k1 - k2[0]) / dot(d, d);
}
point reflection(point k1, line k2) {
	// 传入点k1和直线k2，输出k1关于k2点对称点
	point tmp = projection(k1, k2);
	return tmp * 2 - k1;
}
int toLeft(point k1, line k2) {
	// 1->点在线左侧，0->点在线上，-1->点在线右侧
	return sign(cross(k2.dir(), k1 - k2[0]));
}
bool onSegement(point k1, line k2) {
	return sign(cross(k1 - k2[0], k1 - k2[1])) == 0 && sign(dot(k1 - k2[0], k1 - k2[1])) <= 0;
}
bool lineSegIntersectionCheck(line k1, line k2) {
	// k1->line;k2->segement 判断直线和线段相交
	if (parallel(k1, k2)) return 0;
	return toLeft(k2[0], k1) * toLeft(k2[1], k1) <= 0;
}
bool segmentIntersectioncheck(line k1, line k2) {
	// 判断两个线段是否相交
	// !主要考虑三点共线和四点共线的情况,需要先特判!
	if (parallel(k1, k2) && projection(k1[0], k2) == k1[0]) {return onSegement(k1[0], k2) || onSegement(k2[0], k1);}
	return toLeft(k1[0], k2) * toLeft(k1[1], k2) <= 0 && toLeft(k2[0], k1) * toLeft(k2[1], k1) <= 0;
}
point intersection(line k1, line k2) {
	// 返回直线/线段的交点,先判断能否相交再求交
	point u = k1[0] - k2[0];
	db t = cross(k2.dir(), u) / cross(k1.dir(), k2.dir());
	return k1[0] + k1.dir() * t;
}
db segmentDis(line k1, line k2) {
	// 返回两个线段之间的最短距离
	if (segmentIntersectioncheck(k1, k2)) return 0;
	db res = (db)1e30; point tmp;
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

struct polygon {
	// 记得开vector
	vector<point> p;
	void scan(int n) {for (int i = 1; i <= n; i++) {point k; k.scan(); p.pb(k);};}
	point &operator[](int k) {return p[k];}
	int size() {return p.size();}
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
			if (tmp == 0) tmp = toLeft(p[(i + 1) % num], (line) {p[(i - 1 + num) % num], p[i]});
			else if (toLeft(p[(i + 1) % num], (line) {p[(i - 1 + num) % num], p[i]}) *tmp == -1) return 0;
		}
		return 1;
	}
};

int pointPolygonPosCheck(point k1, polygon k2) {
	// 2->contain;1->onsegment;0->otherwise
	int num = k2.size(), res = 0;
	for (int i = 0; i < num; i++) {
		if (onSegement(k1, (line) {k2[i], k2[(i + 1) % num]})) {return 1;}
		db lmin = min(k2[i].y, k2[(i + 1) % num].y), lmax = max(k2[i].y, k2[(i + 1) % num].y);
		if (cmp(lmin, k1.y) >= 0 || cmp(lmax , k1.y) < 0) continue;
		if (toLeft(k1, (line) {k2[i], k2[(i + 1) % num]}) == 1) res++; else res--;
	}
	return res << 1;
}

bool cmpA(point k1, point k2) {return toLeft(k1, (line) {P0, k2}) < 0;}
void argPointSort1(vector<point> &k) {
	// 1e9数据范围请开long double
	vector<point> q[5]; int num = k.size();
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

vector<point> mapp;

int main() {
	int n;
	cin >> n;
	while (n--) {
		point p;
		p.scan();
		mapp.pb(p);
	}
	argPointSort1(mapp);
	for (int i = 0; i < (int)mapp.size(); i++) mapp[i].print();
	return 0;
}