#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>

const long long MaxN=100;
long long mapp[MaxN+2][MaxN+2],f[MaxN+2][MaxN+2];

long long main()
{
    long long t;
    std::cin>>t;
    while (t--) {
        memset (mapp,0,sizeof(mapp));
        long long n,m;
        std::cin>>n>>m;
        for (long long i=1;i<=n;i++) {
            for (long long j=1;j<=m;j++) {
                std::cin>>mapp[i][j];
            }
        }

        for (long long i=1;i<=n;i++) {
            for (long long j=1;j<=m;j++) {
                f[i][j]=std::max(f[i-1][j],f[i][j-1])+mapp[i][j];
            }
        }
        std::cout<<f[n][m]<<std::endl;
    }

    return 0;
}