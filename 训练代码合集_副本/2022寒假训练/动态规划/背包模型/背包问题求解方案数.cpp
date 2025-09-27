#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>

const long long N=1000;
const long long mod=1e9+7;
struct group {
    long long v;
    long long w;
} mapp[N+2];
long long n,m,f[N+2],rem[N+2];


long long main()
{
    std::cin>>n>>m;
    for (long long i=1;i<=n;i++) std::cin>>mapp[i].v>>mapp[i].w;
    
    for (long long i=0;i<=m;i++) rem[i]=1;
    for (long long i=1;i<=n;i++) {
        for (long long j=m;j>=mapp[i].v;j--) {
            if (f[j]<f[j-mapp[i].v]+mapp[i].w) {
                f[j]=f[j-mapp[i].v]+mapp[i].w;
                rem[j]=rem[j-mapp[i].v];
            }
            else if (f[j]==f[j-mapp[i].v]+mapp[i].w) {
                rem[j]+=rem[j-mapp[i].v];
                rem[j]%=mod;
            }
            // std::cout<<rem[j]<<" ";
        }
        // std::cout<<std::endl;
    }

    std::cout<<rem[m]<<std::endl;
    return 0;
}