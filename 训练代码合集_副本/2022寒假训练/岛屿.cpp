#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>

const long long N=1000000;
long long nxt[N*2+2],head[N+2],ver[N*2+2],tot;
bool v[N+2],circle[N+2];
long long edge[N*2+2],ans=0,d1[N+2],d2[N+2];

void add(long long x,long long y,long long z)
{
    tot++;
    ver[tot]=y;
    nxt[tot]=head[x];
    head[x]=tot;
    edge[tot]=z;
}

void dfs(long long x,long long fa,long long ls)   // 找环
{
    for (long long i=head[x];i;i=nxt[i]) {
        long long y=ver[i];
        if (y==fa) {
            if (std::abs(i-ls)!=1) circle[x]=1;  // 排除两个点超级加辈
            continue;
        }
        if (v[y]) {
            circle[x]=1;
        }
        else {
            v[y]=1;
            dfs(y,x,i);
            if (circle[y]) circle[x]=1;
        }
    }
}

void ddfs(long long x)
{
    d1[x]=0;
    for (long long i=head[x];i;i=nxt[i]) {
        long long y=ver[i];
        long long z=edge[i];
        if (v[y] || circle[y]) continue;
        v[y]=1;
        ddfs(y);
        if (d1[y]+z>=d1[x]) {
            d2[x]=d1[x];
            d1[x]=d1[y]+z;
        } 
        else if (d1[y]+z>d2[x]) d2[x]=d1[y];
    }
    ans=std::max(ans,d1[x]+d2[x]);
}

long long main()
{
    freopen("data.in", "r", stdin);
    
    long long n;
    std::cin>>n;
    for (long long i=1;i<=n;i++) {
        long long a;
        long long b;
        std::cin>>a>>b;
        add(i,a,b);
        add(a,i,b);
    }
    
    for (long long i=1;i<=n;i++) {
        if (!v[i]) {
            v[i]=1;
            dfs(i,0,0);
        }
    }
    memset (v,0,sizeof(v));
    for (long long i=1;i<=n;i++) {
        if (circle[i] && !v[i]) {
            v[i]=1;
            ddfs(i);  // 求每一个基环树的直径
            std::cout<<i<<" "<<d1[i]<<" "<<std::endl;
        }
    }

    return 0;
}