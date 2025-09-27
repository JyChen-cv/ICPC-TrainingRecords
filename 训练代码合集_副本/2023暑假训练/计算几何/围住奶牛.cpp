#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>

#define x first
#define y second 
typedef std::pair<double,double> PDD;
const int N=10000;

int n;
PDD q[N+2];
int stk[N+2];
bool used[N+2];

double get_dist(PDD a,PDD b)
{
    double dx=a.x-b.x;
    double dy=a.y-b.y;
    return sqrt(dx*dx+dy*dy);
}

PDD operator - (PDD a,PDD b)
{
    return {a.x-b.x,a.y-b.y};
}

double cross(PDD a,PDD b)
{
    return a.x*b.y-b.x*a.y;
}

double area(PDD a,PDD b,PDD c)
{
    return cross(b-a,c-a);
}

double andrew()
{
    sort(q+1,q+n+1);
    int top=0; // 标记栈顶元素
    for (int i=1;i<=n;i++) {
        while (top>=2 && area(q[stk[top-1]],q[stk[top]],q[i])<=0) {
            if (area(q[stk[top-1]],q[stk[top]],q[i])<0) used[stk[top--]]=0; // 取消标记
            else top--;// 凸包边界上的点即使被从栈中删掉，也不能删掉used上的标记,这样也有把凸包切段的可能？
            // 其实不太明白为啥必须有used。。。什么时候会出现上下边合二为一的情况啊？一条纯直线？
        }
        stk[++top]=i;
        used[i]=1; // 放入栈后标记
    }
    used[1]=0;
    for (int i=n;i>=1;i--) {
        if (used[i]) continue;
        while (top>=2 && area(q[stk[top-1]],q[stk[top]],q[i])<=0) {
            top--;
        }
        stk[++top]=i;
    }

    double res=0; // 返回凸包的周长
    for (int i=2;i<=top;i++) {
        res+=get_dist(q[stk[i-1]],q[stk[i]]);
    }
    return res;
}

int main()
{
    scanf("%d",&n);
    for (int i=1;i<=n;i++) {
        scanf("%lf%lf",&q[i].x,&q[i].y);
    }
    double res=andrew();
    printf("%.2lf\n",res);
    return 0;
}