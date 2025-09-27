#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <queue>
#include <vector>

const long long N=20;
std::string mapp[N+2];
long long head[N+2],nxt[N*2+2],ver[N*2+2],edge[N*2+2],tot,pot[N+2],v[N+2],ans,n;

long long cal(long long xx,long long yy)
{
    std::string x=mapp[xx];
    std::string y=mapp[yy];
    long long len=std::max(x.size(),y.size())-1;
    if (xx==n) len++;
    for (long long i=1;i<=len;i++) {
        long long tag=0;
        for (long long j=1;j<=i;j++) {
            if (x[x.size()-j]!=y[i-j]) {
                tag=1;
                break;
            }
        } 
        if (tag==0) {
            return i;
        }
    }
    return 0;
}

void add(long long x,long long y)
{
    long long ls=cal(x,y);
    if (ls<1) return ;
    tot++;
    ver[tot]=y;
    edge[tot]=ls;
    nxt[tot]=head[x];
    head[x]=tot;
    pot[y]=mapp[y].size();
}

void dfs(long long x,long long num)
{
    ans=std::max(ans,num);
    for (long long i=head[x];i;i=nxt[i]) {
        long long y=ver[i];
        long long z=edge[i];
        if (v[y]>=2) continue;
        v[y]++;
        dfs(y,num+pot[y]-z);
        v[y]--;
    }
}

long long main()
{
    std::cin>>n;
    n++;
    for (long long i=1;i<=n;i++) {
        std::cin>>mapp[i];
    }

    for (long long i=1;i<=n;i++) {
        for (long long j=i;j<=n;j++) {
            add(i,j);
            add(j,i);
        }
    }
    v[n]=1;
    dfs(n,1);
    std::cout<<ans<<std::endl;
    return 0;
}