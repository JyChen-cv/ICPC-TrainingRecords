#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>

const long long N=100000;
long long mapp[N+2],sum[N+2];
long long ll[N*10+2];

long long main()
{
    long long n;
    std::cin>>n;
    for (long long i=1;i<=n;i++) {
        std::cin>>mapp[i];
        
    }

    long long ans=0;
    ll[0]=1;
    for (long long i=1;i<=n;i++) {
        sum[i]=sum[i-1]+mapp[i];
        ll[sum[i]]++;
        for (long long j=0;j*j<=sum[i];j++) {
            if (j==0) {
                ans+=ll[sum[i]]-1;
                continue;
            }
            if (ll[sum[i]-j*j]) ans+=ll[sum[i]-j*j];
        }
        // std::cout<<ans<<std::endl;
    }
    std::cout<<ans<<std::endl;

    return 0;
}