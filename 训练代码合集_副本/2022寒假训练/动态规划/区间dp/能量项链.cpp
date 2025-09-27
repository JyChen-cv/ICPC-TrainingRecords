#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>

const long long N=1000;
long long mapp[N*2+2],f[N*2+2][N*2+2];

long long main()
{
    long long n,ans=0;
    std::cin>>n;
    for (long long i=1;i<=n;i++) {
        std::cin>>mapp[i];
        mapp[i+n]=mapp[i];
    }

    // for (long long i=1;i<=n*2;i++) f[i][i]=mapp[i];
    for (long long len=2;len<=n;len++) {
        for (long long l=1;l+len-1<=n*2;l++) {
            long long r=l+len-1;
            for (long long k=l;k<r;k++) {
                f[l][r]=std::max(f[l][r],f[l][k]+f[k+1][r]+mapp[l]*mapp[k+1]*mapp[r+1]);
            }
            if (len==n) ans=std::max(ans,f[l][r]);
        }
    }
    std::cout<<ans<<std::endl;

    return 0;
}