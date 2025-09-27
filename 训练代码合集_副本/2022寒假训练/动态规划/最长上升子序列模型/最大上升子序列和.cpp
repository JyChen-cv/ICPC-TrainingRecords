#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>

const long long MaxN=1000;
long long mapp[MaxN+2],f[MaxN+2];

long long main()
{
    long long n;
    std::cin>>n;
    for (long long i=1;i<=n;i++) {
        std::cin>>mapp[i];
    }

    long long ans=0;
    for (long long i=1;i<=n;i++) {
        for (long long j=1;j<i;j++) {
            if (mapp[i]>mapp[j]) f[i]=std::max(f[i],f[j]);
        }
        f[i]+=mapp[i];
        ans=std::max(ans,f[i]);
    }

    std::cout<<ans<<std::endl;
    return 0;
}