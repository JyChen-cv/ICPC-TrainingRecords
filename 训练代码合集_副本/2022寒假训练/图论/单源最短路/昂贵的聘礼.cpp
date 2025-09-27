// 这道题目的建立图方式很值得借鉴，这就是图论的魅力，只要你能看出来这是图论，就不难

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <vector>
#include <queue>
#include <map>
#include <stack>

const long long N=100,M=20000;
long long head[N+2],edge[M+2],nxt[M+2],lev[N+2],wor[N+2],ver[M+2];
long long tot;
long long d[N+2],v[N+2];
std::priority_queue<std::pair<long long,long long> > q;

void add(long long x,long long y,long long z)
{
    tot++;
    ver[tot]=y;
    edge[tot]=z;
    nxt[tot]=head[x];
    head[x]=tot;
}

void dijkstra(long long p,long long l,long long r)
{
    memset (d,0x3f,sizeof(d));
    memset (v,0,sizeof(v));
    d[p]=0;
    q.push(std::make_pair(0,p));
    while (q.size()) {
        long long x=q.top().second;
        q.pop();
        if (v[x]) continue;
        v[x]=1;
        for (long long i=head[x];i;i=nxt[i]) {
            long long y=ver[i];
            long long z=edge[i];
            if (d[y]>d[x]+z && lev[y]<=r && lev[y]>=l) {
                d[y]=d[x]+z;
                q.push(std::make_pair(-d[y],y));
            }
        }
    }
}

long long main()
{
    long long m,n;
    std::cin>>m>>n;
    for (long long i=1;i<=n;i++) {
        long long num;
        std::cin>>wor[i]>>lev[i]>>num;
        for (long long j=1;j<=num;j++) {
            long long a,b;
            std::cin>>a>>b;
            add(a,i,b);
        }
        add(n+1,i,wor[i]);
    }
    
    long long ans=0x3f3f3f3f;
    for (long long i=0;i+m<=100;i++) {
        dijkstra(n+1,i,i+m);
        ans=std::min(ans,d[1]);
    }
    std::cout<<ans<<std::endl;

    return 0;
}