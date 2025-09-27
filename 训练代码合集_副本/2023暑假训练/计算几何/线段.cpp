#include <iostream>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>
#include <queue>

#define x first
#define y second
typedef std::pair<double,double> PDD;

const int N=200;
const double esp=1e-8;
int n;
PDD q[N+2],a[N+2],b[N+2];

int sign(double x)
{
    if (std::fabs(x)<esp) return 0;
    else if (x<0) return -1;
    else return 1;
}

int cmp(double x,double y)
{
    return sign(x-y);
}

double cross(double x1,double y1,double x2,double y2)
{
    return x1*y2-x2*y1;
}

double area(PDD a,PDD b,PDD c)
{
    return cross(b.x-a.x,b.y-a.y,c.x-a.x,c.y-a.y);
}

bool check() 
{
    for (int i=1;i<=n*2;i++) {
        for (int j=i+1;j<=n*2;j++) { // 利用事件点来进行扫描线操作
            if (!cmp(q[i].x,q[j].x) && !cmp(q[i].y,q[j].y)) continue;
            int tag=1;
            for (int k=1;k<=n;k++) { // 这一步转化相当巧妙，对于投影这个东东有了新的理解
                if (sign(area(q[i],q[j],a[k]))*sign(area(q[i],q[j],b[k]))>0) {
                    tag=0;
                    break;
                }
            }
            if (tag==1) return 1;
        }
    }
    return 0;
}

int main()
{
    int t;
    std::cin>>t;
    while (t--) {
        std::cin>>n;
        for (int i=1,k=0;i<=n;i++) {
            double x1,x2,y1,y2;
            scanf("%lf%lf%lf%lf",&x1,&y1,&x2,&y2);
            q[++k]={x1,y1};
            q[++k]={x2,y2};
            a[i]={x1,y1};
            b[i]={x2,y2};
        }

        if (check()) puts("Yes!");
        else puts("No!");
    }
    return 0;
}