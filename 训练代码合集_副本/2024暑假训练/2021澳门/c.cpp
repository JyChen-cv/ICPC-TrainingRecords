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

using ini = ll;  // 设置全局数据类型

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

int toLeft(Point k1, Line k2) {
	// 1->点在线左侧，0->点在线上，-1->点在线右侧
	return sign(cross(k2.dir(), k1 - k2[0]));
}

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

void solve() {
	int n;
	std::cin >> n;
	std::vector<Point> mapp;
	for (int i = 1; i <= n; i++) {
		Point a;
		std::cin >> a.x >> a.y;
		mapp.push_back(a);
	}
	argPointSort1(mapp);
	// for (int i = 0; i < (int)mapp.size(); i++) {
	// 	std::cout << mapp[i].x << " " << mapp[i].y << std::endl;
	// }
	int tag = 0, ans = 1e9;
	Line e = {P0, mapp[0]};
	int cnt = 0, rem = 0;
	while (tag < (int)mapp.size() && toLeft(mapp[tag], e) >= 0) {
		// std::cout << tag << " " << mapp[tag].x << " " << mapp[tag].y << " " << toLeft(mapp[tag], e) << std::endl;
		if (toLeft(mapp[tag], e) == 0) {
			cnt++;
			rem = tag;
		}
		tag++;
	}
	ans = std::min(ans, std::min(tag - cnt, n - tag));
	// std::cout << ans << " " << tag << std::endl;
	for (int i = rem + 1; i < (int)mapp.size(); i = rem) {
		Line ls = {P0, mapp[i]};
		if (toLeft(mapp[0], ls) >= 0) {
			// std::cout << i << std::endl;
			break;
		}
		rem = i, cnt = 0;
		while (rem < (int)mapp.size() && toLeft(mapp[rem], ls) == 0) {
			rem++;
			cnt++;
		}
		while (tag < (int)mapp.size() && toLeft(mapp[tag], ls) >= 0 ) {
			tag++;
		}
		ans = std::min(ans, std::min(tag - i - cnt, n - (tag - i)));
		// std::cout << i << ": " << tag << " " << ans << std::endl;
	}
	std::cout << ans;
}

signed main() {
	std::ios::sync_with_stdio(0);
	std::cin.tie(0), std::cout.tie(0);
	int times = 1;
	std::cin >> times;
	while (times--) {
		solve();
		if (times != 0) std::cout << std::endl;
		// std::cout << toLeft(Point{1, 1}, Line{Point{1, 1}, P0}) << std::endl;
	}
	return 0;
}
