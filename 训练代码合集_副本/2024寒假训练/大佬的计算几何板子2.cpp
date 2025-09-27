#include <bits/stdc++.h>
using namespace std;

using _T=long long; // 全局数据类型，可修改为 long long 等

constexpr _T eps=0;
constexpr long double PI=3.1415926535897932384l;

// 点与向量
template<typename T> struct point
{
    T x,y;

    bool operator==(const point &a) const {return (abs(x-a.x)<=eps && abs(y-a.y)<=eps);}
    bool operator<(const point &a) const {if (abs(x-a.x)<=eps) return y<a.y-eps; return x<a.x-eps;}
    bool operator>(const point &a) const {return !(*this<a || *this==a);}
    point operator+(const point &a) const {return {x+a.x,y+a.y};}
    point operator-(const point &a) const {return {x-a.x,y-a.y};}
    point operator-() const {return {-x,-y};}
    point operator*(const T k) const {return {k*x,k*y};}
    T operator*(const point &a) const {return x*a.x+y*a.y;} // 点积
    T operator^(const point &a) const {return x*a.y-y*a.x;} // 叉积，注意优先级
    int toleft(const point &a) const {const auto t=(*this)^a; return (t>eps)-(t<-eps);} // to-left 测试

};

using Point=point<_T>;

// 极角排序
struct argcmp
{
    bool operator()(const Point &a,const Point &b) const
    {
        const auto quad=[](const Point &a)
        { // 下半平面 < 原点 < x正半轴 < 上半平面 < x负半轴
            if (a.y<-eps) return 1;
            if (a.y>eps) return 4;
            if (a.x<-eps) return 5;
            if (a.x>eps) return 3;
            return 2;
        };
        const int qa=quad(a),qb=quad(b);
        if (qa!=qb) return qa<qb;
        const auto t=a^b;
        // if (abs(t)<=eps) return a*a<b*b-eps; // 不同长度的向量需要分开
        return t>eps;
    }
};

// 直线
template<typename T> struct line
{
    point<T> p,v; // p 为直线上一点，v 为方向向量
    int toleft(const point<T> &a) const {return v.toleft(a-p);} // to-left 测试
};

using Line=line<_T>;

// 多边形
template<typename T> struct polygon
{
    vector<point<T>> p; // 以逆时针顺序存储

    size_t nxt(const size_t i) const {return i==p.size()-1?0:i+1;}
    size_t pre(const size_t i) const {return i==0?p.size()-1:i-1;}
 
};

using Polygon=polygon<_T>;

//凸多边形
template<typename T> struct convex: polygon<T>
{
    // 凸多边形关于某一方向的极点
    // 复杂度 O(logn)
    // 参考资料：https://codeforces.com/blog/entry/48868
    template<typename F> size_t extreme(const F &dir) const
    {
        const auto &p=this->p;
        const auto check=[&](const size_t i){return dir(p[i]).toleft(p[this->nxt(i)]-p[i])>=0;};
        const auto dir0=dir(p[0]); const auto check0=check(0);
        if (!check0 && check(p.size()-1)) return 0;
        const auto cmp=[&](const Point &v)
        {
            const size_t vi=&v-p.data();
            const auto checkv=check(vi);
            const auto t=dir0.toleft(v-p[0]);
            return checkv^(checkv==check0 && ((!check0 && t<=0) || (check0 && t<0)));
        };
        return partition_point(p.begin(),p.end(),cmp)-p.begin();
    }

    // 过凸多边形外一点求凸多边形的切线，返回切点下标
    // 复杂度 O(logn)
    // 必须保证点在多边形外
    pair<size_t,size_t> tangent(const point<T> &a) const
    {
        const size_t i=extreme([&](const point<T> &u){return u-a;});
        const size_t j=extreme([&](const point<T> &u){return a-u;});
        return {i,j};
    }
};

using Convex=convex<_T>;

struct Event {
    Point d;
    int st,qid; // 1 进 0 求值 -1 出 由大到小排序  
    bool operator<(const Event &a) const {
        if(argcmp()(d,a.d)==argcmp()(a.d,d)) return st>a.st;
        return argcmp()(d,a.d);
    }
};

const int N=1e5+10;
int ans[N];
Convex poly;
vector<Event> event;

void solve() {
    poly.p.clear();
    auto &p=poly.p;
    int n; scanf("%d",&n);
    for(int i=1;i<=n;i++) {
        int x,y; scanf("%d %d",&x,&y);
        p.push_back({x,y});
    }
    event.clear();
    int m; scanf("%d",&m);
    int cnt=0;
    for(int i=1;i<=m;i++) {
        int x,y; scanf("%d %d",&x,&y);
        Point t={x,y};
        auto xx=poly.tangent(t);
        auto a=xx.first,b=xx.second;
        Point ap=t-p[a],bp=t-p[b];
        if(ap.toleft(p[(a+1)%p.size()]-p[a])==1) { // bp->ap
            if((bp.toleft({-1,0})==1 || bp.toleft({-1,0})==0) && ap.toleft({-1,0})==-1) cnt++;
            event.push_back({bp,1}),event.push_back({ap,-1});
        }
        else { // ap->bp
            if((ap.toleft({-1,0})==1 || ap.toleft({-1,0})==0) && bp.toleft({-1,0})==-1) cnt++;
            event.push_back({ap,1}),event.push_back({bp,-1});
        }
    }
    // for(auto t:event) cout<<t.d.x<<" "<<t.d.y<<" "<<t.st<<endl;
    int q; scanf("%d",&q);
    for(int i=1;i<=q;i++) {
        int x,y; scanf("%d %d",&x,&y);
        event.push_back({{x,y},0,i});
    }
    sort(event.begin(),event.end());
    for(auto t:event) {
        int st=t.st;
        if(st==0) ans[t.qid]=cnt;
        else cnt+=st;
    }
    for(int i=1;i<=q;i++) printf("%d\n",ans[i]); 
}

signed main() {
//	freopen("1001.in","r",stdin);
//	freopen("my.out","w",stdout);
    int tc; scanf("%d",&tc);
    while(tc--) solve();
    return 0;
}