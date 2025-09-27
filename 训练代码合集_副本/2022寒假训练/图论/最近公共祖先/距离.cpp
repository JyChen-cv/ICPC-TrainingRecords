#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <vector>

const long long N=40000;
long long n,m,t,f[N+2][30],head[N+2],nxt[N*2+2],edge[N*2+2],ver[N*2+2],tot,dep[N+2],cnt[N+2];

long long add(long long x,long long y,long long z)
{
    tot++;
    edge[tot]=z;
    ver[tot]=y;
    nxt[tot]=head[x];
    head[x]=tot;
}

long long dfs(long long x,long long fa)
{
    f[x][0]=fa;
    for (long long i=1;i<=t;i++) {
        f[x][i]=f[f[x][i-1]][i-1];
    }
    for (long long i=head[x];i;i=nxt[i]) {
        long long y=ver[i];
        if (y==fa) continue;
        dep[y]=dep[x]+1;
        cnt[y]=cnt[x]+edge[i];
        dfs(y,x);
    }
}

long long lca(long long x,long long y)
{
    if (dep[x]<dep[y]) std::swap(x,y);
    for (long long i=t;i>=0;i--) {
        if (dep[f[x][i]]>=dep[y]) x=f[x][i];
    }
    if (x==y) return x;
    for (long long i=t;i>=0;i--) {
        if (f[x][i]!=f[y][i]) {
            x=f[x][i];
            y=f[y][i];
        }
    }
    return f[x][0];
}

long long main()
{
    std::cin>>n>>m;
    t=log(n)/log(2)+1;
    for (long long i=1;i<n;i++) {
        long long a,b,c;
        std::cin>>a>>b>>c;
        add(a,b,c);
        add(b,a,c);
    }
    dfs(1,0);
    for (long long i=1;i<=m;i++) {
        long long a,b;
        std::cin>>a>>b;
        long long c=lca(a,b);
        std::cout<<(cnt[a]+cnt[b]-cnt[c]*2)<<std::endl;
    }

    return 0;
}