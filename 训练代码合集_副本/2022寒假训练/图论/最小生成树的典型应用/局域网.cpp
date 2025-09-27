#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <vector>
#include <queue>
#include <stack>

const long long N=200;
struct group {
    long long x,y,z;
    bool operator < (const group &t)const {
        return z<t.z;
    }
} mapp[N+2];
long long n,m,fa[N+2];

long long find(long long x)
{
    if (fa[x]==x) return x;
    else return fa[x]=find(fa[x]);
}

long long main()
{
    std::cin>>n>>m;
    for (long long i=1;i<=n;i++) fa[i]=i;
    for (long long i=1;i<=m;i++) {
        long long a,b,c;
        std::cin>>a>>b>>c;
        mapp[i]={a,b,c};
    }
    std::sort(mapp+1,mapp+m+1);
    long long ans=0;
    for (long long i=1;i<=m;i++) {
        long long a=find(mapp[i].x),b=find(mapp[i].y);
        if (a==b) {
            ans+=mapp[i].z;
        }
        else fa[b]=a;
    }
    std::cout<<ans<<std::endl;
    return 0;
}

// 最小生成树算法的一部分拿出来也可以得到一个最小生成森林