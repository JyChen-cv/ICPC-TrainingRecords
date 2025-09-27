#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>

const long long N=3*1e5,INF=0x3f3f3f3f;
struct group {
    long long x,y;
    long long z;
    bool operator < (const group &t)const {
        return z<t.z;
    }
} mapp[N+2];
long long n,m,dep[N+2],f[N+2][30],tag[N+2],head[N+2],ver[N+2],nxt[N+2],t,v[N+2];
long long d1[N+2][30],d2[N+2][30],edge[N+2],tot,ans;

void add(long long x,long long y,long long z)
{
    tot++;
    edge[tot]=z;
    ver[tot]=y;
    nxt[tot]=head[x];
    head[x]=tot;
}

long long find(long long x)
{
    if (tag[x]==x) return x;
    else return tag[x]=find(tag[x]);
}

long long deal(long long x,long long y,long long z)
{
    if (x==y) return x-z;
    else return x-y;
}

void doo(long long &x,long long &y,long long a1,long long a2,long long b1,long long b2)
{
    x=std::max(a1,b1);
    if (a1==b1) y=std::max(a2,b2);
    else {
        if (a1>b1) y=std::max(b1,a2);
        else y=std::max(a1,b2);
    }
}

void dfs(long long x,long long fa,long long l)
{
    f[x][0]=fa;
    d1[x][0]=l;
    d2[x][0]=-INF;
    for (long long i=1;i<=t;i++) {
        f[x][i]=f[f[x][i-1]][i-1];
        doo(d1[x][i],d2[x][i],d1[x][i-1],d2[x][i-1],d1[f[x][i-1]][i-1],d2[f[x][i-1]][i-1]);
    }
    for (long long i=head[x];i;i=nxt[i]) {
        long long y=ver[i];
        long long z=edge[i];
        if (y==fa) continue;
        dep[y]=dep[x]+1;
        dfs(y,x,z);
    }
}

long long lca(long long x,long long y,long long z)
{
    if (dep[x]<dep[y]) std::swap(x,y);
    long long max1=-INF,max2=-INF;
    for (long long i=t;i>=0;i--) {
        if (dep[f[x][i]]>=dep[y]) {
            doo(max1,max2,max1,max2,d1[x][i],d2[x][i]);
            x=f[x][i];
        }
    }
    for (long long i=t;i>=0;i--) {
        if (f[x][i]!=f[y][i]) {
            doo(max1,max2,max1,max2,d1[x][i],d2[x][i]);
            doo(max1,max2,max1,max2,d1[y][i],d2[y][i]);
            x=f[x][i];
            y=f[y][i];
        }
    }
    doo(max1,max2,max1,max2,d1[x][0],-INF);
    doo(max1,max2,max1,max2,d1[y][0],-INF);
    return deal(z,max1,max2);
}

long long main()
{
    std::cin>>n>>m;
    t=log(n)/log(2)+1;
    for (long long i=1;i<=m;i++) {
        long long a,b;
        long long c;
        std::cin>>a>>b>>c;
        if (a==b) {
            i--;
            m--;
            continue;
        }
        mapp[i]=(group){a,b,c};
    }

    std::sort(mapp+1,mapp+m+1);
    for (long long i=1;i<=n;i++) tag[i]=i;
    for (long long i=1;i<=m;i++) {
        long long a=find(mapp[i].x),b=find(mapp[i].y);
        if (a!=b){
            tag[a]=b;
            add(mapp[i].x,mapp[i].y,mapp[i].z);
            add(mapp[i].y,mapp[i].x,mapp[i].z);
            v[i]=1;
            ans+=mapp[i].z;
        }
    }
    dep[1]=1;
    dfs(1,0,-INF);

    long long res=INF;
    for (long long i=1;i<=m;i++) {
        if (!v[i]) {
            res=std::min(res,lca(mapp[i].x,mapp[i].y,mapp[i].z));
        }
    }
    std::cout<<(ans+res)<<std::endl;

    return 0;
}