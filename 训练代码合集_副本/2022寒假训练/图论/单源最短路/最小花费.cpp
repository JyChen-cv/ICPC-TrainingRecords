#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <queue>

const long long N=2000,M=200000,inf=1e9+7;
long long head[N+2],ver[M+2],nxt[M+2];
double edge[M+2];
long long tot,v[N+2],n,m;
double d[N+2];
std::queue<long long> q;

void add(long long x,long long y,double z)
{
    ver[++tot]=y;
    nxt[tot]=head[x];
    head[x]=tot;
    edge[tot]=z;
}

void SPFA(long long p)
{
    for (long long i=1;i<=n;i++) d[i]=inf;
    memset (v,0,sizeof(v));
    d[p]=100;
    v[p]=1;
    q.push(p);
    while (q.size()) {
        long long x=q.front();
        q.pop();
        v[x]=0;
        for (long long i=head[x];i;i=nxt[i]) {
            long long y=ver[i];
            double z=edge[i];
            if (d[y]>d[x]/z) {
                d[y]=d[x]/z;
                if (!v[y]) {
                    q.push(y);
                    v[y]=1;
                }
            }
        }
    }
}

long long main()
{
    std::cin>>n>>m;
    for (long long i=1;i<=m;i++) {
        long long a,b;
        double c;
        std::cin>>a>>b>>c;
        c=1-c/100;
        add(a,b,c);
        add(b,a,c);
    }

    long long t,s;
    std::cin>>t>>s;
    SPFA(s);
    prlong longf("%.8lf\n",d[t]);

    return 0;
}
