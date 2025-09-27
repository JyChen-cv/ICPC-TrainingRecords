#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>

const long long N=100;
long long mapp[N+2],f[N+2][N+2];

long long main()
{
    long long n;
    std::cin>>n;
    for (long long i=1;i<=n;i++) {
        std::cin>>mapp[i];
        mapp[i+n]=mapp[i];
    }

    long long ans=0x3f3f3f3f;
    memset (f,0x3f,sizeof(f));
    for (long long i=1;i+1<=n*2;i++) f[i][i+1]=0;
    for (long long len=3;len<=n;len++) {
        for (long long l=1;l+len-1<n*2;l++) {
            long long r=l+len-1;
            f[l][r]=std::min(f[l][r-1]+mapp[l]*mapp[r-1]*mapp[r],f[l+1][r]+mapp[l]*mapp[l+1]*mapp[r]);
            if (len==n) ans=std::min(ans,f[l][r]);
        }
    }
    std::cout<<ans<<std::endl;

    return 0;
}

// 少考虑了好多情况，比如从中间选择，例如三角形（1，2，4）