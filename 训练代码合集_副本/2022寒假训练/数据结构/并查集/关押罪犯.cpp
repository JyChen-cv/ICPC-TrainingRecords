#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>

const long long N=100000;
struct group {
    long long x,y,z;
    bool operator < (const group &t)const { // sort只会调用小于号不会调用大于号
        return z>t.z; // 这样写可以实现降序排列
    }
} mapp[N+2];
long long fa[N+2];

long long find(long long x)
{
    if (fa[x]==x) return x;
    else return fa[x]=find(fa[x]);
}

long long main()
{
    long long n,m;
    std::cin>>n>>m;
    for (long long i=1;i<=n*2;i++) fa[i]=i;
    for (long long i=1;i<=m;i++) {
        std::cin>>mapp[i].x>>mapp[i].y>>mapp[i].z;
    }
    std::sort(mapp+1,mapp+m+1);
    for (long long i=1;i<=m;i++) {
        long long a=find(mapp[i].x);
        long long b=find(mapp[i].y);
        long long c=find(mapp[i].x+n);
        long long d=find(mapp[i].y+n);
        fa[a]=d;
        fa[b]=c;
        a=find(mapp[i].x);
        b=find(mapp[i].y);
        c=find(mapp[i].x+n);
        d=find(mapp[i].y+n);
        if (a==c || b==d) {
            std::cout<<mapp[i].z;
            break;
        }
    }
    return 0;
}