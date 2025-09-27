#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>

const long long N=1000;
struct group {
    long long w;
    long long tag;
} mapp[N+2];
long long n,m,num;

bool cmp(group x,group y)
{
    return x.w>y.w;
}

long long main()
{
    long long t;
    std::cin>>t;
    while (t--) {
        memset (mapp,0,sizeof(mapp));
        num=0;

        std::cin>>n>>m;
        for (long long i=1;i<=n;i++) {
            std::cin>>mapp[i].w>>mapp[i].tag;
            if (mapp[i].tag) num++;
        }
        num=std::min(num,m);
        std::sort(mapp+1,mapp+n+1,cmp);

        double ans=0;
        for (long long i=1;i<=n;i++) {
            if (i<=num) ans+=(double)mapp[i].w/2;
            else ans+=mapp[i].w;
        }
        prlong longf("%.1lf\n",ans);
    }

    return 0;
}