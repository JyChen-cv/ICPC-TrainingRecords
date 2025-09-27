#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <cstring>

const long long N=1000;
struct group {
    long long v;
    long long w;
} mapp[N+2];
long long f[N+2];

long long main()
{
    long long n,m;
    std::cin>>n>>m;
    for (long long i=1;i<=m;i++) {
        std::cin>>mapp[i].v>>mapp[i].w;
    }

    for (long long i=1;i<=m;i++) {
        for (long long j=n;j>=mapp[i].v;j--) {
            f[j]=std::max(f[j],f[j-mapp[i].v]+mapp[i].w);
        }
    }

    std::cout<<f[n]<<std::endl;
    return 0;
}