#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>

const long long MaxN=100;
long long mapp[MaxN+2],f[MaxN+2];

long long main()
{
    long long t;
    std::cin>>t;
    while (t--) {
        memset (mapp,0,sizeof(mapp));
        memset (f,0,sizeof(f));

        long long n;
        std::cin>>n;
        for (long long i=1;i<=n;i++) std::cin>>mapp[i];

        long long ans=0;
        for (long long i=1;i<=n;i++) {
            f[i]=1;
             for (long long j=1;j<i;j++) {
                if (mapp[j]<mapp[i]) f[i]=std::max(f[i],f[j]+1);
             }
             ans=std::max(ans,f[i]);
        }
        memset(f,0,sizeof(f));
        for (long long i=n;i>=1;i--) {  // 这里必须倒叙枚举，来保证新状态需要的旧状态已全部完成计算
            f[i]=1;
            for (long long j=i+1;j<=n;j++) {
                if (mapp[j]<mapp[i]) f[i]=std::max(f[i],f[j]+1);
            }
            ans=std::max(ans,f[i]);
        }
        std::cout<<ans<<std::endl;
    }

    return 0;
}