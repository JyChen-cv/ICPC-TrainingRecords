#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>

const long long N=100000;
long long ver[N*2+2],nxt[N*2+2],head[N],cnt[N+2],fa[N+2][30];
long long tot,t,dep[N+2],n,m,ans1,ans2;

void add(long long x,long long y) {
    tot++;
    ver[tot]=y;
    nxt[tot]=head[x];
    head[x]=tot;
}

void dfs(long long x,long long f) {
    for (long long i=1;i<=t;i++) {
        fa[x][i]=fa[fa[x][i-1]][i-1];
    }
    for (long long i=head[x];i;i=nxt[i]) {
        long long y=ver[i];
        if (y==f) continue;
        
        fa[y][0]=x;
        dep[y]=dep[x]+1;
        dfs(y,x);
    }
}

long long lca(long long x,long long y) {
    // 先跳到同一层，再一起向上跳
    if (dep[y]>dep[x]) std::swap(y,x);
    for (long long i=t;i>=0;i--) {
        if (dep[fa[x][i]]>=dep[y]) x=fa[x][i];
    }
    if (x==y) return x;
    for (long long i=t;i>=0;i--) {
        if (fa[x][i]!=fa[y][i]) {
            x=fa[x][i];
            y=fa[y][i];
        }
    }
    return fa[x][0];
}

void deal(long long x,long long f) {
    for (long long i=head[x];i;i=nxt[i]) {
        long long y=ver[i];
        if (y==f) continue;
        deal(y,x);
        if (cnt[y]==0) ans1++;
        else if (cnt[y]==1) ans2++;
        cnt[x]+=cnt[y];
    }
}

long long main()
{
    std::cin>>n>>m;
    t=(long long)(log(n)/log(2))+1;
    for (long long i=1;i<n;i++) {
        long long a,b;
        std::cin>>a>>b;
        add(a,b);
        add(b,a);
    }
    dep[1]=1;
    dfs(1,0);
    for (long long i=1;i<=m;i++) {
        long long a,b;
        std::cin>>a>>b;
        long long c=lca(a,b);
        cnt[a]++;
        cnt[b]++;
        cnt[c]-=2;
    }
    deal(1,0);

    std::cout<<(ans1*m+ans2)<<std::endl;
    
    return 0;
}