#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <vector>

const long long N=40000;
long long n,m,t,f[N+2][30],head[N+2],nxt[N*2+2],edge[N*2+2],ver[N*2+2],tot,root,dep[N+2];

long long add(long long x,long long y)
{
    tot++;
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
        dfs(y,x);
    }
}

long long main()
{
    std::cin>>n;
    t=log(n)/log(2)+1;
    for (long long i=1;i<=n;i++) {
        long long a,b;
        std::cin>>a>>b;
        if (b==-1) {
            root=a;
            continue;
        }
        add(a,b);
        add(b,a);
    }
    dep[root]=1;
    dfs(root,0);
    std::cin>>m;
    for (long long i=1;i<=m;i++) {
        long long a,b,tag=0;
        std::cin>>a>>b;
        if (dep[a]<dep[b]) {
            std::swap(a,b);
            tag=1;
        }

        for (long long i=t;i>=0;i--) {
            if (dep[f[a][i]]>=dep[b]) a=f[a][i];
        }
        if (a==b) {
            if (tag==1) std::cout<<1<<std::endl;
            else std::cout<<2<<std::endl;
        }
        else std::cout<<0<<std::endl;
    }

    return 0;
}