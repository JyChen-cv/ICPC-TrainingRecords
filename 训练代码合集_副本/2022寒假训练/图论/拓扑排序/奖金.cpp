#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
#include <queue>

const long long N=20000;
long long head[N+2],nxt[N*2+2],ver[N*2+2],tot,d[N+2],v[N+2],dep[N+2];
std::queue<long long> q;


void add(long long x,long long y)
{
    tot++;
    ver[tot]=y;
    nxt[tot]=head[x];
    head[x]=tot;
    d[y]++;
    v[y]=1;
}

void dfs(long long x,long long fa)
{
    for (long long i=head[x];i;i=nxt[i]) {
        long long y=ver[i];
        if (y==fa) continue;
        d[y]--;
        if (!d[y]) q.push(y);
    }
}

void ddfs(long long x,long long fa)
{
    if (dep[x]) return ;
    for (long long i=head[x];i;i=nxt[i]) {
        long long y=ver[i];
        if (y==fa) continue;
        ddfs(y,x);
        dep[x]=std::max(dep[x],dep[y]+1);
    }
}

long long main()
{
    long long n,m;
    std::cin>>n>>m;
    for (long long i=1;i<=m;i++) {
        long long a,b;
        std::cin>>a>>b;
        add(a,b);
    }
    
    for (long long i=1;i<=n;i++) 
        if (!d[i]) q.push(i);
    while (q.size()) {
        long long x=q.front();
        q.pop();
        dfs(x,0);
    }
    for (long long i=1;i<=n;i++) {
        if (d[i]) {
            std::cout<<"Poor Xed"<<std::endl;
            return 0;
        }
    }
    
    for (long long i=1;i<=n;i++) {
        if (!v[i]) ddfs(i,0);
    }
    long long ans=0;
    for (long long i=1;i<=n;i++) {
        ans+=(100+dep[i]);
    }
    std::cout<<ans<<std::endl;
    return 0;
}