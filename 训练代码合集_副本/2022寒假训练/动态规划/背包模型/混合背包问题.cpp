#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>

const long long N=1000;
long long h[40];
struct group {
    long long v;
    long long w;
} mapp[N*20+2];
long long f[N*20+2];

long long main()
{
    h[0]=1;
    for (long long i=1;i<=30;i++) {
        h[i]=h[i-1]*2;
    }

    long long n,m,num=0;
    std::cin>>n>>m;
    for (long long i=1;i<=n;i++) {
        long long x,vv,ww;
        std::cin>>vv>>ww>>x;
        if (x==-1) x=1;
        else if (x==0) x=10000000;
        for (long long j=0;j<=30;j++) {
            if (x>=h[j]) {
                num++;
                x-=h[j];
                mapp[num].v=vv*h[j];
                mapp[num].w=ww*h[j];
            }
            else {
                num++;
                mapp[num].v=vv*x;
                mapp[num].w=ww*x;
                break;
            }
        }
    }

    for (long long i=1;i<=num;i++) {
        for (long long j=m;j>=mapp[i].v;j--) {
            f[j]=std::max(f[j],f[j-mapp[i].v]+mapp[i].w);
        }
    }

    std::cout<<f[m]<<std::endl;
    return 0;
}