#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>

const long long N=100000;
long long mapp[N+2],f[N+2][2];

long long main()
{
    long long t;
    std::cin>>t;
    while (t--) {
        memset (f,0,sizeof(f));

        long long n;
        std::cin>>n;
        for (long long i=1;i<=n;i++) {
            std::cin>>mapp[i];
            f[i][1]=f[i-1][0];
            f[i][0]=std::max(f[i-1][0],f[i-1][1]);
            f[i][1]+=mapp[i];
        }

        std::cout<<std::max(f[n][0],f[n][1])<<std::endl;
    }

    return 0;
}