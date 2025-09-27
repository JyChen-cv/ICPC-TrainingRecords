#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <vector>
#include <cstdlib>

using namespace std;

const double eps = 1e-8;
const double PI = acos(-1);

struct Point
{
	double x, y;

	Point() = default;
	Point(double x, double y): x(x), y(y) {}

	bool operator==(const Point &a) const {return (abs(x - a.x) <= eps && abs(y - a.y) <= eps);}
	Point operator+(const Point &a) const {return Point(x + a.x, y + a.y);}
	Point operator-(const Point &a) const {return Point(x - a.x, y - a.y);}
	Point operator-() const {return Point(-x, -y);}
	Point operator*(const double &k) const {return Point(k * x, k * y);}
	Point operator/(const double &k) const {return Point(x / k, y / k);}
	double operator*(const Point &a) const {return x * a.x + y * a.y;} //Dot
	double operator^(const Point &a) const {return x * a.y - y * a.x;} //Cross
	bool operator<(const Point &a) const {if (abs(x - a.x) <= eps) return y < a.y - eps; return x < a.x - eps;}
	bool is_par(const Point &a) const {return abs((*this)^a) <= eps;}
	bool is_ver(const Point &a) const {return abs((*this) * a) <= eps;}
	int toleft(const Point &a) const {auto t = (*this)^a; return (t > eps) - (t < -eps);}
	double len() const {return sqrt((*this) * (*this));}
	double dis(const Point &a) const {return (a - (*this)).len();}
	double ang(const Point &a) const {return acos(((*this) * a) / (this->len() * a.len()));}
	Point rot(const double &rad) const {return Point(x * cos(rad) - y * sin(rad), x * sin(rad) + y * cos(rad));}
};

struct Line
{
	Point p, v; //p+tv

	Line() = default;
	Line(Point p, Point v): p(p), v(v) {}

	bool operator==(const Line &a) const {return (v.is_par(a.v) && v.is_par(p - a.p));}
	bool is_par(const Line &a) const {return (v.is_par(a.v) && !v.is_par(p - a.p));}
	bool is_ver(const Line &a) const {return v.is_ver(a.v);}
	bool is_on(const Point &a) const {return v.is_par(a - p);}
	int toleft(const Point &a) const {return v.toleft(a - p);}
	Point inter(const Line &a) const {return p + v * ((a.v ^ (p - a.p)) / (v ^ a.v));}
	double dis(const Point &a) const {return abs(v ^ (a - p)) / v.len();}
	Point proj(const Point &a) const {return p + v * ((v * (a - p)) / (v * v));}
};

struct Polygon
{
	vector<Point> p;

	Polygon() = default;
	Polygon(vector<Point> p): p(move(p)) {}

	inline size_t nxt(const size_t &i) const {return i == p.size() - 1 ? 0 : i + 1;}
	inline size_t pre(const size_t &i) const {return i == 0 ? p.size() - 1 : i - 1;}

	double C() const {
		double sum = 0;
		for (size_t i = 0; i < p.size(); i++) sum += p[i].dis(p[nxt(i)]);
		return sum;
	}

	double S() const {
		double sum = 0;
		for (size_t i = 0; i < p.size(); i++) sum += p[i] ^ p[nxt(i)];
		return abs(sum) / 2;
	}
};

#define back1(x) x.back()
#define back2(x) *(x.rbegin()+1)

Polygon convex(vector<Point> p)
{
	vector<Point> st;
	sort(p.begin(), p.end());
	for (Point u : p)
	{
		while (st.size() > 1 && (back1(st) - back2(st)).toleft(u - back2(st)) <= 0) st.pop_back();
		st.push_back(u);
	}
	size_t k = st.size();
	p.pop_back(); reverse(p.begin(), p.end());
	for (Point u : p)
	{
		while (st.size() > k && (back1(st) - back2(st)).toleft(u - back2(st)) <= 0) st.pop_back();
		st.push_back(u);
	}
	st.pop_back();
	return Polygon(st);
}

int n;
double x, y;

Polygon rotcaliper(Polygon &a)
{
	double ans = LONG_LONG_MAX;
	Polygon ansp;
	for (int i = 0, j = 1, l = -1, r = -1; i < (int)a.p.size(); i++)
	{
		while (((a.p[a.nxt(j)] - a.p[i]) ^ (a.p[a.nxt(j)] - a.p[a.nxt(i)]))
		        > ((a.p[j] - a.p[i]) ^ (a.p[j] - a.p[a.nxt(i)]))) j = a.nxt(j);
		if (l == -1) l = i, r = j;
		Point v(a.p[a.nxt(i)] - a.p[i]);
		v = Point(-v.y, v.x);
		while (v.toleft(a.p[a.nxt(l)] - a.p[l]) <= 0) l = a.nxt(l);
		while (v.toleft(a.p[a.nxt(r)] - a.p[r]) >= 0) r = a.nxt(r);
		Line li(a.p[i], a.p[a.nxt(i)] - a.p[i]), lj(a.p[j], a.p[i] - a.p[a.nxt(i)]);
		Line ll(a.p[l], v), lr(a.p[r], v);
		vector<Point> t = {li.inter(ll), ll.inter(lj), lj.inter(lr), lr.inter(li)};
		Polygon pl(t);
		double s = pl.S();
		if (s < ans) ans = s, ansp = pl;
	}
	return ansp;
}

int main()
{
	scanf("%d", &n);
	vector<Point> v;
	for (int i = 1; i <= n; i++)
	{
		scanf("%lf%lf", &x, &y);
		v.push_back(Point(x, y));
	}
	Polygon c = convex(v);
	auto ans = rotcaliper(c);
	size_t st = 0;
	for (size_t i = 0; i < ans.p.size(); i++)
	{
		if (make_pair(ans.p[i].y, ans.p[i].x) < make_pair(ans.p[st].y, ans.p[st].x)) st = i;
	}
	printf("%.9lf\n", ans.S());
	getchar(); getchar();
	return 0;
}