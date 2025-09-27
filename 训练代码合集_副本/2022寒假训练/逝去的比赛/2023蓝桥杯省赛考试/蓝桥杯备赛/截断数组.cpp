#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>

const long long N=100000;
long long mapp[N+2];

long long main()
{
    long long n;
    std::cin>>n;
    for (long long i=1;i<=n;i++) {
        std::cin>>mapp[i];
        mapp[i]+=mapp[i-1];
    }
    if (mapp[n]%3!=0) std::cout<<0<<std::endl;
    long long ls=mapp[n]/3;
    long long tag1=0,ans=0;
    for (long long i=1;i<=n;i++) {
        if (mapp[i]==ls) tag1++;
        if (mapp[i]==ls*2) {
            ans+=tag1;
        }
    }
    std::cout<<ans<<std::endl;
    return 0;
}