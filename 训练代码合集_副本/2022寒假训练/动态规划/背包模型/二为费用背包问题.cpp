#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <cstdio>

const long long N=1000;
struct group {
    long long v;
    long long g;
    long long w;
} mapp[N+2];
long long f[102][102];

long long main()
{
    long long n,m,k;
    std::cin>>n>>m>>k;
    for (long long i=1;i<=n;i++) {
        std::cin>>mapp[i].v>>mapp[i].g>>mapp[i].w;
    }

    for (long long i=1;i<=n;i++) {
        for (long long j=m;j>=mapp[i].v;j--) {
            for (long long l=k;l>=mapp[i].g;l--) {
                f[j][l]=std::max(f[j][l],f[j-mapp[i].v][l-mapp[i].g]+mapp[i].w);
            }
        }
    }

    std::cout<<f[m][k]<<std::endl;
    return 0;
}