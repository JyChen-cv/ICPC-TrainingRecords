#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <queue>

const long long N=2500,M=6200*2;
long long ver[M+2],edge[M+2],nxt[M+2],head[N+2];
long long tot;
std::queue<long long> q;
long long d[N+2],v[N+2];

void add(long long x,long long y,long long z)
{
    ver[++tot]=y;
    nxt[tot]=head[x];
    head[x]=tot;
    edge[tot]=z;
}

void SPFA(long long p)
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
    long long n,m,s,t;
    std::cin>>n>>m>>s>>t;
    for (long long i=1;i<=m;i++) {
        long long a,b,c;
        std::cin>>a>>b>>c;
        add(a,b,c);
        add(b,a,c);
    }

    SPFA(s);
    std::cout<<d[t]<<std::endl;

    return 0;
}