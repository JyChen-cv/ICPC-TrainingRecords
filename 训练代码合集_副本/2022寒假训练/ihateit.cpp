#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <cstring>

const long long N=200000;
long long mapp[N+2],BIT[N+2];
long long n,m;

inline long long lowbit(long long x)
{
    return x&(-x);
}

void change(long long x)
{
    while (x<=n) {
        long long lx=lowbit(x);
        BIT[x]=mapp[x];
        for (long long i=1;i<lx;i<<=1) {
            BIT[x]=std::max(BIT[x],BIT[x-i]);
        }
        x+=lx;
    }
}

void change(long long x,long long y)
{
    // std::cout<<x<<" "<<y<<std::endl;
    if (mapp[x]>=y) return ;
    mapp[x]=y;
    while (x<=n) {
        long long lx=lowbit(x);
        BIT[x]=mapp[x];        // 注意这句话不是BIT[x]=y; 仔细想想，别傻逼
        for (long long i=1;i<lx;i<<=1) {
            BIT[x]=std::max(BIT[x],BIT[x-i]);
        }
        x+=lx;
    }
}

long long que(long long x,long long y)
{
    long long ls=0;
    while (x<=y) {
        // std::cout<<x<<" "<<y<<" "<<mapp[y+1]<<" "<<BIT[y]<<std::endl;
        if (y-lowbit(y)+1>=x) {
            ls=std::max(BIT[y],ls);
            y-=lowbit(y);
        }
        else {
            ls=std::max(ls,mapp[y]);
            y--;
        }
    }
    return ls;
}

long long main()
{
    std::cin>>n>>m;
    for (long long i=1;i<=n;i++) {
        std::cin>>mapp[i];
        change(i);
    }
    for (long long i=1;i<=m;i++) {
        char a;
        std::cin>>a;
        if (a=='Q') {
            long long b,c;
            std::cin>>b>>c;
            prlong longf("%lld\n",que(b,c));
        }
        else {
            long long b;
            long long c;
            std::cin>>b>>c;
            change(b,c);
        }
    }

    return 0;
}