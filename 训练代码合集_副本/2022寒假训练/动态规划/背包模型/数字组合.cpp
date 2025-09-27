#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>

const long long N=1000;
long long mapp[N+2],f[N*10+2];

long long main()
{
    long long n,m;
    std::cin>>n>>m;
    for (long long i=1;i<=n;i++) {
        std::cin>>mapp[i];
    }

    for (long long i=1;i<=n;i++) {
        for (long long j=m;j>=mapp[i];j--) {
            if (j==mapp[i]) f[j]++;
            else if (f[j-mapp[i]]) f[j]+=f[j-mapp[i]];
        }
    }
    std::cout<<f[m]<<std::endl;
    return 0;
}