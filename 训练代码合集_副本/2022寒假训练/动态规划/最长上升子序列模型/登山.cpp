#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>

const long long MaxN=1000;
long long mapp[MaxN+2],f[MaxN+2],q[MaxN+2];

long long main()
{
    long long n;
    std::cin>>n;
    for (long long i=1;i<=n;i++) std::cin>>mapp[i];

    for (long long i=1;i<=n;i++) {
        f[i]=1;
        for (long long j=1;j<i;j++) {
            if (mapp[i]>mapp[j]) f[i]=std::max(f[i],f[j]+1);
        }
    }
    long long ans=0;
    for (long long i=n;i>=1;i--) {
        q[i]=1;
        for (long long j=i+1;j<=n;j++) {
            if (mapp[j]<mapp[i]) q[i]=std::max(q[i],q[j]+1);
        }
        f[i]+=q[i];
        f[i]-=1;
        ans=std::max(ans,f[i]);
    }

    std::cout<<ans<<std::endl;
    return 0;
}