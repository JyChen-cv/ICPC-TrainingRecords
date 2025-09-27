#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <queue>

const long long N=25000;
long long n,m,w;
long long head[N+2],nxt[N*2+2],ver[N*2+2],edge[N*2+2];
long long tot,d[N+2],cnt[N+2],v[N+2];
std::queue<long long> q;

void add(long long x,long long y,long long z)
{
    tot++;
    edge[tot]=z;
    ver[tot]=y;
    nxt[tot]=head[x];
    head[x]=tot;
}

bool SPFA() 
{
    memset(d,0,sizeof(d));
    memset(v,0,sizeof(v));
    memset(cnt,0,sizeof(cnt));
    
    for (long long i=0;i<=n;i++) {
        q.push(i);
        v[i]=1;
    }
    while (q.size()) {
        long long x=q.front();
        q.pop();
        v[x]=0;
        for (long long i=head[x];i;i=nxt[i]) {
            long long y=ver[i];
            long long z=edge[i];
            if (d[y]>d[x]+z) {
                d[y]=d[x]+z;
                cnt[y]=cnt[x]+1;
                if (cnt[y]>=n) return 1;
                if (!v[y]) q.push(y),v[y]=1;
            }
        }
    }
    return 0;
}

long long main()
{
    long long t;
    std::cin>>t;
    while (t--) {
        memset(edge,0,sizeof(edge));
        memset(nxt,0,sizeof(nxt));
        memset(head,0,sizeof(head));
        memset(ver,0,sizeof(ver));
        tot=0;
        std::cin>>n>>m>>w;
        for (long long i=1;i<=m;i++) {
            long long a,b,c;
            std::cin>>a>>b>>c;
            add(a,b,c);
            add(b,a,c);
        }
        for (long long i=1;i<=w;i++) {
            long long a,b,c;
            std::cin>>a>>b>>c;
            add(a,b,-c);
        }
        if (SPFA()) std::cout<<"YES"<<std::endl;
        else std::cout<<"NO"<<std::endl;
    }

    return 0;
}