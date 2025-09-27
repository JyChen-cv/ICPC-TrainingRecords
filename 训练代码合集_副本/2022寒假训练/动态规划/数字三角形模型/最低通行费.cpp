#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <cstring>

const long long MaxN=100;
long long mapp[MaxN+3][MaxN+3],f[MaxN+3][MaxN+3];

long long main()
{
    long long n;
    std::cin>>n;
    for (long long i=1;i<=n;i++) {
        for (long long j=1;j<=n;j++) {
            std::cin>>mapp[i][j];
        }
    }
    memset(f,0x3f,sizeof(f));
    f[0][1]=0;
    f[1][0]=0;
    for (long long i=1;i<=n;i++) {
        for (long long j=1;j<=n;j++) {
            f[i][j]=std::min(f[i-1][j],f[i][j-1])+mapp[i][j];
            // std::cout<<f[i][j]<<" ";
        }
        // std::cout<<std::endl;
    }

    std::cout<<f[n][n]<<std::endl;
    return 0;
}