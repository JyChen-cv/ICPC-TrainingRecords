#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>

const long long N=1000;
long long mapp[N+2],f[N*25+2],n;

long long main()
{
    long long t;
    std::cin>>t;
    while (t--) {
        memset(mapp,0,sizeof(mapp));
        memset(f,0,sizeof(f));

        std::cin>>n;
        for (long long i=1;i<=n;i++) {
            std::cin>>mapp[i];
        }
        std::sort(mapp+1,mapp+n+1);

        long long ans=0;
        for (long long i=1;i<=n;i++) {
            if (f[mapp[i]]==0) ans++;
            for (long long j=mapp[i];j<=25000;j++) {
                if (j==mapp[i]) f[j]=1;
                else if (f[j-mapp[i]]) f[j]=1;
            }
        }
        std::cout<<ans<<std::endl;
    }

    return 0;
}