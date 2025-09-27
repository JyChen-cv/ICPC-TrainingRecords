#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
#include <queue>

#define x first 
#define y second 
typedef std::pair<double,double> PDD;
const int N=40000;
const double pi=acos(-1); 

int n,cnt;
PDD q[N+2];
int stk[N],top;
bool used[N+2];

PDD operator - (PDD a,PDD b)
{
    return {a.x-b.x,a.y-b.y};
}

double cross(PDD a,PDD b)
{
    return a.x*b.y-a.y*b.x;
}

double area(PDD a,PDD b,PDD c)
{
    return cross(b-a,c-a);
}

double get_dist(PDD a,PDD b)
{
    double dx=a.x-b.x;
    double dy=a.y-b.y;
    return sqrt(dx*dx+dy*dy);
}

double andrew()
{
    sort(q+1,q+cnt+1);
    for (int i=1;i<=cnt;i++) {
        while (top>=2 && area(q[stk[top-1]],q[stk[top]],q[i])<=0) {
            used[stk[top--]]=0;
        }
        stk[++top]=i;
        used[i]=1;
    }
    used[1]=0;
    for (int i=cnt;i>=1;i--) {
        if (used[i]) continue;
        while (top>=2 && area(q[stk[top-1]],q[stk[top]],q[i])<=0) {
            top--;
        }
        stk[++top]=i;
    }

    double res=0;
    for (int i=2;i<=top;i++) {
        res+=get_dist(q[stk[i-1]],q[stk[i]]);
    }
    return res;
}

PDD rotate(PDD a,double b) // 旋转直接带公式，没啥说的
{
    return PDD{a.x*cos(b)+a.y*sin(b),-a.x*sin(b)+a.y*cos(b)};
}

int main()
{
    std::cin>>n;
    double a,b,r;
    std::cin>>a>>b>>r;
    a=a/2-r; // 竖直方向
    b=b/2-r; // 水平方向
    const int dx[]={1,1,-1,-1};
    const int dy[]={1,-1,1,-1};
    while (n--) {
        double xx,yy,z;
        std::cin>>xx>>yy>>z;
        for (int i=0;i<4;i++) {
            PDD t=rotate({dx[i]*b,dy[i]*a},-z); // 题干交代是逆时针旋转
            q[++cnt]={xx+t.x,yy+t.y};
        }
    }

    double res=andrew();
    printf("%.2lf\n",res+2*pi*r);
    return 0;
}