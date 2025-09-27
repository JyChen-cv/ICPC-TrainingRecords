#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;
#define mp(a,b) make_pair(a,b);
#define pb(x) push_back(x);
typedef long long ll;
typedef double db;
const db eps = 1e-9;
const db pi = acos(-1);
using ini = ll;

int sign(db k) {if (k > eps) {return 1;} else if (k < -eps) {return -1;} else return 0;}
int cmp(db k1, db k2) {return sign(k1 - k2);}
template<typename T>struct point {
	T x, y;
	point<T> operator - (const point<T> &k) {return (point<T>) {x - k.x, y - k.y};}
};
using Point = point<ini>;
db cross(Point k1, Point k2) {return k1.x * k2.y - k1.y * k2.x;}
db dot(Point k1, Point k2) {return k1.x * k2.x + k1.y * k2.y;}
template<typename T>struct line {
	Point p[2];
	Point &operator[](int k) {return p[k];}
	Point dir() {return p[1] - p[0];}
};
using Line = line<ini>;
int toLeft(Point k1, Line k2) {
	return sign(cross(k2.dir(), k1 - k2[0]));
}
const int N = 2e3;
int rem[N + 2], rem2[N + 2];
int n; std::vector<Point> q;
int main() {
	std::ios::sync_with_stdio(0);
	std::cin.tie(0), std::cout.tie(0);
	std::cin >> n;
	q.pb((Point) {0, 0});
	for (int i = 1; i <= n; i++) {
		Point a;
		std::cin >> a.x >> a.y;
		q.pb(a);
	}
	for (int i = 1; i <= n; i++) {
		int nxt = i + 1;
		while (nxt <= n && q[i].y == q[nxt].y) nxt++;
		rem[i] = nxt;
	}
	for (int i = n; i >= 1; i--) {
		int pre = i - 1;
		while (pre >= 1 && q[i].y == q[pre].y) pre--;
		rem2[i] = pre;
	}
	int ans = 0;
	for (int i = 1; i < (int)q.size() && iq; i = rem[i]) {
		if (toLeft(q[rem[i]], Line{q[rem2[i]], q[i]}) == 1) {
			ans++;
		}
	}
	std::cout << ans << std::endl;
	return 0;
}