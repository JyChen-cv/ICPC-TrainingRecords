#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <queue>

const long long N=800,M=2900;
long long ver[M+2],head[N+2],edge[M+2],w[N+2],nxt[M+2];
long long tot;
long long v[N+2],d[N+2];
std::queue<long long> q;

void add(long long x,long long y,long long z)
{
    ver[++tot]=y;
    nxt[tot]=head[x];
    head[x]=tot;
    edge[tot]=z;
}

void spfa(long long p) 
{
    memset (d,0x3f,sizeof(d));
    memset (v,0,sizeof(v));
    d[p]=0;
    v[p]=1;
    q.push(p);
    while (q.size()) {
        long long x=q.front();
        q.pop();
        v[x]=0;
        for (long long i=head[x];i;i=nxt[i]) {
            long long y=ver[i];
            long long z=edge[i];
            if (d[y]>d[x]+z) {
                d[y]=d[x]+z;
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
    long long num,n,m;
    std::cin>>num>>n>>m;
    for (long long i=1;i<=num;i++) {
        long long a;
        std::cin>>a;
        w[a]++;
    }
    for (long long i=1;i<=m;i++) {
        long long a,b,c;
        std::cin>>a>>b>>c;
        add(a,b,c);
        add(b,a,c);
    }

    long long ans=0x3f3f3f3f;
    for (long long i=1;i<=n;i++) {
        spfa(i);
        long long ls=0;
        for (long long i=1;i<=n;i++) {
            ls+=(long long)w[i]*d[i];
        }
        ans=std::min(ans,ls);
    }
    std::cout<<ans<<std::endl;

    return 0;
}