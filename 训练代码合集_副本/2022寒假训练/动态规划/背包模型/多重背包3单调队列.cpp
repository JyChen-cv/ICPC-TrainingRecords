#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <cstring>

const long long N=200000;
long long que[N+2],f[N+2],g[N+2];

long long main()
{
    long long n,m;
    std::cin>>n>>m;
    for (long long i=1;i<=n;i++) {
        memcpy (g,f,sizeof(f));

        long long v,w,num;
        std::cin>>v>>w>>num;
        for (long long j=0;j<v;j++) {
            long long hh=0,tt=-1;
            for (long long k=j;k<=m;k+=v) {
                while (tt>=hh && (k-que[hh])>num*v) hh++;
                while (tt>=hh && (g[que[hh]]-(que[hh]-j)/v*w)<(g[k]-(k-j)/v*w)) tt--;
                tt++;
                que[tt]=k;
                f[k]=std::max(g[k],g[que[hh]]+(k-que[hh])/v*w);
            }
        }
    }

    return 0;
}