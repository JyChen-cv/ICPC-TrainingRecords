#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>

const long long N=20000;
long long mapp[N+2],f[N+2];

long long main()
{
    long long n,m;
    std::cin>>n>>m;
    for (long long i=1;i<=m;i++) std::cin>>mapp[i];

    for (long long i=0;i<=n;i++) f[i]=n;
    for (long long i=1;i<=m;i++) {
        for (long long j=n;j>=mapp[i];j--) {
            if (f[j-mapp[i]]-mapp[i]>=0) f[j]=std::min(f[j],f[j-mapp[i]]-mapp[i]);
            // std::cout<<f[j]<<" ";
        }
        // std::cout<<std::endl;
    }

    std::cout<<f[n]<<std::endl;
    return 0;
}