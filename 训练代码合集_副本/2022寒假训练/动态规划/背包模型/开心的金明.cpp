#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>

const long long N=30000;
struct group {
    long long v;
    long long imp;
} mapp[N+2];
long long n,m,f[N+2];

long long main()
{
    std::cin>>n>>m;
    for (long long i=1;i<=m;i++) {
        std::cin>>mapp[i].v>>mapp[i].imp;
        mapp[i].imp*=mapp[i].v;
    }

    for (long long i=1;i<=m;i++) {
        for (long long j=n;j>=mapp[i].v;j--) {
            f[j]=std::max(f[j],f[j-mapp[i].v]+mapp[i].imp);
        }
    }
    std::cout<<f[n]<<std::endl;
    return 0;
}