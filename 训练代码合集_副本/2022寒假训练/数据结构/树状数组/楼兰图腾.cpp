#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <cstring>

const long long N=200000;
typedef unsigned long long ull;
ull BIT[N+2],mapp[N+2],rem[N+2];
long long n;

inline long long lowbit(long long x)
{
    return x&(-x);
}

ull sum(long long x,long long y)
{
    ull ans=0;
    while (x) {
        ans+=BIT[x];
        x-=lowbit(x);
    }

    ull anss=0;
    while (y) {
        anss+=BIT[y];
        y-=lowbit(y);
    }
    return anss-ans;
}

void change(long long x)
{
    while (x<=n) {
        BIT[x]+=1;
        x+=lowbit(x);
    }
}

long long main()
{
    std::cin>>n;
    for (long long i=1;i<=n;i++) {
        std::cin>>mapp[i];
    }

    for (long long i=1;i<=n;i++) {
        rem[i]=sum(mapp[i],n);
        change(mapp[i]);
        // for (long long j=1;j<=n;j++) std::cout<<BIT[j]<<" ";
        // std::cout<<std::endl;
    }
    memset (BIT,0,sizeof(BIT));
    ull ans=0;
    for (long long i=n;i>=1;i--) {
        ull ls=sum(mapp[i],n);
        ans+=(ls*rem[i]);
        change(mapp[i]);
    }
    std::cout<<ans<<" ";

    memset (BIT,0,sizeof(BIT));
    memset (rem,0,sizeof(rem));
    for (long long i=1;i<=n;i++) {
        rem[i]=sum(0,mapp[i]-1);
        change(mapp[i]);
        // for (long long j=1;j<=n;j++) std::cout<<BIT[j]<<" ";
        // std::cout<<std::endl;
    }
    memset (BIT,0,sizeof(BIT));
    ans=0;
    for (long long i=n;i>=1;i--) {
        ull ls=sum(0,mapp[i]-1);
        ans+=(ls*rem[i]);
        change(mapp[i]);
    }
    std::cout<<ans<<std::endl;

    return 0;
}