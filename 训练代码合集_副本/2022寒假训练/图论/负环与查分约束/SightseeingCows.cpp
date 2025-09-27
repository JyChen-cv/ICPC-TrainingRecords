#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <queue>

const long long N=10000,M=50000;
long long head[N+2],ver[M+2],nxt[M+2],tot,n,m,cnt[N+2];
bool v[N+2];
double edge[M+2],p[N+2],d[N+2];
struct group {
    long long a,b;
    double c;
} mapp[N+2];
std::queue<long long> q;

void add(long long x,long long y,double z)
{
    edge[++tot]=z;
    ver[tot]=y;
    nxt[tot]=head[x];
    head[x]=tot;
}

bool spfa() 
{
    memset(d,0,sizeof(d));
    memset(v,0,sizeof(v));
    memset(cnt,0,sizeof(cnt));
    for (long long i=1;i<=n;i++) {
        q.push(i);
        v[i]=1;
    }
    while (q.size()) {
        long long x=q.front();
        q.pop();
        v[x]=0;
        for (long long i=head[x];i;i=nxt[i]) {
            long long y=ver[i];
            double z=edge[i];
            if (d[y]>d[x]+z) {
                d[y]=d[x]+z;
                cnt[y]=cnt[x]+1;
                if (cnt[y]>=n) return 1;
                if (!v[y]) {
                    q.push(y);
                    v[y]=1;
                }
            }
        }
    }
    return 0;
}

bool check(double x)
{
    memset(nxt,0,sizeof(nxt));
    memset(head,0,sizeof(head));
    memset(edge,0,sizeof(edge));
    memset(ver,0,sizeof(ver));
    tot=0;
    for (long long i=1;i<=m;i++) {
        add(mapp[i].a,mapp[i].b,mapp[i].c*x-p[mapp[i].a]);
    }
    return spfa();
}

long long main()
{
    std::cin>>n>>m;
    for (long long i=1;i<=n;i++) std::cin>>p[i];
    for (long long i=1;i<=m;i++) {
        std::cin>>mapp[i].a>>mapp[i].b>>mapp[i].c;
    }
    double l=0,r=1000;
    while ((r-l)>0.0001) { // 精度高一点才能保证正确
        double mid=(l+r)/2;
        if (check(mid)) {
            l=mid;
        }
        else {
            r=mid;
        }
    }
    prlong longf("%.2lf\n",r);
    return 0;
}